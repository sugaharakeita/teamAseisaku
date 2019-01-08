#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneKyoushitu.h"
#include "Hero.h"
#include "GameHead.h"

CSceneKyoushitu::CSceneKyoushitu()
{

}

CSceneKyoushitu::~CSceneKyoushitu()
{

}

void CSceneKyoushitu::InitScene()
{
	//�\������摜�̓ǂݎ��
	Draw::LoadImage(L"���b�Z�[�W�E�B���h�E.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�A�C�e���S��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�L��2�S�̐}.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"����������.png", 13, TEX_SIZE_512);
	//�����I�u�W�F�N�g�̍쐬
	CObjKyoushitu* r7 = new CObjKyoushitu();
	Objs::InsertObj(r7, SPOT_KYOUSHITU, 0);
	//��l���I�u�W�F�N�g�̍쐬
	CObjHero* h = new CObjHero(0.0f, 0.0f);
	if (Rouka2C == 1)//�Q�K�L������������ڂ����ꍇ
		CObjHero* h = new CObjHero(0.0f, 128.0f);
	else if (Rouka2R == 1)//�Q�K�L���E������ڂ����ꍇ
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
	//�����󋵂ɉ����Đ����������


}

void CSceneKyoushitu::Scene()
{

}