//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メゾット
void CSceneMain::InitScene()
{
			

	

	////主人公オブジェクト作成
	//CObjHero* obj = new CObjHero();
	//Objs::InsertObj(obj, OBJ_HERO, 10);

	////Staffroomオブジェクト生成
	//CObjStaffroom* objb = new CObjStaffroom();
	//Objs::InsertObj(objb, OBJ_STAFFROOM, 9);

	////Principalofficeオブジェクト生成
	//CObjPrincipaloffice* objc = new CObjPrincipaloffice();
	//Objs::InsertObj(objc, OBJ_PRINCIPALOFFICE, 9);
	//
	////Infirmaryオブジェクト生成
	//CObjInfirmary* objd = new CObjInfirmary();
	//Objs::InsertObj(objd, OBJ_INFIRMARY, 9);

	////Corridor1_1オブジェクト生成
	//CObjCorridor1_1* obje = new CObjCorridor1_1();
	//Objs::InsertObj(obje, OBJ_CORRIDOR1_1, 9);

	////Corridor1_2オブジェクト生成
	//CObjCorridor1_2* objf = new CObjCorridor1_2();
	//Objs::InsertObj(objf, OBJ_CORRIDOR1_2, 9);

	////Corridor1_3オブジェクト生成
	//CObjCorridor1_3* objg = new CObjCorridor1_3();
	//Objs::InsertObj(objg, OBJ_CORRIDOR1_3, 9);

	


	//グラフィック読み込み
	
	/*
	Draw::LoadImage(L"主人公.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"職員室完成版.png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"校長室完成版.png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"廊下1-1.png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"廊下1-3.png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"保健室修正版.png", 9, TEX_SIZE_512);*/

	
	

	

}


//実行中メゾット
void CSceneMain::Scene()
{

}
