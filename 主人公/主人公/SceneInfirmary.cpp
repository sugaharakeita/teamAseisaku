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
#include "SceneInfirmary.h"
#include "GameHead.h"

//コンストラクタ
CSceneInfirmary::CSceneInfirmary()
{

}

//デストラクタ
CSceneInfirmary::~CSceneInfirmary()
{

}

//初期化メゾット
void CSceneInfirmary::InitScene()
{

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Infirmaryオブジェクト生成
	CObjInfirmary* objb = new CObjInfirmary();
	Objs::InsertObj(objb, OBJ_INFIRMARY, 9);


	//グラフィック読み込み
	Draw::LoadImage(L"主人公.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"保健室修正版.png", 9, TEX_SIZE_512);

}


//実行中メゾット
void CSceneInfirmary::Scene()
{

}
