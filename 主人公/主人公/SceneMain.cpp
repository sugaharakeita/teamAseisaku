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
	//外部データの読み込み(ステージ情報)
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;              //ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"hokensitu.csv", &size); //外部データ読み込み

	int map[10][100];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//グラフィック読み込み
	Draw::LoadImageW(L"rouka.png", 0, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"HeroTouka.png", 1, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"二宮金次郎透過.png", 2, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室・床.png", 5, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室・先生机.png", 6, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室・椅子.png", 7, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室・カーテン.png", 8, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室・ベッド.png", 9, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室・机.png", 10, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室・ソファ.png", 11, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室・道具(体重計).png", 12, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"保健室・道具(身長計).png", 13, TEX_SIZE_512);

	
	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//敵オブジェクト作成
	CObjEnemy* obje = new CObjEnemy(0,0);
	Objs::InsertObj(obje, OBJ_ENEMY, 10);
}

//実行中メソッド
void CSceneMain::Scene()
{
	
}