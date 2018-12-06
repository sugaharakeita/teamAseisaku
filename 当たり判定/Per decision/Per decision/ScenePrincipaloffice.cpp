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
#include "ScenePrincipaloffice.h"
#include "GameHead.h"

//コンストラクタ
CScenePrincipaloffice::CScenePrincipaloffice()
{

}

//デストラクタ
CScenePrincipaloffice::~CScenePrincipaloffice()
{

}

//初期化メゾット
void CScenePrincipaloffice::InitScene()
{

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Principalofficeオブジェクト生成
	CObjPrincipaloffice* objb = new CObjPrincipaloffice();
	Objs::InsertObj(objb, OBJ_PRINCIPALOFFICE, 9);

	//敵オブジェクト作成
	CObjEnemy* objh = new CObjEnemy(0, 0);
	Objs::InsertObj(objh, OBJ_ENEMY, 10);

	//グラフィック読み込み
	Draw::LoadImage(L"二宮金次郎透過.png", 10, TEX_SIZE_512);


	//グラフィック読み込み
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"校長室完成版.png", 9, TEX_SIZE_512);

}


//実行中メゾット
void CScenePrincipaloffice::Scene()
{

}
