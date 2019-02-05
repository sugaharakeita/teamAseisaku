#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "ObjCorridor1_1.h"
#include "GameHead.h"

using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//イニシャライズ
void CObjCorridor1_1::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 70.0f, 410, 110, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//上壁
	Hits::SetHitBox(this, 510.0f, 70.0f, 290, 110, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 500.0f, 115, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//下壁
	Hits::SetHitBox(this, 215.0f, 500.0f, 445, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//下壁
	Hits::SetHitBox(this, 755.0f, 500.0f, 40, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);


}

//アクション
void CObjCorridor1_1::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	if (hx + 64.0f > 787.0f)
	{
		Hits::DeleteHitBox(this);
		Hits::DeleteHitBox(this);
	}

	//画面左下に行くと職員室に移動1
	if (hy > 450.0f && hx < 250.0f)
	{
		Scene::SetScene(new CSceneStaffroom());
		g_hero_x = 20;
		g_hero_y = 70;
	}

	//画面右下に行くと職員室に移動2
	if (hy > 450.0f && hx > 550.0f)
	{
		Scene::SetScene(new CSceneStaffroom());
		g_hero_x = 730;
		g_hero_y = 70;
	}

	//画面上に行くと校長室に移動
	if (hy < 120.0f)
	{
		Scene::SetScene(new CScenePrincipaloffice());
		g_hero_x = 600;
		g_hero_y = 520;
	}


}

//ドロー
void CObjCorridor1_1::Draw()
{
	/*
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//背景
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1038.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	*/

}