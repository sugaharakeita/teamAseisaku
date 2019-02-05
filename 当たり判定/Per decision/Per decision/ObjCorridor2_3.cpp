#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor2_3.h"
#include "GameHead.h"

using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//イニシャライズ
void CObjCorridor2_3::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 800, 175, ELEMENT_FIELD, OBJ_CORRIDOR2_3, 9);

	//下壁
	Hits::SetHitBox(this, 144.0f, 500.0f, 495, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_3, 9);

	//下壁
	Hits::SetHitBox(this, 780.0f, 500.0f, 20, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_3, 9);

}

//アクション
void CObjCorridor2_3::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hx < 10.0f)
	{
		Hits::DeleteHitBox(this);
	}

	//左下の扉に行くと二階・教室に行く
	if (hy > 450 && hx < 200)
	{
		g_hero_x = 50;
		g_hero_y = 100;
		Scene::SetScene(new CSceneClassroom());
		return;
	}

	//右下の扉に行くと二階・教室に行く
	if (hy > 450 && hx > 600)
	{
		g_hero_x = 700;
		g_hero_y = 100;
		Scene::SetScene(new CSceneClassroom());
		return;
	}


}

//ドロー
void CObjCorridor2_3::Draw()
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