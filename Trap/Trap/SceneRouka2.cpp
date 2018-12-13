#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneRouka2.h"
#include "Hero.h"
#include "GameHead.h"

CSceneRouka2::CSceneRouka2()
{

}

CSceneRouka2::~CSceneRouka2()
{

}

void CSceneRouka2::InitScene()
{
	Draw::LoadImage(L"���b�Z�[�W�E�B���h�E.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�A�C�e��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�L��2�S�̐}.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"�ƒ�Ȏ�������", 11, TEX_SIZE_512);
	Draw::LoadImage(L"�ƒ�ȏ�����������.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"����������.png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"�}����������.png", 14, TEX_SIZE_512);
	CObjRouka2* r4 = new CObjRouka2();
	Objs::InsertObj(r4, SPOT_ROUKA2, 0);
	CObjHero* h = new CObjHero(0.0f, 0.0f);
	if (room[7] == 1)
	{
		
	}
	else if (room[8] == 1)
	{


	}
	else if (room[9] == 1)
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

void CSceneRouka2::Scene()
{

}