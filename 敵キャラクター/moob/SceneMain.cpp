//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������\�b�h
void CSceneMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	//Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"��{�����Y�E��ver.png", 1, TEX_SIZE_512);

	//��l���I�u�W�F�N�g
	CObjHero*obj = new CObjHero;
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Map�I�u�W�F�N�g
	CObjMap*objb = new CObjMap();
	Objs::InsertObj(objb, OBJ_MAP, 9);

	//test�p�@�G�I�u�W�F�N�g�쐬
	CObjEnemy*obje = new CObjEnemy(0,0);
	Objs::InsertObj(obje, OBJ_ENEMY, 10);
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}