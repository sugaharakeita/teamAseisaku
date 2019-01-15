//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL_ (0)
#define _HAS_ITERATOR_DEBUGGINGb (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain8.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain8::CSceneMain8()
{

}

//�f�X�g���N�^
CSceneMain8::~CSceneMain8()
{

}

//���������\�b�h
void CSceneMain8::InitScene()
{
	//�O���t�B�b�N�ǂݍ��݁E��l��
	Draw::LoadImageW(L"HeroTouka.png", 1, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ��݁E�}�b�v
	Draw::LoadImageW(L"�L��3-2.png", 0, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ��݁E1�K�G
	Draw::LoadImageW(L"�G��.png", 2, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//Test�p�@�G�I�u�W�F�N�g�쐬
	CObjEnemy2* obje = new CObjEnemy2(0, 0);
	Objs::InsertObj(obje, OBJ_ENEMY, 10);

	//Map�I�u�W�F�N�g�쐬
	CObjMap8* objm = new CObjMap8();
	Objs::InsertObj(objm, OBJ_MAP, 9);
}

//���s�����\�b�h
void CSceneMain8::Scene()
{

}