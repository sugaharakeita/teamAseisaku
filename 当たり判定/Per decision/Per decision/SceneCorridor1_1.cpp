//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"

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
	//音楽読み込み
	Audio::LoadAudio(0, L"黒い足音.wav", BACK_MUSIC); //通常
	Audio::LoadAudio(1, L"死神の斧.wav", BACK_MUSIC); //Enemy出現

	Audio::LoadAudio(2, L"学校の廊下を歩く .wav", BACK_MUSIC); //主人公足音

	//ボリュームを0.8減らす
	float v = Audio::VolumeMaster(0.8);

	//音楽スタート
	Audio::Start(0);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Corridor1_1オブジェクト生成
	CObjCorridor1_1* objb = new CObjCorridor1_1();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_1, 9);
	
	//敵オブジェクト作成
	CObjEnemy* objh = new CObjEnemy(0, 0);
	Objs::InsertObj(objh, OBJ_ENEMY, 11);
	
	//グラフィック読み込み
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"廊下1-1.png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"二宮金次郎透過.png", 11, TEX_SIZE_512);
}



//実行中メゾット
void CSceneCorridor1_1::Scene()
{

}
