#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneRouka1.h"
#include "Hero.h"
#include "GameHead.h"

CSceneRouka1::CSceneRouka1()
{

}

CSceneRouka1::~CSceneRouka1()
{

}

void CSceneRouka1::InitScene()
{
	Draw::LoadImage(L"メッセージウィンドウ.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"アイテム.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"廊下1-1.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"廊下1-2.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"廊下1-3.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"校長室.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"職員室.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"保健室.png", 9, TEX_SIZE_512);
	CObjRouka1* r0 = new CObjRouka1();
	Objs::InsertObj(r0, SPOT_ROUKA1, 0);
	CObjHero* h = new CObjHero(0.0f,0.0f);//ここで定義しておくことで、主人公を生み出す処理は一度で済む
	//パターンに応じて生成するもの
	if (room[0] == 1)
	{
		if (Rouka1CL == 1)
			CObjHero* h = new CObjHero(736.0f, HeroY);
		else if (Shokuin == 1)
			CObjHero* h = new CObjHero(42.0f, 416.0f);
		else if (Kouchou == 1)
			CObjHero* h = new CObjHero(736, 180.0f);
		CObjKouchouDoor* d0 = new CObjKouchouDoor(708.0f, 16.0f);
		Objs::InsertObj(d0, KOUCHOU_DOOR, 1);
		CObjShokuinDoor* d1 = new CObjShokuinDoor(114.0f, 494.0f);
		Objs::InsertObj(d1, SHOKUIN_DOOR, 1);
	}
	else if (room[1] == 1)
	{
		if (Rouka1L == 1)
			CObjHero* h = new CObjHero(64.0f, HeroY);
		else if(Rouka1CR==1)
			CObjHero* h = new CObjHero(736.0f, HeroY);
		else if (Shokuin == 1)
			CObjHero* h = new CObjHero(524.0f, 416.0f);
		CObjShokuinDoor* d2 = new CObjShokuinDoor(502.0f, 494.0f);
		Objs::InsertObj(d2, SHOKUIN_DOOR, 1);

	}
	else if (room[2] == 1)
	{
		if (Rouka1CL == 1)
			CObjHero* h = new CObjHero(64.0f, HeroY);
		else if (Rouka1R == 1)
			CObjHero* h = new CObjHero(736.0f,HeroY);
		else if (Title == 1)
			CObjHero* h = new CObjHero(248.0f, 536.0f);
		
	}
	else if (room[3] == 1)
	{
		if (Rouka1CR == 1)
			CObjHero* h = new CObjHero(64.0f, HeroY);
		else if (Hoken == 1)
			CObjHero* h = new CObjHero(212.0f, 180.0f);
		CObjHokenDoor* d3 = new CObjHokenDoor(212.0f, 16.0f);
		Objs::InsertObj(d3, HOKEN_DOOR, 1);
		
	}
	//パターンに関係なく生まれるもの
	Objs::InsertObj(h, OBJ_HERO, 2);
	CObjExcla* x = new CObjExcla(HeroX+8,HeroY+8);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	CObjTextALL* m = new CObjTextALL(0.0f, 0.0f);
	Objs::InsertObj(m, OBJ_TEXTURE, 3);
	CObjMessage* m1 = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m1, OBJ_MESSAGE, 3);
	CObjMenu* m2 = new CObjMenu(0.0f, 0.0f);
	Objs::InsertObj(m2, OBJ_MENU, 3);
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

void CSceneRouka1::Scene()
{

}