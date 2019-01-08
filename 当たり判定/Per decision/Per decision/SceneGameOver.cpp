//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneGameOver.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//初期化メソッド
void CSceneGameOver::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(0, L"怪しい空気.wav", BACK_MUSIC); 
	Audio::LoadAudio(1, L"システム49　決定音 .wav", SOUND_TYPE::EFFECT);


	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"げーむおーばー！！");
	Font::SetStrTex(L"(´＾3 ^`）m9");
	Font::SetStrTex(L"タイトルへ");

	//ゲームオーバーオブジェクトの作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}

//実行中メソッド
void CSceneGameOver::Scene()
{

}