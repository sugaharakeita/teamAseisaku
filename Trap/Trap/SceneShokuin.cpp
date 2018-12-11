#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneShokuin.h"
#include "Hero.h"
#include "GameHead.h"

CSceneShokuin::CSceneShokuin()
{

}

CSceneShokuin::~CSceneShokuin()
{

}

void CSceneShokuin::InitScene()
{
	Draw::LoadImage(L"メッセージウィンドウ.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"アイテム.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"廊下1-1.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"職員室.png", 8, TEX_SIZE_512);
	CObjShokuin* r2 = new CObjShokuin();
	Objs::InsertObj(r2, SPOT_SHOKUIN, 0);
	CObjHero* h = new CObjHero(0.0f, 0.0f);
	if(Rouka1L==1)
		CObjHero* h = new CObjHero(0.0f, 128.0f);
	else if (Rouka1CL == 1)
		CObjHero* h = new CObjHero(736.0f, 128.0f);
	Objs::InsertObj(h, OBJ_HERO, 2); 
	CObjExcla* x = new CObjExcla(HeroX + 8, HeroY + 8);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	CObjMessage* m1 = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m1, OBJ_MESSAGE, 3);
	CObjMenu* m2 = new CObjMenu(0.0f, 0.0f);
	Objs::InsertObj(m2, OBJ_MENU, 3);
	CObjShokuinDoor* d1 = new CObjShokuinDoor(0.0f, 0.0f);
	Objs::InsertObj(d1, SHOKUIN_DOOR, 1);
	CObjShokuinDoor* d2 = new CObjShokuinDoor(732.0f, 0.0f);
	Objs::InsertObj(d2, SHOKUIN_DOOR, 1);
	CObjHokenHako* b2 = new CObjHokenHako(0.0f, 534.0f);
	Objs::InsertObj(b2, OBJ_HAKO, 1);
	if (KouchouKey == 1)
	{
		CObjKouchouKey* k = new CObjKouchouKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k, KOUCHOU_KEY, 1);
	}
	if (HokenKey == 1)
	{
		CObjHokenKey* k2 = new CObjHokenKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k2, HOKEN_KEY, 1);
	}
	if (Hammer == 1)
	{
		CObjHammer* i = new CObjHammer(HeroX + 8, HeroY + 8);
		Objs::InsertObj(i, OBJ_HAMMER, 1);
	}

}

void CSceneShokuin::Scene()
{

}