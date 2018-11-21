//STLデバッグ機能をOFFにする
#define _SECURE_SCL_ (0)
#define _HAS_ITERATOR_DEBUGGINGb (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
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

//初期化メソッド
void CSceneMain::InitScene()
{
	////外部データの読み込み(ステージ情報)
	//unique_ptr<wchar_t> p; //ステージ情報ポインター
	//int size;              //ステージ情報の大きさ
	//p = Save::ExternalDataOpen(L"hokensitu.csv", &size); //外部データ読み込み

	//int map[6][11];
	//int count = 1;
	//for (int i = 0; i < 6; i++)
	//{
	//	for (int j = 0; j < 11; j++)
	//	{
	//		int w = 0;
	//		swscanf_s(&p.get()[count], L"%d", &w);

	//		map[i][j] = w;

	//		if (w >= 10)
	//		{
	//			count += 1;
	//		}

	//		
	//		count += 2;
	//	}
	//}

	

	//グラフィック読み込み
	Draw::LoadImageW(L"HeroTouka.png", 1, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"二宮金次郎透過.png", 2, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室修正版.png", 5, TEX_SIZE_1024);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjHokensitu* objb = new CObjHokensitu();
	Objs::InsertObj(objb, OBJ_HOKENSITU, 8);

	//敵オブジェクト作成
	CObjEnemy* obje = new CObjEnemy(0,0);
	Objs::InsertObj(obje, OBJ_ENEMY, 9);
}

//実行中メソッド
void CSceneMain::Scene()
{
	
}