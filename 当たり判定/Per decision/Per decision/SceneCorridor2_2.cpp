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
#include "SceneCorridor2_2.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneCorridor2_2::CSceneCorridor2_2()
{

}

//�f�X�g���N�^
CSceneCorridor2_2::~CSceneCorridor2_2()
{

}

//���������]�b�g
void CSceneCorridor2_2::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"�d���̊�.wav", BACK_MUSIC); //�ʏ�@�L��
	Audio::LoadAudio(1, L"���_�̕�.wav", BACK_MUSIC); //Enemy�o��

	Audio::LoadAudio(2, L"�w�Z�̘L������� .wav", BACK_MUSIC); //��l������

	//�{�����[����0.6���炷
	float v = Audio::VolumeMaster(0.6);

	//���y�X�^�[�g
	Audio::Start(0);

	//�b���J�E���g������
	m_time = 0;

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Corridor2_2�I�u�W�F�N�g����
	CObjCorridor2_2* objb = new CObjCorridor2_2();
	Objs::InsertObj(objb, OBJ_CORRIDOR2_2, 9);


	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"�L��2-2.png", 9, TEX_SIZE_512);
}


//���s�����]�b�g
void CSceneCorridor2_2::Scene()
{
	/*
	m_time++;

	//�G�I�u�W�F�N�g�쐬�E�G�o����BGM�ύX
	if (m_time == 90)
	{
		CObjEnemy* objh = new CObjEnemy(0, 0);
		Objs::InsertObj(objh, OBJ_ENEMY, 11);

		Audio::Stop(0);
		Audio::Start(1);
	}
*/
}
