//STLデバッグ機能をOFFにする
#define _SECURE_SCL_ (0)
#define _HAS_ITERATOR_DEBUGGINGb (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneHomepreparationroom.h"
#include "GameHead.h"

//コンストラクタ
CSceneHomepreparationroom::CSceneHomepreparationroom()
{

}

//デストラクタ
CSceneHomepreparationroom::~CSceneHomepreparationroom()
{

}

//初期化メソッド
void CSceneHomepreparationroom::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(3, L"謀略の間.wav", BACK_MUSIC); //通常　室内

	Audio::LoadAudio(2, L"学校の廊下を歩く .wav", BACK_MUSIC); //主人公足音

	//ボリュームを0.8減らす
	float v = Audio::VolumeMaster(0.8);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(3);

	//グラフィック読み込み・主人公
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	//グラフィック読み込み・マップ
	Draw::LoadImage(L"家庭準備室.png", 9, TEX_SIZE_512);


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);


	//Mapオブジェクト作成
	CObjHomepreparationroom* objhp = new CObjHomepreparationroom();
	Objs::InsertObj(objhp, OBJ_ROOM, 9);
}

//実行中メソッド
void CSceneHomepreparationroom::Scene()
{

}