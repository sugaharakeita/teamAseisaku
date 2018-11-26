//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include <math.h>
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjEnemy.h"

//使用するネームスペース
using namespace GameL;

//位置情報X取得用
float CObjEnemy::GetX()
{
	return m_px;
}

//位置情報X取得用
float CObjEnemy::GetY()
{
	return m_py;
}


//コンストラクタ
CObjEnemy::CObjEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjEnemy::Init()
{
	m_x = x;
	m_y = y;
	m_px = 200.0f;		//位置
	m_py = 200.0f;
	m_vx = 1.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//静止フレームを初期にする

	m_ani_time = 0;
	m_ani_frame = 1;

	m_speed_power = 1.5f;

	//当たり判定
	Hits::SetHitBox(this, m_px, m_py,52, 96, ELEMENT_ENEMY, OBJ_ENEMY, 1);

}

//アクション
void CObjEnemy::Action()
{
	m_vx = 0;
	m_vy = 0;


	//主人公と追尾で角度を取る
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float x = obj->GetX() - m_px;
	float y = obj->GetY() - m_py;


	float ar = atan2(y, x)*180.0f / 3.14;

	if (ar < 0)
	{
		ar = 360 + ar;
	}

	if (ar >= 45 && ar < 136)//上 45度以上　136度未満
	{

		m_vy += m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (ar > 0 && ar < 45 || ar > 315) //右　0度以上かつ45度未満　315度以上
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (ar > 225 && ar < 316)//下　225度以上　316未満
	{
		m_vy -= m_speed_power;
		m_posture = 2.0f;
		m_ani_time += 1;
	}
	else if (ar > 135 && ar < 225)//左　135度以上　225度未満
	{
		m_vx -= m_speed_power;
		m_posture = 3.0f;
		m_ani_time += 1;
	}


	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//位置更新
	m_px += m_vx*1.75;
	m_py += m_vy*1.75;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);  //作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_px, m_py);               //入り口から新しい位置（敵の位置）情報に置き換える

}

//ドロー
void CObjEnemy::Draw()
{
	int AniData[4] =
	{
		1 , 0 , 2 , 0 ,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	if (m_posture == 2)//下から上
	{
		//切り取り位置の設定
		src.m_top    = 196.0f;
		src.m_left   = 12.0f + AniData[m_ani_frame] * 64;
		src.m_right  = 48.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 286.0f;


	}
	else if (m_posture == 0)//上から下
	{
		//切り取り位置の設定
		src.m_top	 = 4.0f;
		src.m_left	 = 12.0f + AniData[m_ani_frame] * 64;
		src.m_right  = 50.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 93.0f;


	}
	else if (m_posture == 1)//右向き
	{
		//切り取り位置の設定
		src.m_top    = 100.0f;
		src.m_left   = 8.0f + AniData[m_ani_frame] * 64;
		src.m_right  = 50.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 188.0f;



	}
	else if (m_posture == 3)//左向き
	{
		//切り取り位置の設定
		src.m_top    = 292.0f;
		src.m_left   = 15.0f + AniData[m_ani_frame] * 64;
		src.m_right  = 55.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 380.0f;

	}

	//表示位置の設定
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = 0.0f + m_px;
	dst.m_right  = 48.0f + m_px;
	dst.m_bottom = 96.0f + m_py;

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);

}