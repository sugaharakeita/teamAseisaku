#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor2_2.h"
#include "GameHead.h"

using namespace GameL;



//イニシャライズ
void CObjCorridor2_2::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 140, 180, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//上壁
	Hits::SetHitBox(this, 140.0f, 0.0f, 1, 180, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//階段1

	//上壁
	Hits::SetHitBox(this, 331.0f, 0.0f, 16, 180, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//階段2
	Hits::SetHitBox(this, 347.0f, 50.0f, 200, 1, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//上壁
	Hits::SetHitBox(this, 536.0f, 0.0f, 264, 180, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 500.0f,800, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 500.0f, 800, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

}

//アクション
void CObjCorridor2_2::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	if (hx < 50.0f || hx + 64.0f > 770.0f || hy < 5.0f)
	{
		Hits::DeleteHitBox(this);
	}

	/*
	//画面端左に行くと廊下2-1へ移動
	if (hx < 0.0f)
	{
	Scene::SetScene(new CSceneCorridor2_1());
	}

	//画面端右に行くと廊下2-3へ移動
	if (hx + 64.0f > 800.0f)
	{
	Scene::SetScene(new CSceneCorridor2_3());
	}

	//画面端上に行くとクリア画面
	if (hy < 0.0f && Input::GetVKey(VK_RETURN) == true)
	{
	Scene::SetScene(new CSceneClear());
	}
	*/
}

//ドロー
void CObjCorridor2_2::Draw()
{
	/*
		//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//背景
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 380.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

	*/

}