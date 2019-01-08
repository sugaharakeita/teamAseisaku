#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneKouchou.h"
#include "Hero.h"
#include "GameHead.h"

CSceneKouchou::CSceneKouchou()
{

}

CSceneKouchou::~CSceneKouchou()
{

}

void CSceneKouchou::InitScene()
{
	//�\������摜�̓ǂݎ��
	Draw::LoadImage(L"���b�Z�[�W�E�B���h�E.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�A�C�e���S��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�L��1-1.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�Z����.png", 7, TEX_SIZE_512);
	//�Z�����I�u�W�F�N�g�̍쐬
	CObjKouchou* r1 = new CObjKouchou();
	Objs::InsertObj(r1, SPOT_KOUCHOU, 0);
	//��l���I�u�W�F�N�g�̍쐬
	CObjHero* h = new CObjHero(736, 520);
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
	//�Z�����̔��I�u�W�F�N�g�̍쐬
	CObjKouchouDoor* d0 = new CObjKouchouDoor(580.0f, 586.0f);
	Objs::InsertObj(d0, KOUCHOU_DOOR, 1);
	//�����󋵂ɉ����Đ����������
	if (Hammer == 0)
	{
		//�n���}�[�I�u�W�F�N�g�̐ݒu
		CObjHammer* i = new CObjHammer(188, 164);
		Objs::InsertObj(i, OBJ_HAMMER, 1);
	}
	else if (Hammer == 1 && Ham_flag == false)
	{
		//�n���}�[�I�u�W�F�N�g�̏���
		CObjHammer* i = new CObjHammer(HeroX + 8, HeroY + 8);
		Objs::InsertObj(i, OBJ_HAMMER, 1);
	}
}

void CSceneKouchou::Scene()
{

}