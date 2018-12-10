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
#include "SceneInfirmary.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneInfirmary::CSceneInfirmary()
{

}

//�f�X�g���N�^
CSceneInfirmary::~CSceneInfirmary()
{

}

//���������]�b�g
void CSceneInfirmary::InitScene()
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

	//Infirmary�I�u�W�F�N�g����
	CObjInfirmary* objb = new CObjInfirmary();
	Objs::InsertObj(objb, OBJ_INFIRMARY, 9);
	
	//�G�I�u�W�F�N�g�쐬
	CObjEnemy* objh = new CObjEnemy(0, 0);
	Objs::InsertObj(objh, OBJ_ENEMY, 11);
	
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"��{�����Y����.png", 11, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"�ی����C����.png", 9, TEX_SIZE_512);

}


//���s�����]�b�g
void CSceneInfirmary::Scene()
{

}
