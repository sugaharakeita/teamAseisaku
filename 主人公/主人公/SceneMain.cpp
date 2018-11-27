//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL_ (0)
#define _HAS_ITERATOR_DEBUGGINGb (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"

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
	Draw::LoadImageW(L"HeroTouka.png", 1, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"��{�����Y����.png", 2, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"�ی����C����.png", 5, TEX_SIZE_1024);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjHokensitu* objb = new CObjHokensitu();
	Objs::InsertObj(objb, OBJ_HOKENSITU, 8);

	//�G�I�u�W�F�N�g�쐬
	CObjEnemy* obje = new CObjEnemy(0,0);
	Objs::InsertObj(obje, OBJ_ENEMY, 9);
}

//���s�����\�b�h
void CSceneMain::Scene()
{
	
}