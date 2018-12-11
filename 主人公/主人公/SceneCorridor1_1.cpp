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
#include "SceneCorridor1_1.h"
#include "GameHead.h"

//コンストラクタ
CSceneCorridor1_1::CSceneCorridor1_1()
{

}

//デストラクタ
CSceneCorridor1_1::~CSceneCorridor1_1()
{

}

//初期化メゾット
void CSceneCorridor1_1::InitScene()
{

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Corridor1_1オブジェクト生成
	CObjCorridor1_1* objb = new CObjCorridor1_1();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_1, 9);


	//グラフィック読み込み
	Draw::LoadImage(L"主人公.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"廊下1-1.png", 9, TEX_SIZE_512);
}


//実行中メゾット
void CSceneCorridor1_1::Scene()
{

}
