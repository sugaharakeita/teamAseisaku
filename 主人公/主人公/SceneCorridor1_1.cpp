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
#include "SceneCorridor1_1.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneCorridor1_1::CSceneCorridor1_1()
{

}

//�f�X�g���N�^
CSceneCorridor1_1::~CSceneCorridor1_1()
{

}

//���������]�b�g
void CSceneCorridor1_1::InitScene()
{

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Corridor1_1�I�u�W�F�N�g����
	CObjCorridor1_1* objb = new CObjCorridor1_1();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_1, 9);


	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"��l��.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"�L��1-1.png", 9, TEX_SIZE_512);
}


//���s�����]�b�g
void CSceneCorridor1_1::Scene()
{

}
