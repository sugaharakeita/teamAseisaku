//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include <math.h>

#include "GameHead.h"
#include "ObjEnemy2.h"

//使用するネームスペース
using namespace GameL;

float g_enemy2_x = 150.0f;
float g_enemy2_y = 0.0f;

//位置情報X取得用
float CObjEnemy2::GetX()
{
	return m_px;
}

//位置情報X取得用
float CObjEnemy2::GetY()
{
	return m_py;
}


//コンストラクタ
CObjEnemy2::CObjEnemy2(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjEnemy2::Init()
{
	m_x = x;
	m_y = y;
	m_px = g_enemy2_x;
	m_py = g_enemy2_y;
	m_vx = 1.0f;
	m_vy = 0.0f;
	m_posture = 1.0f;

	m_ani_time = 0;
	m_ani_frame = 1;

	m_speed_power = 1.5f;
	m_ani_max_time = 4;


	//衝突状態確認用初期化
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;


	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 45, 60, ELEMENT_ENEMY, OBJ_ENEMY, 11);
}

//アクション
void CObjEnemy2::Action()
{
	m_vx = 0;
	m_vy = 0;

	//主人公の位置を取得
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float hx = hero->GetX();
	//float hy = hero->GetY() ;

	//主人公と追尾で角度を取る
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float x = obj->GetX() - m_px;
	float y = obj->GetY() - m_py;

	//敵の位置
	CObjEnemy2*obje = (CObjEnemy2*)Objs::GetObj(OBJ_ENEMY);
	float ex = obj->GetX() - m_px;
	float ey = obj->GetY() - m_py;

	//計算頻度を落とし、斜め移動を防ぐ
	static int   count = 0;
	static float br = 0.0f;
	count++;
	if (count > 30)
	{
		count = 0;
		int ar = atan2(y, x)*180.0f / 3.14;

		if (ar < 0)
		{
			ar = 360 + ar;
		}
		br = ar;
	}

	if (br >= 45 && br < 136)//上 45度以上　136度未満
	{

		m_vy += m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (br > 0 && br < 45 || br > 315) //右　0度以上かつ45度未満　315度以上
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (br > 225 && br < 316)//下　225度以上　316未満
	{
		m_vy -= m_speed_power;
		m_posture = 2.0f;
		m_ani_time += 1;
	}
	else if (br > 135 && br < 225)//左　135度以上　225度未満
	{
		m_vx -= m_speed_power;
		m_posture = 3.0f;
		m_ani_time += 1;
	}

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//敵がステージの当たり判定に当たった時の処理（全ステージ対応）
	if (hit->CheckElementHit(ELEMENT_FIELD) == true)
	{

		HIT_DATA** hit_data;
		hit_data = hit->SearchElementHit(ELEMENT_FIELD);

		float r = hit_data[0]->r;

		//角度で上下左右を判定
		if (r > 0 && r < 45 || r >= 315)
		{
			//右
			m_hit_right = true;
		}
		else if (r >= 45 && r < 136)
		{
			//上
			m_hit_up = true;
		}
		else if (r >= 135 && r <= 225)
		{
			//左
			m_hit_left = true;
		}
		else if (r > 225 && r < 316)
		{
			//下
			m_hit_down = true;
		}


		//左に当たり判定があった場合
		if (m_hit_left == true)
		{
			m_vx = m_vx + 2.0f;
		}

		//右に当たり判定があった場合
		if (m_hit_right == true)
		{
			m_vx = m_vx - 2.0f;
		}

		//下に当たり判定があった場合
		if (m_hit_down == true)
		{
			m_vy = m_vy - 2.0f;
		}

		//上に当たり判定があった場合
		if (m_hit_up == true)
		{
			m_vy = m_vy + 2.0f;
		}
	}




	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}



	//敵の現在向いている角度を取る
	//float br = atan2(-m_vy, m_vx)* 180.0f / 3.14f;

	//移動方向に-１°加える
	//m_vx =cos(ar*3.14 / 180);
	//m_vy =sin(ar*3.14 / 180);


	//位置更新
	m_px += m_vx*1.75;
	m_py += m_vy*1.75;

	//HitBoxの内容を更新
	hit->SetPos(m_px, m_py);
}
//ドロー
void CObjEnemy2::Draw()
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
		src.m_top = 205.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 40;
		src.m_right = 40.0f + AniData[m_ani_frame] * 40;
		src.m_bottom = 254.0f;


	}
	else if (m_posture == 0)//上から下
	{
		//切り取り位置の設定
		src.m_top = 13.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 40;
		src.m_right = 40.0f + AniData[m_ani_frame] * 40;
		src.m_bottom = 62.0f;


	}
	else if (m_posture == 1)//右向き
	{
		//切り取り位置の設定
		src.m_top = 136.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 40;
		src.m_right = 41.0f + AniData[m_ani_frame] * 40;
		src.m_bottom = 189.0f;



	}
	else if (m_posture == 3)//左向き
	{
		//切り取り位置の設定
		src.m_top = 76.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 40;
		src.m_right = 35.0f + AniData[m_ani_frame] * 40;
		src.m_bottom = 125.0f;

	}
	

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 40.0f + m_px;
	dst.m_bottom = 49.0f + m_py;

	//描画
	Draw::Draw(11, &src, &dst, c, 0.0f);

}