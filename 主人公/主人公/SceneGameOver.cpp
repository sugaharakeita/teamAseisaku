//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

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