#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "Hero.h"
#include "SceneRouka1.h"
#include "GameHead.h"

CSceneRouka1::CSceneRouka1()
{

}

CSceneRouka1::~CSceneRouka1()
{

}

void CSceneRouka1::InitScene()
{
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"î†.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"òLâ∫1-1.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"òLâ∫1-2.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"òLâ∫1-3.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"ï€åíé∫èCê≥î≈.png", 7, TEX_SIZE_512);
	CObjRouka1* r = new CObjRouka1();
	Objs::InsertObj(r, SPOT_ROUKA1, 0);
	CObjHero* h = new CObjHero(0.0f,0.0f);
	if (room[0] == 1)
	{
		CObjHero* h = new CObjHero(128.0f, 320.0f);
		CObjKouchouDoor* d0 = new CObjKouchouDoor(460.0f, 16.0f);
		Objs::InsertObj(d0, KOUCHOU_DOOR, 1);
		CObjShokuinDoor* d1 = new CObjShokuinDoor(75.0f, 494.0f);
		Objs::InsertObj(d1, SHOKUIN_DOOR, 1);
		CObjHokenHako* b2 = new CObjHokenHako(384.0f, 432.0f);
		Objs::InsertObj(b2, OBJ_HAKO, 1);

	}
	else if (room[1] == 1 && room[0] == 1)
	{
		CObjHero* h = new CObjHero(0.0f, 320.0f);
		
	}
	else if (room[1] == 1 && room[2] == 1)
	{
		CObjHero* h = new CObjHero(672.0f, 320.0f);
		CObjShokuinDoor* d2 = new CObjShokuinDoor(168.0f, 494.0f);
		Objs::InsertObj(d2, SHOKUIN_DOOR, 1);

	}
	else if (room[1] == 1 && Title == 1)
	{
		CObjHero* h = new CObjHero(368.0f, 400.0f);
		CObjKouchouHako* b = new CObjKouchouHako(384.0f, 432.0f);
		Objs::InsertObj(b, OBJ_HAKO, 1);

	}
	else if (room[2] == 1)
	{
		CObjHokenDoor* d3 = new CObjHokenDoor(588.0f, 16.0f);
		Objs::InsertObj(d3, HOKEN_DOOR, 1);

	}
	//ÉpÉ^Å[ÉìÇÕÇ‹ÇæÇ‹ÇæëùÇ¶ÇÈ
	Objs::InsertObj(h, OBJ_HERO, 2);
	CObjExcla* m = new CObjExcla(HeroX,HeroY);
	Objs::InsertObj(m, OBJ_EXCLAMATION, 3);
	
	Font::SetStrTex(L"1äKòLâ∫");
}

void CSceneRouka1::Scene()
{

}