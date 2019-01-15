#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneHoken.h"
#include "Hero.h"
#include "GameHead.h"

CSceneHoken::CSceneHoken()
{

}

CSceneHoken::~CSceneHoken()
{

}

void CSceneHoken::InitScene()
{
	//�\������摜�̓ǂݎ��
	Draw::LoadImage(L"���b�Z�[�W�E�B���h�E.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�A�C�e���S��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�L��1-3.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"�ی���.png", 9, TEX_SIZE_512);
	//�ی����I�u�W�F�N�g�̍쐬
	CObjHoken* r3 = new CObjHoken();
	Objs::InsertObj(r3, SPOT_HOKEN, 0);
	//��l���I�u�W�F�N�g�̍쐬
	CObjHero* h = new CObjHero(72, 520);
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
	//�ی����̔��I�u�W�F�N�g�̍쐬
	CObjHokenDoor* d3 = new CObjHokenDoor(78.0f, 580.0f);
	Objs::InsertObj(d3, HOKEN_DOOR, 1);
	//�Z�����̃J�M���蔠�I�u�W�F�N�g�̍쐬
	CObjKouchouHako* b1 = new CObjKouchouHako(724.0f, 14.0f);
	Objs::InsertObj(b1, OBJ_HAKO, 1);
	//�����󋵂ɉ����Đ����������
	if (KouchouKey == 1 && Kou_flag == false)
	{
		//�Z�����̃J�M�I�u�W�F�N�g�̏���
		CObjKouchouKey* k = new CObjKouchouKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k, KOUCHOU_KEY, 1);
	}
	if (Hammer == 1 && Ham_flag == false)
	{
		//�n���}�[�I�u�W�F�N�g�̏���
		CObjHammer* i = new CObjHammer(HeroX + 8, HeroY + 8);
		Objs::InsertObj(i, OBJ_HAMMER, 1);
	}
}

void CSceneHoken::Scene()
{

}