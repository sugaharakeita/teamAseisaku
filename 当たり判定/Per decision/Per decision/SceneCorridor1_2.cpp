//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneCorridor1_2.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneCorridor1_2::CSceneCorridor1_2()
{

}

//�f�X�g���N�^
CSceneCorridor1_2::~CSceneCorridor1_2()
{

}

//���������]�b�g
void CSceneCorridor1_2::InitScene()
{

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

	//�G�I�u�W�F�N�g�쐬
	CObjEnemy* objh = new CObjEnemy(0, 0);
	Objs::InsertObj(objh, OBJ_ENEMY, 10);

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"��{�����Y����.png", 10, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);
}


//���s�����]�b�g
void CSceneCorridor1_2::Scene()
{

}
