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
	//�\������摜�̓ǂݎ��
	Draw::LoadImage(L"���b�Z�[�W�E�B���h�E.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�A�C�e���S��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�L��1-1.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�L��1-2.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"�L��1-3.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"�Z����.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"�E����.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"�ی���.png", 9, TEX_SIZE_512);
	//�P�K�L���I�u�W�F�N�g�̍쐬
	CObjRouka1* r0 = new CObjRouka1();
	Objs::InsertObj(r0, SPOT_ROUKA1, 0);
	//��l���I�u�W�F�N�g�̍쐬
	CObjHero* h = new CObjHero(0.0f,0.0f);//�����Œ�`���Ă������ƂŁA��l���𐶂ݏo�������͈�x�ōς�
	//�����ɉ����Đ����������
	if (room[0] == 1)//�P�K�L�������ɋ���ꍇ
	{
		if (Rouka1CL == 1)//�P�K�L��������������ڂ����ꍇ
			CObjHero* h = new CObjHero(736.0f, HeroY);
		else if (Shokuin == 1)//�E��������ڂ����ꍇ
			CObjHero* h = new CObjHero(42.0f, 416.0f);
		else if (Kouchou == 1)//�Z��������ڂ����ꍇ
			CObjHero* h = new CObjHero(736, 180.0f);
		//�Z�����̔��I�u�W�F�N�g�̍쐬
		CObjKouchouDoor* d0 = new CObjKouchouDoor(708.0f, 16.0f);
		Objs::InsertObj(d0, KOUCHOU_DOOR, 1);
		//�E�����̔��I�u�W�F�N�g�̍쐬
		CObjShokuinDoor* d1 = new CObjShokuinDoor(114.0f, 494.0f);
		Objs::InsertObj(d1, SHOKUIN_DOOR, 1);
	}
	else if (room[1] == 1)//�P�K�L�����������ɋ���ꍇ
	{
		if (Rouka1L == 1)//�P�K�L����������ڂ����ꍇ
			CObjHero* h = new CObjHero(64.0f, HeroY);
		else if(Rouka1CR==1)//�P�K�L�������E������ڂ����ꍇ
			CObjHero* h = new CObjHero(736.0f, HeroY);
		else if (Shokuin == 1)//�E��������ڂ����ꍇ
			CObjHero* h = new CObjHero(524.0f, 416.0f);
		//�E�����̔��I�u�W�F�N�g�̍쐬
		CObjShokuinDoor* d2 = new CObjShokuinDoor(502.0f, 494.0f);
		Objs::InsertObj(d2, SHOKUIN_DOOR, 1);

	}
	else if (room[2] == 1)//�P�K�L�������E���ɋ���ꍇ
	{
		if (Rouka1CL == 1)//�P�K�L��������������ڂ����ꍇ
			CObjHero* h = new CObjHero(64.0f, HeroY);
		else if (Rouka1R == 1)//�P�K�L���E������ڂ����ꍇ
			CObjHero* h = new CObjHero(736.0f,HeroY);
		else if (Rouka2C == 1)//�Q�K�L����������ڂ����ꍇ
			CObjHero* h = new CObjHero(216.0f, 128.0f);
		else if (Title == 1)//�^�C�g������ڂ����ꍇ�B�P�K�̃X�^�[�g�ʒu
			CObjHero* h = new CObjHero(248.0f, 536.0f);
		
	}
	else if (room[3] == 1)//�P�K�L���E���ɋ���ꍇ
	{
		if (Rouka1CR == 1)//�P�K�L�������E������ڂ����ꍇ
			CObjHero* h = new CObjHero(64.0f, HeroY);
		else if (Hoken == 1)//�ی�������ڂ����ꍇ
			CObjHero* h = new CObjHero(212.0f, 180.0f);
		//�ی����̔��I�u�W�F�N�g�̍쐬
		CObjHokenDoor* d3 = new CObjHokenDoor(212.0f, 16.0f);
		Objs::InsertObj(d3, HOKEN_DOOR, 1);
		
	}
	//�����Ɋ֌W�Ȃ������������
	Objs::InsertObj(h, OBJ_HERO, 2);
	//�����I�u�W�F�N�g�̍쐬
	CObjExcla* x = new CObjExcla(HeroX+8,HeroY+8);
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
	if (KouchouKey == 1 && Kou_flag == false)
	{
		//�Z�����̃J�M�I�u�W�F�N�g�̏���
		CObjKouchouKey* k = new CObjKouchouKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k, KOUCHOU_KEY, 1);
	}
	if (HokenKey == 1 && Hok_flag == false)
	{
		//�ی����̃J�M�I�u�W�F�N�g�̏���
		CObjHokenKey* k2 = new CObjHokenKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k2, HOKEN_KEY, 1);
	}
	if (Hammer == 1 && Ham_flag == false)
	{
		//�n���}�[�I�u�W�F�N�g�̏���
		CObjHammer* i = new CObjHammer(HeroX + 8, HeroY + 8);
		Objs::InsertObj(i, OBJ_HAMMER, 1);
	}

}

void CSceneRouka1::Scene()
{

}