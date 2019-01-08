//STLデバッグ機能をOFFにする
#define _SECURE_SCL_ (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneLibrary.h"
#include "GameHead.h"

//コンストラクタ
CSceneLibrary::CSceneLibrary()
{

}

//デストラクタ
CSceneLibrary::~CSceneLibrary()
{

}

//初期化メソッド
void CSceneLibrary::InitScene()
{
	//グラフィック読み込み・主人公
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	//グラフィック読み込み・マップ
	Draw::LoadImage(L"図書室.png", 0, TEX_SIZE_512);

	//グラフィック読み込み・1階敵
	Draw::LoadImage(L"ぬいぐるみ透過.png", 2, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

	////Test用　敵オブジェクト作成
	//CObjEnemy2* obje = new CObjEnemy2(0, 0);
	//Objs::InsertObj(obje, OBJ_ENEMY, 10);

	//Mapオブジェクト作成
	CObjLibrary* objr = new CObjLibrary();
	Objs::InsertObj(objr, OBJ_ROOM, 9);
}

//実行中メソッド
void CSceneLibrary::Scene()
{

}