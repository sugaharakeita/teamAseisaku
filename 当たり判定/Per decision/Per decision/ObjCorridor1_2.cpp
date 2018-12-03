#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor1_2.h"
#include "GameHead.h"

using namespace GameL;



//イニシャライズ
void CObjCorridor1_2::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 140, 180, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//上壁
	Hits::SetHitBox(this, 140.0f, 0.0f, 1, 180, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//階段
	//Hits::SetHitBox(this, 130.0f, 0.0f, 200, 1, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);
	
	//上壁
	Hits::SetHitBox(this, 331.0f, 0.0f, 1, 180, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);
	
	//ダンボール
	Hits::SetHitBox(this, 333.0f, 0.0f, 204, 150, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//上壁
	Hits::SetHitBox(this, 537.0f, 0.0f, 280, 180, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 500.0f, 200, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//出入り口1
	Hits::SetHitBox(this, 200.0f, 600.0f, 155, 1, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);
	
	//下壁
	Hits::SetHitBox(this, 355.0f, 500.0f, 130, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//出入り口2
	Hits::SetHitBox(this, 485.0f, 600.0f, 125, 1, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//下壁
	Hits::SetHitBox(this, 610.0f, 500.0f, 200, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

}

//アクション
void CObjCorridor1_2::Action()
{

	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//画面端左に行くと廊下1-1へ移動
	if (hx < 0.0f)
	{
		Scene::SetScene(new CSceneCorridor1_1());
	}

	//画面端右に行くと廊下1-3へ移動
	if (hx+64.0f > 800.0f)
	{
		Scene::SetScene(new CSceneCorridor1_3());
	}

	//画面端上に行くと廊下2-2へ移動
	if (hy < 0.0f)
	{
		Scene::SetScene(new CSceneCorridor2_2());
	}

}

//ドロー
void CObjCorridor1_2::Draw()
{
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

}