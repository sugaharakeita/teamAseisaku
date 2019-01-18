//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMap7.h"

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;
//
//extern float g_enemy_x = 150.0f;
//extern float g_enemy_y = 0.0f;
//


//イニシャライズ
void CObjMap7::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;


	//廊下2-1当たり判定
	HitBoxs Hit[5] =
	{
		{ 0,  -54,  229,  229, 0, },//ドアから左側の壁
		{ 335, -290,  465,  465, 1, },//ドアから右側の壁
		{ -449,  175,  465,  465, 2, },//一番左端
		{ 123,  495,  335,  335, 3, },//家庭科室扉(後ろ側)右側の壁
		{ 563,  495,  127,  127, 4, },//家庭科室扉(前側)右側の壁

	};

	for (int i = 0; i < 5; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//アクション
void CObjMap7::Action()
{
	
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
	


	////敵の位置
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();

	
	if (hx + 64.0f > 787.0f || hy > 440.0f || hy < 110.0f)
	{
		Hits::DeleteHitBox(this);
		Hits::DeleteHitBox(this);
	}
	

	//マップ端にいくと廊下3-2にいく
	if (hx >700 == true)
	{
		if (m_key_flag == true)
		{
			//主人公
			g_hero_x = 110;
			g_hero_y = hy;
			//敵
			//g_enemy_x = 110;
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//下に行くと二階・家庭科室に行く。
	if (hy > 450 == true)
	{
		if (hx < 350 == true)
		{
			if (m_key_flag == true)
			{
				g_hero_x = 650;
				g_hero_y = hy;
				m_key_flag = false;
			}
		}
	}
	else
	{
		m_key_flag = true;
	}

	//下に行くと二階・家庭準備室に行く。
	if (hy > 450 == true)
	{
		if (hx > 450 == true)
		{
			if (m_key_flag == true)
			{
				g_hero_x = 650;
				g_hero_y = hy;
				m_key_flag = false;
			}
		}
	}
	else
	{
		m_key_flag = true;
	}


	//上に行くと二階・図書室に行く
	if (hy < 100 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 650;
			g_hero_y = hy;
			//Scene::SetScene(new CSceneLibrary());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}




}

//ドロー
void CObjMap7::Draw()
{
	/*
		//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

				//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 1035.0f;
	src.m_bottom = 362.0f;

	////背景１の位置の設定をし描画
	//dst.m_top = 0.0f;
	//dst.m_left = 0.0f + m_x1;
	//dst.m_right = 1716.0f + m_x1;
	//dst.m_bottom = 600.0f;
	//Draw::Draw(0, &src, &dst, c, 0.0f);



	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//背景１の位置の設定をし描画
			dst.m_top = 0.0f;
			dst.m_left = 0.0f + m_scroll;
			dst.m_right = 1716.0f + m_scroll;
			dst.m_bottom = 600.0f;
			Draw::Draw(0, &src, &dst, c, 0.0f);

		}
	}

	*/

}