//STLデバッグ機能をOFFにする
#define _SECURE_SCL_ (0)
#define _HAS_ITERATOR_DEBUGGINGb (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain8.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain8::CSceneMain8()
{

}

//デストラクタ
CSceneMain8::~CSceneMain8()
{

}

//初期化メソッド
void CSceneMain8::InitScene()
{
	//グラフィック読み込み・主人公
	Draw::LoadImageW(L"HeroTouka.png", 1, TEX_SIZE_512);

	//グラフィック読み込み・マップ
	Draw::LoadImageW(L"廊下3-2.png", 0, TEX_SIZE_512);

	//グラフィック読み込み・1階敵
	Draw::LoadImageW(L"絵画.png", 2, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//Test用　敵オブジェクト作成
	CObjEnemy2* obje = new CObjEnemy2(0, 0);
	Objs::InsertObj(obje, OBJ_ENEMY, 10);

	//Mapオブジェクト作成
	CObjMap8* objm = new CObjMap8();
	Objs::InsertObj(objm, OBJ_MAP, 9);
}

//実行中メソッド
void CSceneMain8::Scene()
{

}