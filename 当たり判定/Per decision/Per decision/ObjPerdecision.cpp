#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjPerdecision.h"
#include "GameHead.h"

using namespace GameL;


//内積関数　
//引数1，2 float ax, ay :Aベクトル
//引数3，4 float bx, by :Bベクトル
//戻り値 float :射影
//内容 AベクトルとBベクトルで内積を行い射影を求める
float CObjPerdecision::Dot(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * bx + ay * by;

	return t;
}

//外積関数
//引数1，2 float ax, ay :Aベクトル
//引数3，4 float bx, by :Bベクトル
//戻り値 float :射影
//内容 AベクトルとBベクトルで内積を行い射影を求める
float CObjPerdecision::Cross(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * bx - ay * by;

	return t;
}

//符号を求めるマクロ
#define SGN(x) 1 - ( x <= 0 ) - ( x < 0 )

//線と線の交差判定 
//引数 float 1, 2 a1x , a1y :軸ベクトルAの始点
//引数 float 3, 4 a2x , a2y :軸ベクトルAの終点
//引数 float 5, 6 b1x , b1y :ベクトルBの始点
//引数 float 7, 8 b2x , b2y :ベクトルBの終点
//引数 float 9, 10 out_px , out_py :交差するベクトルの交点位置
//戻り値 bool :true=交点有り  false=交点無し
//内容 : 引数のA・Bベクトルの交点を見つけ、out_pxとout_pyに返す
bool CObjPerdecision::LineCrossPoint(
	float a1x, float a1y, float a2x, float a2y,
	float b1x, float b1y, float b2x, float b2y,
	float * out_px, float * out_py
)
{
	//エラーコード
	*out_px = -99999.0f; *out_py = -99999.0f;

	//Aベクトル作成(a2←a1)
	float ax = a2x - a1x;	float ay = a2y - a1y;

	//Bベクトル作成(b2←b1)
	float bx = b2x - b1x;	float by = b2y - b1y;

	//Cベクトル作成(b1←a1)
	float cx = b1x - a1x;	float cy = b1y - a1y;

	//Dベクトル作成(b2←a1)
	float dx = b2x - a1x;	float dy = b2y - a1y;

	//A×Cの射影とA×Bの射影を求める
	float t1 = Cross(ax, ay, cx, cy);
	float t2 = Cross(ax, ay, dx, dy);

	//符号が同じ方向になっているかどうかをチェック
	if (SGN(t1) == SGN(t2))
		return false; //交点無し

	//射影を絶対値化
	t1 = abs(t1); t2 = abs(t2);

	//交点を求める
	float px = bx * (t1 / (t1 + t2)) + b1x;
	float py = by * (t1 / (t1 + t2)) + b1y;

	//APベクトル(p←a1)
	float apx = px - a1x; float apy = py - a1y;

	//BPベクトル(p←a2)
	float bpx = px - a2x; float bpy = py - a2y;

	//A・APの射影とA・BPの射影を求める
	float w1 = Dot(ax, ay, apx, apy);
	float w2 = Dot(ax, ay, bpx, bpy);

	//符号チェック
	if (SGN(w1) == SGN(w2))
		return false; //交点が外

	//交点を返す
	*out_px = px; *out_py = py;

	return true;

}


//主人公と壁の交差判定関数
bool CObjPerdecision::HeroPerdecisionCrossPoint(
	float x, float y, float vx, float vy,
	float * out_px, float * out_py, float * out_len
)
{
	bool pb = false; //交点確認用
	float len = 99999.0f; //交点との距離

	//ブロックの辺ベクトル　
	float edge[4][4] =
	{
		{ 0, 0, 64, 0 }, //→
		{ 64, 0, 64, 64 }, //↓
		{ 64, 64, 0, 64 },//←
		{ 0, 64, 0, 0 }, //↑
	};

	//m_mapの全要素のアクセス	
	//ブロックの4辺からの交点を探す
	for (int k = 0; k < 4; k++)
	{
		float px, py;
		bool b;
		float l = 0.0f;
		b = LineCrossPoint(x, y, x + vx, y + vy,
			64 + edge[k][0], 64 + edge[k][1], 64 + edge[k][2], 64 + edge[k][3],
			&px, &py);

		//交点チェック
		if (b == true)
		{
			//交点との距離を求める
			l = sqrt((px - x) * (px - x) + (py - y) * (py - y));

			//見つけた交点の中で最も近い距離が短いモノを探す
			if (len > l)
			{
				len = l;
				*out_px = px;
				*out_py = py;
				pb = true;
			}
		}

	}

	*out_len = len;
	return pb;
}


//PerdecisionHit関数
void CObjPerdecision::PerdecisionHit
(
	float * x, float * y, bool scroll_on,
	bool * up, bool * down, bool * left, bool * right,
	float * vx, float * vy, int * bt
)
{
	//衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//要素番号を座標に変更
	float bx = 64.0f;
	float by = 64.0f;


	//主人公とブロックの当たり判定
	if ((*x + 64.0f > bx) && (*x < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
	{

		//vectorの作成
		float rvx = *x - bx;
		float rvy = *y - by;

		//長さを求める
		float len = sqrt(rvx*rvx + rvy*rvy);

		//角度を求める
		float r = atan2(rvy, rvx);
		r = r*180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);
	}

}

