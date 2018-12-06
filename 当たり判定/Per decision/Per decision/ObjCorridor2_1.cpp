#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor2_1.h"
#include "GameHead.h"

using namespace GameL;



//イニシャライズ
void CObjCorridor2_1::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 70.0f, 107, 110, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//上壁
	Hits::SetHitBox(this, 157.0f, 70.0f, 690, 110, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 500.0f, 110, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//下壁
	Hits::SetHitBox(this, 157.0f, 500.0f, 295, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//下壁
	Hits::SetHitBox(this, 499.0f, 500.0f, 200, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

	//下壁
	Hits::SetHitBox(this, 750.0f, 500.0f, 50, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_1, 9);

}

//アクション
void CObjCorridor2_1::Action()
{

	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//画面端左に行くと廊下2-1へ移動
	if (hx + 64.0f > 800.0f)
	{
		Scene::SetScene(new CSceneCorridor2_2());
	}

}

//ドロー
void CObjCorridor2_1::Draw()
{
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

}