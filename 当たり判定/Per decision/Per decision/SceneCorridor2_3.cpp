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
#include "SceneCorridor2_3.h"
#include "GameHead.h"

//コンストラクタ
CSceneCorridor2_3::CSceneCorridor2_3()
{

}

//デストラクタ
CSceneCorridor2_3::~CSceneCorridor2_3()
{

}

//初期化メゾット
void CSceneCorridor2_3::InitScene()
{

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Corridor2_2オブジェクト生成
	CObjCorridor2_3* objb = new CObjCorridor2_3();
	Objs::InsertObj(objb, OBJ_CORRIDOR2_3, 9);


	//グラフィック読み込み
	Draw::LoadImage(L"主人公.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"廊下2-3.png", 9, TEX_SIZE_512);
}


//実行中メゾット
void CSceneCorridor2_3::Scene()
{

}
