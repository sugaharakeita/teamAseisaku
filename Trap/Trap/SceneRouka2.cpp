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
	//�\������摜�̓ǂݎ��
	Draw::LoadImage(L"���b�Z�[�W�E�B���h�E.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�A�C�e���S��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�L��2�S�̐}.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"�ƒ�Ȏ�������", 11, TEX_SIZE_512);
	Draw::LoadImage(L"�ƒ�ȏ�����������.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"����������.png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"�}����������.png", 14, TEX_SIZE_512);
	//�Q�K�L���I�u�W�F�N�g�̍쐬
	CObjRouka2* r4 = new CObjRouka2();
	Objs::InsertObj(r4, SPOT_ROUKA2, 0);
	//��l���I�u�W�F�N�g�̍쐬
	CObjHero* h = new CObjHero(0.0f, 0.0f);
	if (room[7] == 1)//�Q�K�L�������ɋ���ꍇ
	{
		if (Rouka2C == 1)//�Q�K�L������������ڂ����ꍇ
			CObjHero* h = new CObjHero(736.0f, 128.0f);
		else if (Kateika == 1)//�ƒ�Ȏ�����ڂ����ꍇ
			CObjHero* h = new CObjHero(0.0f, 128.0f);
		else if (Tosho == 1)//�}��������ڂ����ꍇ
			CObjHero* h = new CObjHero(0.0f, 536.0f);
		//�ƒ�Ȏ��̔��I�u�W�F�N�g�̍쐬
		CObjKateikaDoor* d4 = new CObjKateikaDoor(0.0f,0.0f);
		Objs::InsertObj(d4, KATEIKA_DOOR, 0);
		CObjKateikaDoor* d4 = new CObjKateikaDoor(0.0f, 0.0f);
		Objs::InsertObj(d4, KATEIKA_DOOR, 0);
		//�}�����̔��I�u�W�F�N�g�̍쐬
		CObjToshoDoor* d7 = new CObjToshoDoor(0.0f, 0.0f);
		Objs::InsertObj(d7, TOSHO_DOOR, 0);


	}
	else if (room[8] == 1)//�Q�K�L�������ɋ���ꍇ
	{
		if (Rouka2L == 1)//�Q�K�L����������ڂ����ꍇ
			CObjHero* h = new CObjHero(0.0f, 128.0f);
		else if (Rouka2R == 1)//�Q�K�L���E������ڂ����ꍇ
			CObjHero* h = new CObjHero(736.0f, 128.0f);
		else if (Kyoushitu == 1)//��������ڂ����ꍇ
			CObjHero* h = new CObjHero(736.0f, 536.0f);
		if (Rouka1CR == 1)//�P�K�L�������E������ڂ����ꍇ�B�Q�K�̃X�^�[�g�ʒu
			CObjHero* h = new CObjHero(736.0f, 128.0f);
		//�ƒ�ȏ������̔��I�u�W�F�N�g�̍쐬
		CObjKateikaJunbiDoor* d5 = new CObjKateikaJunbiDoor(0.0f, 0.0f);
		Objs::InsertObj(d5, KATEIKAJUNBI_DOOR, 0);
		//�����̔��I�u�W�F�N�g�̍쐬
		CObjKyoushituDoor* d6 = new CObjKyoushituDoor(0.0f, 0.0f);
		Objs::InsertObj(d6, KYOUSHITU_DOOR, 0);


	}
	else if (room[9] == 1)//�Q�K�L���E���ɋ���ꍇ
	{
		if (Rouka2C == 1)//�Q�K�L������������ڂ����ꍇ
			CObjHero* h = new CObjHero(0.0f, 128.0f);
		else if (Kyoushitu == 1)//��������ڂ����ꍇ
			CObjHero* h = new CObjHero(736.0f, 536.0f);
		//�����̔��I�u�W�F�N�g�̍쐬
		CObjKyoushituDoor* d6 = new CObjKyoushituDoor(0.0f, 0.0f);
		Objs::InsertObj(d6, KYOUSHITU_DOOR, 0);


	}
	Objs::InsertObj(h, OBJ_HERO, 2);
	//�����I�u�W�F�N�g�̍쐬
	CObjExcla* x = new CObjExcla(HeroX + 8, HeroY + 8);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	//�e�L�X�g�\���p�I�u�W�F�N�g�̍쐬
	CObjTextALL* m = new CObjTextALL(0.0f, 0.0f);
	Objs::InsertObj(m, OBJ_TEXTURE, 3);
	//���b�Z�[�W�\���p�I�u�W�F�N�g�̍쐬
	CObjMessage* m1 = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m1, OBJ_MESSAGE, 3);
	//���j���[�\���p�I�u�W�F�N�g�̍쐬
	CObjMenu* m2 = new CObjMenu(0.0f, 0.0f);
	Objs::InsertObj(m2, OBJ_MENU, 3);
	//�����󋵂ɉ����Đ����������


}

void CSceneRouka2::Scene()
{

}