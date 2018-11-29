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
	Draw::LoadImage(L"���b�Z�[�W�E�B���h�E.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�L��1-1.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�L��1-2.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"�L��1-3.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"�Z����.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"�E����.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"�ی����C����.png", 9, TEX_SIZE_512);
	CObjRouka1* r = new CObjRouka1();
	Objs::InsertObj(r, SPOT_ROUKA1, 0);
	CObjHero* h = new CObjHero(0.0f,0.0f);
	//�p�^�[���͂܂��܂�������
	if (room[0] == 1)
	{
		if (Rouka1CL == 1)
			CObjHero* h = new CObjHero(736.0f, HeroY);
		CObjKouchouDoor* d0 = new CObjKouchouDoor(756.0f, 16.0f);
		Objs::InsertObj(d0, KOUCHOU_DOOR, 1);
		CObjShokuinDoor* d1 = new CObjShokuinDoor(114.0f, 494.0f);
		Objs::InsertObj(d1, SHOKUIN_DOOR, 1);
		CObjHokenHako* b2 = new CObjHokenHako(384.0f, 432.0f);
		Objs::InsertObj(b2, OBJ_HAKO, 1);

	}
	else if (room[1] == 1)
	{
		if (Rouka1L == 1)
			CObjHero* h = new CObjHero(64.0f, HeroY);
		else if(Rouka1CR==1)
			CObjHero* h = new CObjHero(736.0f, HeroY);
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
		CObjKouchouHako* b = new CObjKouchouHako(416.0f, 432.0f);
		Objs::InsertObj(b, OBJ_HAKO, 1);
		
	}
	else if (room[3] == 1)
	{
		if (Rouka1CR == 1)
			CObjHero* h = new CObjHero(64.0f, HeroY);
		CObjHokenDoor* d3 = new CObjHokenDoor(210.0f, 16.0f);
		Objs::InsertObj(d3, HOKEN_DOOR, 1);
		
	}
	//�p�^�[���Ɋ֌W�Ȃ����܂�����
	Objs::InsertObj(h, OBJ_HERO, 2);
	CObjExcla* x = new CObjExcla(HeroX,HeroY);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	CObjMessage* m = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m, OBJ_MESSAGE, 3);
	if (KouchouKey == 1)
	{
		CObjKouchouKey* k = new CObjKouchouKey(HeroX, HeroY);
		Objs::InsertObj(k, KOUCHOU_KEY, 1);
	}
	if (HokenKey == 1)
	{
		CObjHokenKey* k2 = new CObjHokenKey(HeroX, HeroY);
		Objs::InsertObj(k2, HOKEN_KEY, 1);
	}

}

void CSceneRouka1::Scene()
{

}