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
#include "SceneCorridor1_2.h"
#include "GameHead.h"

//コンストラクタ
CSceneCorridor1_2::CSceneCorridor1_2()
{

}

//デストラクタ
CSceneCorridor1_2::~CSceneCorridor1_2()
{

}

//初期化メゾット
void CSceneCorridor1_2::InitScene()
{

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objb = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

	//敵オブジェクト作成
	CObjEnemy* objh = new CObjEnemy(0, 0);
	Objs::InsertObj(objh, OBJ_ENEMY, 10);

	//グラフィック読み込み
	Draw::LoadImage(L"二宮金次郎透過.png", 10, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);
}


//実行中メゾット
void CSceneCorridor1_2::Scene()
{

}
