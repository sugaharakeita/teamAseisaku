//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMap8.h"

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;


//イニシャライズ
void CObjMap8::Init()
{
	m_x1 = 0.0f;

	//廊下2-2当たり判定
	HitBoxs Hit[3] =
	{
		{ -42,    0,  175,  175, 0, },//ドアから左側の壁
		{ 335, -290,  465,  465, 1, },//ドアから右側の壁
		{ 0,  494,  800,  800, 2, },//家庭科室扉(後ろ側)右側の壁

	};

	for (int i = 0; i < 5; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}

}

//アクション
void CObjMap8::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();



	//700～800にいくと廊下3-3にいく
	if (hx >700 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 110;
			g_hero_y = hy;
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//0～100にいくと廊下3-1にいく
	if (hx < 100 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 690;
			g_hero_y = hy;
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}




}

//ドロー
void CObjMap8::Draw()
{
	/*
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 384.0f;
	src.m_bottom = 362.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	*/


}