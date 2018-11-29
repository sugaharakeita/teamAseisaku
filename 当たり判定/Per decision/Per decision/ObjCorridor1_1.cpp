#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor1_1.h"
#include "GameHead.h"

using namespace GameL;



//イニシャライズ
void CObjCorridor1_1::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 70.0f, 352, 110, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//上ドア1
	//Hits::SetHitBox(this, 352.0f, 70.0f, 54, 110, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//上壁
	Hits::SetHitBox(this, 404.0f, 70.0f, 210, 110, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//上ドア2
	Hits::SetHitBox(this, 614.0f, 70.0f, 46, 110, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//上壁
	Hits::SetHitBox(this, 660.0f, 70.0f, 30, 110, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//上ドア3
	Hits::SetHitBox(this, 690.0f, 70.0f, 43, 110, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//上壁
	Hits::SetHitBox(this, 733.0f, 70.0f, 95, 110, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 500.0f, 56, 100, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//下ドア1
	//Hits::SetHitBox(this, 56.0f, 600.0f, 50, 1, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//下壁
	Hits::SetHitBox(this, 106.0f, 500.0f, 545, 100, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//下ドア2
	//Hits::SetHitBox(this, 645.0f, 600.0f, 50, 1, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

	//下壁
	Hits::SetHitBox(this, 699.0f, 500.0f, 100, 100, ELEMENT_CORRIDOR1_1, OBJ_CORRIDOR1_1, 9);

}

//アクション
void CObjCorridor1_1::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hx+64.0f > 800.0f)
	{
		Scene::SetScene(new CSceneCorridor1_2());
	}

	if (hy + 64.0f > 600.0f && 56.0f < hx < 106.0f)
	{
		Scene::SetScene(new CSceneStaffroom());
	}

	if (hy + 64.0f > 600.0f && 645.0f < hx < 695.0f)
	{
		Scene::SetScene(new CSceneStaffroom());
	}
	
	if (hy < 110.0f && 352.0f < hx < 406.0f)
	{
		Scene::SetScene(new CScenePrincipaloffice());
	}

}

//ドロー
void CObjCorridor1_1::Draw()
{
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

}