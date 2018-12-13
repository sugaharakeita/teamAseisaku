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
#include "SceneClear.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//初期化メゾット
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"School");
	Font::SetStrTex(L"Enterキーでスタート");

	//音楽の読み込み
	Audio::LoadAudio(0, L"VEIL オープニング.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"システム49　決定音 .wav", SOUND_TYPE::EFFECT);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.6f); //ボリュームを0.6下げる
	Audio::Start(0);

	//タイトルオブジェクト生成
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);

}


//実行中メゾット
void CSceneTitle::Scene()
{

}
