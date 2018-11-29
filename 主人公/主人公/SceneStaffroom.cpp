//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneStaffroom.h"
#include "GameHead.h"

//コンストラクタ
CSceneStaffroom::CSceneStaffroom()
{

}

//デストラクタ
CSceneStaffroom::~CSceneStaffroom()
{

}

//初期化メゾット
void CSceneStaffroom::InitScene()
{

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Staffroomオブジェクト生成
	CObjStaffroom* objb = new CObjStaffroom();
	Objs::InsertObj(objb, OBJ_STAFFROOM, 9);


	//グラフィック読み込み
	Draw::LoadImage(L"主人公.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"職員室完成版.png", 9, TEX_SIZE_512);

}


//実行中メゾット
void CSceneStaffroom::Scene()
{

}
