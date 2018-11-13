//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;


//位置情報X取得用
float CObjHero::GetX()
{
	return m_px;
}

//位置情報X取得用
float CObjHero::GetY()
{
	return m_py;
}


//イニシャライズ
void CObjHero::Init()
{
	m_px = 0.0f;	//位置
	m_py = 0.0f;
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;		//右向き0.0f 左向き1.0f

	m_ani_time = 0;		
	m_ani_frame = 1;		//静止フレームを初期にする

	m_speed_power = 0.5f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅
}

//アクション
void CObjHero::Action()
{
	//移動ベクトルの破棄
	m_vy = 0.0f;

	//キーの入力方向
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy = m_speed_power;
		m_vy = -2.0f;
	}
	
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += m_speed_power;
		m_vy = +2.0f;
	}


	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;	//キー入力が無い場合は静止フレームにする
		m_ani_time = 0;
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

	//摩擦
	m_vx += -(m_vx*0.098);

	//位置更新
	m_px += m_vx*1.0;
	m_py += m_vy*1.0;
}

//ドロー
void CObjHero::Draw()
{
	int AniData[4] =
	{
		1 , 0 , 2 , 0 ,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top    =  0.0f;
	src.m_left   =  0.0f + AniData[m_ani_frame] * 64;
	src.m_right  = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (		 64.0f * m_posture ) + m_px;
	dst.m_right  = ( 64   -  64.0f * m_posture ) + m_px;
	dst.m_bottom = 64.0f+m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

}

