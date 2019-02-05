//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL_ (0)
#define _HAS_ITERATOR_DEBUGGINGb (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMusicroom.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMusicroom::CSceneMusicroom()
{

}

//�f�X�g���N�^
CSceneMusicroom::~CSceneMusicroom()
{

}

//���������\�b�h
void CSceneMusicroom::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(3, L"�d���̊�.wav", BACK_MUSIC); //�ʏ�@����

	Audio::LoadAudio(2, L"�w�Z�̘L������� .wav", BACK_MUSIC); //��l������

	float v = Audio::VolumeMaster(3);

	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(3);

	//�O���t�B�b�N�ǂݍ��݁E��l��
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ��݁E�}�b�v
	Draw::LoadImage(L"���y��.png", 9, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);


	//Map�I�u�W�F�N�g�쐬
	CObjMusicroom* objmu = new CObjMusicroom();
	Objs::InsertObj(objmu, OBJ_ROOM, 9);
}

//���s�����\�b�h
void CSceneMusicroom::Scene()
{

}