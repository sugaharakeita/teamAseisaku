//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjHomepreparationroom.h"
//#include "ObjHitBoxHPR.h"//家庭準備室

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;
//
//extern float g_enemy_x = 150.0f;
//extern float g_enemy_y = 0.0f;
//


//イニシャライズ
void CObjHomepreparationroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//家庭準備室当たり判定
	HitBoxs Hit[11] =
	{
		{   0, 	-22,   148,  148, 0, },//上、左壁
		{ 273,  -401,  527,  527, 1, },//上、右壁
		{ 723,   126,   66,   66, 2, },//流し台
		{ -56,   126,   75,   75, 3, },//左壁、上側
		{-305,   277,  323,  323, 4, },//左壁、下側
		{  18,   493,  620,  620, 5, },//下棚
		{ 718,   238,  438,  438, 6, },//右棚
		{ 221,   280,  120,  116, 7, },
		{ 341,   280,  120,  116, 8, },
		{ 461,   280,  116,  116, 9, },//7～9中央の机
		{ 638,   581,   80,   80,10, },
	};

	for (int i = 0; i <11; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}



}

//アクション
void CObjHomepreparationroom::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	////敵の位置
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();

	
	//上に行くと廊下2-1に行く
	if (hy > 50 == true && hy < 100 == true)
	{
		if (m_key_flag == true)
		{
			//主人公
			g_hero_x = hx;
			g_hero_y = 100;
			//敵
			//g_enemy_x = 110;

			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	

	//左に行くと二階・家庭科室に行く
	if (hx < 100 == true)
	{
		if (m_key_flag == true)
		{
			//主人公
			g_hero_x = 100;
			g_hero_y = hy;
			//敵
			//g_enemy_x = 110;

			Scene::SetScene(new CSceneHomeeconomicsroom());
			m_key_flag = false;
		}
	}

	

}

//ドロー
void CObjHomepreparationroom::Draw()
{
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

				//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 404.0f;
	src.m_bottom = 506.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);



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