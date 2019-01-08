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
	//�\������摜�̓ǂݎ��
	Draw::LoadImage(L"���b�Z�[�W�E�B���h�E.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�A�C�e���S��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�L��1-1.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�E����.png", 8, TEX_SIZE_512);
	//�E�����I�u�W�F�N�g�̍쐬
	CObjShokuin* r2 = new CObjShokuin();
	Objs::InsertObj(r2, SPOT_SHOKUIN, 0);
	//��l���I�u�W�F�N�g�̍쐬
	CObjHero* h = new CObjHero(0.0f, 0.0f);
	if(Rouka1L==1)//�P�K�L����������ڂ����ꍇ
		CObjHero* h = new CObjHero(0.0f, 128.0f);
	else if (Rouka1CL == 1)//�P�K�L��������������ڂ����ꍇ
		CObjHero* h = new CObjHero(736.0f, 128.0f);
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
	//�E�����̔��I�u�W�F�N�g�̍쐬
	CObjShokuinDoor* d1 = new CObjShokuinDoor(0.0f, 0.0f);
	Objs::InsertObj(d1, SHOKUIN_DOOR, 1);
	CObjShokuinDoor* d2 = new CObjShokuinDoor(732.0f, 0.0f);
	Objs::InsertObj(d2, SHOKUIN_DOOR, 1);
	//�E�����ɂ���\�莆�I�u�W�F�N�g�̍쐬
	CObjShokuinPaper* t1 = new CObjShokuinPaper(78.0f, 34.0f);
	Objs::InsertObj(t1, OBJ_TEXTURE, 1);
	//�����󋵂ɉ����Đ����������
	if (KouchouKey == 1 && Kou_flag == false)
	{
		//�Z�����̃J�M�I�u�W�F�N�g�̏���
		CObjKouchouKey* k = new CObjKouchouKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k, KOUCHOU_KEY, 1);
	}
	if (HokenKey == 0)
	{
		//�ی����̃J�M�I�u�W�F�N�g�̐ݒu
		CObjHokenKey* k2 = new CObjHokenKey(177.0f, 72.0f);
		Objs::InsertObj(k2, HOKEN_KEY, 1);
	}
	else if (HokenKey == 1 && Hok_flag == false)
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

void CSceneShokuin::Scene()
{

}