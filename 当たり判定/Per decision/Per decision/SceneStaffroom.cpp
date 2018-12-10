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
#include "SceneStaffroom.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneStaffroom::CSceneStaffroom()
{

}

//�f�X�g���N�^
CSceneStaffroom::~CSceneStaffroom()
{

}

//���������]�b�g
void CSceneStaffroom::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"��������.wav", BACK_MUSIC); //�ʏ�
	Audio::LoadAudio(1, L"���_�̕�.wav", BACK_MUSIC); //Enemy�o��

	//�{�����[����0.8���炷
	float v = Audio::VolumeMaster(0.8);

	//���y�X�^�[�g
	Audio::Start(0);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Staffroom�I�u�W�F�N�g����
	CObjStaffroom* objb = new CObjStaffroom();
	Objs::InsertObj(objb, OBJ_STAFFROOM, 9);
	
	//�G�I�u�W�F�N�g�쐬
	CObjEnemy* objh = new CObjEnemy(0, 0);
	Objs::InsertObj(objh, OBJ_ENEMY, 11);
	
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"��{�����Y����.png", 11, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"�E����������.png", 9, TEX_SIZE_512);

}


//���s�����]�b�g
void CSceneStaffroom::Scene()
{

}
