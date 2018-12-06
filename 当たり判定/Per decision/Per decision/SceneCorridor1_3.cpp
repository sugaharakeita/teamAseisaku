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
#include "SceneCorridor1_3.h"
#include "GameHead.h"

//コンストラクタ
CSceneCorridor1_3::CSceneCorridor1_3()
{

}

//デストラクタ
CSceneCorridor1_3::~CSceneCorridor1_3()
{

}

//初期化メゾット
void CSceneCorridor1_3::InitScene()
{

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Corridor1_3オブジェクト生成
	CObjCorridor1_3* objb = new CObjCorridor1_3();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_3, 9);

	//敵オブジェクト作成
	CObjEnemy* objh = new CObjEnemy(0, 0);
	Objs::InsertObj(objh, OBJ_ENEMY, 10);

	//グラフィック読み込み
	Draw::LoadImage(L"二宮金次郎透過.png", 10, TEX_SIZE_512);


	//グラフィック読み込み
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"廊下1-3.png", 9, TEX_SIZE_512);
}


//実行中メゾット
void CSceneCorridor1_3::Scene()
{

}
