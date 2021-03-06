#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor1_3.h"
#include "GameHead.h"

using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//イニシャライズ
void CObjCorridor1_3::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 150, 175, ELEMENT_FIELD, OBJ_CORRIDOR1_3, 9);

	//上壁
	Hits::SetHitBox(this, 280.0f, 0.0f, 525, 175, ELEMENT_FIELD, OBJ_CORRIDOR1_3, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 500.0f, 800, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_3, 9);
	
}

//アクション
void CObjCorridor1_3::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hy < 122.0f)
	{
		Hits::DeleteHitBox(this);
	}

	//主人公のy座標yが175.0f以下になると保健室へ移動
	if (hy < 120.0f)
	{
		Scene::SetScene(new CSceneInfirmary());
		g_hero_x = 100;
		g_hero_y = 530;
	}

}

//ドロー
void CObjCorridor1_3::Draw()
{
	/*
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//背景
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 360.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	*/
	
}