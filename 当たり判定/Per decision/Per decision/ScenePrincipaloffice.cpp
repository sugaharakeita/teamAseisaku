//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "ScenePrincipaloffice.h"
#include "GameHead.h"

//�R���X�g���N�^
CScenePrincipaloffice::CScenePrincipaloffice()
{

}

//�f�X�g���N�^
CScenePrincipaloffice::~CScenePrincipaloffice()
{

}

//���������]�b�g
void CScenePrincipaloffice::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(3, L"�d���̊�.wav", BACK_MUSIC); //�ʏ�@����

	Audio::LoadAudio(2, L"�w�Z�̘L������� .wav", BACK_MUSIC); //��l������

	float v = Audio::VolumeMaster(3);

	
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(3);


	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Principaloffice�I�u�W�F�N�g����
	CObjPrincipaloffice* objb = new CObjPrincipaloffice();
	Objs::InsertObj(objb, OBJ_PRINCIPALOFFICE, 9);
	

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"�Z����.PNG", 9, TEX_SIZE_512);

}


//���s�����]�b�g
void CScenePrincipaloffice::Scene()
{

}
