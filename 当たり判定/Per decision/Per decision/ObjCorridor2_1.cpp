#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor2_1.h"
#include "GameHead.h"

using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//イニシャライズ
void CObjCorridor2_1::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 70.0f, 210, 110, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//上壁
	Hits::SetHitBox(this, 310.0f, 70.0f, 490, 110, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 500.0f, 15, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//下壁
	Hits::SetHitBox(this, 115.0f, 500.0f, 310, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//下壁
	Hits::SetHitBox(this, 525.0f, 500.0f, 120, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//下壁
	Hits::SetHitBox(this, 740.0f, 500.0f, 60, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

}

//アクション
void CObjCorridor2_1::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//上に行くと二階・図書室に行く
	if (hy < 120.0f)
	{
		Scene::SetScene(new CSceneLibrary());
		g_hero_x = 130;
		g_hero_y = 520;
	}

	//下に行くと二階・家庭科室に行く(左側のドア)。
	if (hy > 450.0f && hx < 74.0f)
	{
		Scene::SetScene(new CSceneHomeeconomicsroom());
		g_hero_x = 70;
		g_hero_y = 100;
	}

	//下に行くと二階・家庭科室に行く(右側のドア)。
	if (hy > 450.0f &&  hx < 550.0f)
	{
		Scene::SetScene(new CSceneHomeeconomicsroom());
		g_hero_x = 660;
		g_hero_y = 100;
	}

	//下に行くと二階・家庭準備室に行く。
	if (hy > 450.0f &&  hx > 600.0f)
	{
		Scene::SetScene(new CSceneHomepreparationroom());
		g_hero_x = 150;
		g_hero_y = 100;
		return;
	}

}

//ドロー
void CObjCorridor2_1::Draw()
{
	/*
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//背景
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1030.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	*/

}