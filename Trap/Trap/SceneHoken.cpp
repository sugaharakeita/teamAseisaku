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
	Draw::LoadImage(L"メッセージウィンドウ.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"アイテム.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"廊下1-3.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"保健室.png", 9, TEX_SIZE_512);
	CObjHoken* r3 = new CObjHoken();
	Objs::InsertObj(r3, SPOT_HOKEN, 0);
	CObjHero* h = new CObjHero(72, 520);
	Objs::InsertObj(h, OBJ_HERO, 2);
	CObjExcla* x = new CObjExcla(HeroX + 8, HeroY + 8);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	CObjMessage* m1 = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m1, OBJ_MESSAGE, 3);
	CObjMenu* m2 = new CObjMenu(0.0f, 0.0f);
	Objs::InsertObj(m2, OBJ_MENU, 3);
	CObjHokenDoor* d3 = new CObjHokenDoor(78.0f, 580.0f);
	Objs::InsertObj(d3, HOKEN_DOOR, 1);
	CObjKouchouHako* b1 = new CObjKouchouHako(724.0f, 200.0f);
	Objs::InsertObj(b1, OBJ_HAKO, 1);
	if (KouchouKey == 1)
	{
		CObjKouchouKey* k = new CObjKouchouKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k, KOUCHOU_KEY, 1);
	}

}

void CSceneHoken::Scene()
{

}