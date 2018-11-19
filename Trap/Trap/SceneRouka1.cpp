#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

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
	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"˜L‰º1-1.png", 3, TEX_SIZE_512);
	CObjRouka1* r = new CObjRouka1();
	Objs::InsertObj(r, SPOT_ROUKA1, 0);
	CObjHero* h = new CObjHero(128.0f,320.0f);
	Objs::InsertObj(h, OBJ_HERO, 2);
	CObjExcla* m = new CObjExcla(128.0f, 320.0f);
	Objs::InsertObj(m, OBJ_EXCLAMATION, 3);
	CObjKouchouDoor* d0 = new CObjKouchouDoor(460.0f, 16.0f);
	Objs::InsertObj(d0, KOUCHOU_DOOR, 1);
	CObjShokuinDoor* d1 = new CObjShokuinDoor(75.0f,492.0f);
	Objs::InsertObj(d1, SHOKUIN_DOOR, 1);
	CObjShokuinDoor* d2 = new CObjShokuinDoor(912.0f, 492.0f);
	Objs::InsertObj(d2, SHOKUIN_DOOR, 1);
	CObjHokenDoor* d3 = new CObjHokenDoor(588.0f,16.0f);
	Objs::InsertObj(d3, HOKEN_DOOR, 1);
	CObjHokenHako* b = new CObjHokenHako(384.0f,432.0f);
	Objs::InsertObj(b, OBJ_HAKO, 1);
	
	Font::SetStrTex(L"1ŠK˜L‰º");
}

void CSceneRouka1::Scene()
{

}