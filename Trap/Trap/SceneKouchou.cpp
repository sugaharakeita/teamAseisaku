#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneKouchou.h"
#include "Hero.h"
#include "GameHead.h"

CSceneKouchou::CSceneKouchou()
{

}

CSceneKouchou::~CSceneKouchou()
{

}

void CSceneKouchou::InitScene()
{
	Draw::LoadImage(L"メッセージウィンドウ.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"アイテム全部.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"廊下1-1.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"校長室.png", 7, TEX_SIZE_512);
	CObjKouchou* r1 = new CObjKouchou();
	Objs::InsertObj(r1, SPOT_KOUCHOU, 0);
	CObjHero* h = new CObjHero(736, 520);
	Objs::InsertObj(h, OBJ_HERO, 2);
	CObjExcla* x = new CObjExcla(HeroX + 8, HeroY + 8);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	CObjTextALL* m = new CObjTextALL(0.0f, 0.0f);
	Objs::InsertObj(m, OBJ_TEXTURE, 3);
	CObjMessage* m1 = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m1, OBJ_MESSAGE, 3);
	CObjMenu* m2 = new CObjMenu(0.0f, 0.0f);
	Objs::InsertObj(m2, OBJ_MENU, 3);
	CObjKouchouDoor* d0 = new CObjKouchouDoor(580.0f, 586.0f);
	Objs::InsertObj(d0, KOUCHOU_DOOR, 1);
	if (Hammer == 0)
	{
		CObjHammer* i = new CObjHammer(188, 164);
		Objs::InsertObj(i, OBJ_HAMMER, 1);
	}
	else if (Hammer == 1 && Ham_flag == false)
	{
		CObjHammer* i = new CObjHammer(HeroX + 8, HeroY + 8);
		Objs::InsertObj(i, OBJ_HAMMER, 1);
	}
}

void CSceneKouchou::Scene()
{

}