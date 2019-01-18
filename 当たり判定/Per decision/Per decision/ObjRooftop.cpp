//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjRooftop.h"
//#include "ObjHitBoxHER.h"//家庭科室

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;
//
//extern float g_enemy_x = 150.0f;
//extern float g_enemy_y = 0.0f;
//


//イニシャライズ
void CObjRooftop::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//家庭科室当たり判定
	HitBoxs Hit[17] =
	{
		{ -58, 	0,	128,  128, 0, },//左壁
		{ 130,  -413,  541,  541, 1, },//真ん中壁
		{ 731,     0,  128,  128, 2, },//右壁
		{ 0,   584,  400,  400, 3, },//下
		{ 400,   584,  400,  400, 4, },//下
		{ -399,   146,  438,  438, 5, },//左棚
		{ 170,   190,  140,  140, 6, },//上、左の机
		{ 370,   190,  120,  120, 7, },//上、真ん中の机
		{ 550,   190,  120,  120, 8, },//上、右の机
		{ 170,   410,  125,  125, 9, },//下、左の机
		{ 367,   410,  125,  125, 10, },//下、真ん中の机
		{ 545,   410,  120,  120, 11, },//下、右の机
		{ 715,   300,   33,   33, 12, },
		{ 715,   333,   33,   33, 13, },
		{ 715,   366,   33,   33, 14, },
		{ 715,   399,   33,   33, 15, },
		{ 715,   432,   33,   33, 16, },//11～16まで教卓


	};

	for (int i = 0; i <17; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//アクション
void CObjRooftop::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	////敵の位置
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();

	/*
	//上に行くと廊下2-1に行く
	if (hy > 50 == true && hy < 100 == true)
	{
	if (m_key_flag == true)
	{
	//主人公
	g_hero_x = hx;
	g_hero_y = 110;
	//敵
	//g_enemy_x = 110;

	m_key_flag = false;
	}
	}
	else
	{
	m_key_flag = true;
	}

	*/



}

//ドロー
void CObjRooftop::Draw()
{
	/*
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 852.0f;
	src.m_bottom = 506.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	*/



	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		//背景１の位置の設定をし描画
	//		dst.m_top = 0.0f;
	//		dst.m_left = 0.0f + m_scroll;
	//		dst.m_right = 1716.0f + m_scroll;
	//		dst.m_bottom = 600.0f;
	//		Draw::Draw(0, &src, &dst, c, 0.0f);

	//	}
	//}

}