//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "ScenePrologue.h"
#include "GameHead.h"

//コンストラクタ
CScenePrologue::CScenePrologue()
{

}

//デストラクタ
CScenePrologue::~CScenePrologue()
{

}

//初期化メソッド
void CScenePrologue::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"あらすじ");
	Font::SetStrTex(L"主人公は忘れ物を取りに学校へ訪れた。");
	Font::SetStrTex(L"そこで、主人公は様々な怪異に出会う・・・");
	Font::SetStrTex(L"怪異の目を掻い潜りながら屋上を目指し、脱出しよう☆");
	Font::SetStrTex(L"屋上を目指し、脱出しよう☆");
	Font::SetStrTex(L"EnterでLet's go!!");

	//ゲームオーバーオブジェクトの作成
	CObjPrologue* objp = new CObjPrologue();
	Objs::InsertObj(objp, OBJ_PROLOGUE, 10);
}

//実行中メソッド
void CScenePrologue::Scene()
{

}