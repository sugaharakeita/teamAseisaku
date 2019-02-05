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
	//音楽読み込み
	Audio::LoadAudio(3, L"謀略の間.wav", BACK_MUSIC); //通常　室内

	Audio::LoadAudio(2, L"学校の廊下を歩く .wav", BACK_MUSIC); //主人公足音

	float v = Audio::VolumeMaster(3);

	
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(3);


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Principalofficeオブジェクト生成
	CObjPrincipaloffice* objb = new CObjPrincipaloffice();
	Objs::InsertObj(objb, OBJ_PRINCIPALOFFICE, 9);
	

	//グラフィック読み込み
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"校長室.PNG", 9, TEX_SIZE_512);

}


//実行中メゾット
void CScenePrincipaloffice::Scene()
{

}
