#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneHoken.h"
#include "Hero.h"
#include "GameHead.h"

CSceneHoken::CSceneHoken()
{

}

CSceneHoken::~CSceneHoken()
{

}

void CSceneHoken::InitScene()
{
	//表示する画像の読み取り
	Draw::LoadImage(L"メッセージウィンドウ.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"アイテム全部.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"廊下1-3.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"保健室.png", 9, TEX_SIZE_512);
	//保健室オブジェクトの作成
	CObjHoken* r3 = new CObjHoken();
	Objs::InsertObj(r3, SPOT_HOKEN, 0);
	//主人公オブジェクトの作成
	CObjHero* h = new CObjHero(72, 520);
	Objs::InsertObj(h, OBJ_HERO, 2);
	//発見オブジェクトの作成
	CObjExcla* x = new CObjExcla(HeroX + 8, HeroY + 8);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	//テキスト表示用オブジェクトの作成
	CObjTextALL* m = new CObjTextALL(0.0f, 0.0f);
	Objs::InsertObj(m, OBJ_TEXTURE, 3);
	//メッセージ表示用オブジェクトの作成
	CObjMessage* m1 = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m1, OBJ_MESSAGE, 3);
	//メニュー表示用オブジェクトの作成
	CObjMenu* m2 = new CObjMenu(0.0f, 0.0f);
	Objs::InsertObj(m2, OBJ_MENU, 3);
	//保健室の扉オブジェクトの作成
	CObjHokenDoor* d3 = new CObjHokenDoor(78.0f, 580.0f);
	Objs::InsertObj(d3, HOKEN_DOOR, 1);
	//校長室のカギ入り箱オブジェクトの作成
	CObjKouchouHako* b1 = new CObjKouchouHako(724.0f, 14.0f);
	Objs::InsertObj(b1, OBJ_HAKO, 1);
	//所持状況に応じて生成するもの
	if (KouchouKey == 1 && Kou_flag == false)
	{
		//校長室のカギオブジェクトの所持
		CObjKouchouKey* k = new CObjKouchouKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k, KOUCHOU_KEY, 1);
	}
	if (Hammer == 1 && Ham_flag == false)
	{
		//ハンマーオブジェクトの所持
		CObjHammer* i = new CObjHammer(HeroX + 8, HeroY + 8);
		Objs::InsertObj(i, OBJ_HAMMER, 1);
	}
}

void CSceneHoken::Scene()
{

}