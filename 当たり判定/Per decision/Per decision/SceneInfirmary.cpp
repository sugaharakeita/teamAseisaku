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
	//音楽読み込み
	Audio::LoadAudio(3, L"謀略の間.wav", BACK_MUSIC); //通常　室内

	Audio::LoadAudio(2, L"学校の廊下を歩く .wav", BACK_MUSIC); //主人公足音

	//ボリュームを0.8減らす
	float v = Audio::VolumeMaster(0.8);
	v = Audio::VolumeMaster((1.0 - v));


	//音楽スタート
	Audio::Start(3);


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Infirmaryオブジェクト生成
	CObjInfirmary* objb = new CObjInfirmary();
	Objs::InsertObj(objb, OBJ_INFIRMARY, 9);
		

	//グラフィック読み込み
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"保健室.PNG", 9, TEX_SIZE_512);

}


//実行中メゾット
void CSceneInfirmary::Scene()
{

}
