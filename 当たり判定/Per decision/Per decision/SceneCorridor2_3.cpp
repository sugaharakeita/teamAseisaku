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
#include "SceneCorridor2_3.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneCorridor2_3::CSceneCorridor2_3()
{

}

//�f�X�g���N�^
CSceneCorridor2_3::~CSceneCorridor2_3()
{

}

//���������]�b�g
void CSceneCorridor2_3::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"�d���̊�.wav", BACK_MUSIC); //�ʏ�
	Audio::LoadAudio(1, L"���_�̕�.wav", BACK_MUSIC); //Enemy�o��

	//�{�����[����0.8���炷
	float v = Audio::VolumeMaster(0.8);

	//���y�X�^�[�g
	Audio::Start(0);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Corridor2_2�I�u�W�F�N�g����
	CObjCorridor2_3* objb = new CObjCorridor2_3();
	Objs::InsertObj(objb, OBJ_CORRIDOR2_3, 9);


	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"�L��2-3.png", 9, TEX_SIZE_512);
}


//���s�����]�b�g
void CSceneCorridor2_3::Scene()
{

}
