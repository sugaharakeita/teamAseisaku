#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneKateika.h"
#include "Hero.h"
#include "GameHead.h"

CSceneKateika::CSceneKateika()
{

}

CSceneKateika::~CSceneKateika()
{

}

void CSceneKateika::InitScene()
{
	Draw::LoadImage(L"メッセージウィンドウ.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"アイテム全部.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"廊下2全体図.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"教室完成版.png", 13, TEX_SIZE_512);
	CObjKateika* r5 = new CObjKateika();
	Objs::InsertObj(r5, SPOT_KATEIKA, 0);
	CObjHero* h = new CObjHero(0.0f, 0.0f);
	if (room[7] == 1)
	{

	}
	else if (room[10] == 1)
	{


	}
	Objs::InsertObj(h, OBJ_HERO, 2);
	CObjExcla* x = new CObjExcla(HeroX + 8, HeroY + 8);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	CObjTextALL* m = new CObjTextALL(0.0f, 0.0f);
	Objs::InsertObj(m, OBJ_TEXTURE, 3);
	CObjMessage* m1 = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m1, OBJ_MESSAGE, 3);
	CObjMenu* m2 = new CObjMenu(0.0f, 0.0f);
	Objs::InsertObj(m2, OBJ_MENU, 3);


}

void CSceneKateika::Scene()
{

}