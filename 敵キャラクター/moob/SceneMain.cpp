//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

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

//初期化メソッド
void CSceneMain::InitScene()
{
	//グラフィック読み込み
	//Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"二宮金次郎・赤ver.png", 1, TEX_SIZE_512);

	//主人公オブジェクト
	CObjHero*obj = new CObjHero;
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Mapオブジェクト
	CObjMap*objb = new CObjMap();
	Objs::InsertObj(objb, OBJ_MAP, 9);

	//test用　敵オブジェクト作成
	CObjEnemy*obje = new CObjEnemy(0,0);
	Objs::InsertObj(obje, OBJ_ENEMY, 10);
}

//実行中メソッド
void CSceneMain::Scene()
{

}