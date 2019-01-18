//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL_ (0)
#define _HAS_ITERATOR_DEBUGGINGb (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneConferenceroom.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneConferenceroom::CSceneConferenceroom()
{

}

//�f�X�g���N�^
CSceneConferenceroom::~CSceneConferenceroom()
{

}

//���������\�b�h
void CSceneConferenceroom::InitScene()
{
	//�O���t�B�b�N�ǂݍ��݁E��l��
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ��݁E�}�b�v
	Draw::LoadImage(L"��c��.png", 0, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ��݁E1�K�G
	Draw::LoadImage(L"�G��.png", 2, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//Test�p�@�G�I�u�W�F�N�g�쐬
	CObjEnemy3* obje = new CObjEnemy3(0, 0);
	Objs::InsertObj(obje, OBJ_ENEMY, 10);

	//Map�I�u�W�F�N�g�쐬
	CObjConferenceroom* objcon = new CObjConferenceroom();
	Objs::InsertObj(objcon, OBJ_ROOM, 9);
}

//���s�����\�b�h
void CSceneConferenceroom::Scene()
{

}