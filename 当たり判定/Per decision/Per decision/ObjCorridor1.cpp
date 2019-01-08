#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "ObjCorridor1.h"
#include "GameHead.h"

using namespace GameL;



//イニシャライズ
void CObjCorridor1::Init()
{

	//エリア移動フラグ初期化
	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;

}

//アクション
void CObjCorridor1::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	if (m_flag_Corridor1_1 == true)
	{
		//Corridor1_1オブジェクト生成
		CObjCorridor1_1* objb = new CObjCorridor1_1();
		Objs::InsertObj(objb, OBJ_CORRIDOR1_1, 9);

		Draw::LoadImage(L"廊下1-1.png", 9, TEX_SIZE_512);

		m_flag_Corridor1_2 = false;
		m_flag_Corridor1_3 = false;
	}

	if (m_flag_Corridor1_2 == true)
	{
		//Corridor1_2オブジェクト生成
		CObjCorridor1_2* objb = new CObjCorridor1_2();
		Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

		Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);

		m_flag_Corridor1_1 = false;
		m_flag_Corridor1_3 = false;
	}

	if (m_flag_Corridor1_3 == true)
	{
		//Corridor1_3オブジェクト生成
		CObjCorridor1_3* objb = new CObjCorridor1_3();
		Objs::InsertObj(objb, OBJ_CORRIDOR1_3, 9);

		Draw::LoadImage(L"廊下1-3.png", 9, TEX_SIZE_512);

		m_flag_Corridor1_1 = false;
		m_flag_Corridor1_2 = false;
	}

	/*
	//廊下1-1画面端右に行くと廊下1-2へ移動
	if (hx + 64.0f > 800.0f && m_flag_Corridor1_1 == true)
	{
	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objb = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

	Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);

	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = true;
	}

	//廊下1-2画面端左に行くと廊下1-1へ移動
	if (hx < 0.0f && m_flag_Corridor1_2 == true)
	{
	//Corridor1_1オブジェクト生成
	CObjCorridor1_1* objb = new CObjCorridor1_1();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_1, 9);

	Draw::LoadImage(L"廊下1-1.png", 9, TEX_SIZE_512);

	m_flag_Corridor1_1 = true;
	m_flag_Corridor1_2 = false;
	}

	//廊下1-2画面端右に行くと廊下1-3へ移動
	if (hx + 64.0f > 800.0f && m_flag_Corridor1_2 == true)
	{
	//Corridor1_3オブジェクト生成
	CObjCorridor1_3* objb = new CObjCorridor1_3();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_3, 9);

	Draw::LoadImage(L"廊下1-3.png", 9, TEX_SIZE_512);

	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = true;
	}

	//廊下1-3画面端左に行くと廊下1-2へ移動
	if (hx < 0.0f && m_flag_Corridor1_3 == true)
	{
	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objb = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

	Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);

	m_flag_Corridor1_3 = false;
	m_flag_Corridor1_2 = true;
	}
	*/


	/*
	//廊下1-1画面端下に行くと職員室に移動
	if ((hy + 64.0f > 600.0f && 56.0f < hx < 106.0f) ||
	(hy + 64.0f > 600.0f && 645.0f < hx < 695.0f))
	{
	Scene::SetScene(new CSceneStaffroom());
	}

	//廊下1-1画面端上に行くと校長室に移動
	if (hy < 110.0f && 352.0f < hx < 406.0f)
	{
	Scene::SetScene(new CScenePrincipaloffice());
	}

	//廊下1-2画面端上に行くと廊下2-2へ移動
	if (hy < 0.0f && Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneCorridor2_2());
	}

	//廊下1-3主人公のy座標yが175.0f以下になると保健室へ移動
	if (hy + 64.0f < 175.0f && 150.0f < hx < 280.0f)
	{
	Scene::SetScene(new CSceneInfirmary());
	}
	*/

}

//ドロー
void CObjCorridor1::Draw()
{


}