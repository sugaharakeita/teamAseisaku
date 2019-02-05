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
#include "SceneHomepreparationroom.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneHomepreparationroom::CSceneHomepreparationroom()
{

}

//�f�X�g���N�^
CSceneHomepreparationroom::~CSceneHomepreparationroom()
{

}

//���������\�b�h
void CSceneHomepreparationroom::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(3, L"�d���̊�.wav", BACK_MUSIC); //�ʏ�@����

	Audio::LoadAudio(2, L"�w�Z�̘L������� .wav", BACK_MUSIC); //��l������

	//�{�����[����0.8���炷
	float v = Audio::VolumeMaster(0.8);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(3);

	//�O���t�B�b�N�ǂݍ��݁E��l��
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ��݁E�}�b�v
	Draw::LoadImage(L"�ƒ돀����.png", 9, TEX_SIZE_512);


	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);


	//Map�I�u�W�F�N�g�쐬
	CObjHomepreparationroom* objhp = new CObjHomepreparationroom();
	Objs::InsertObj(objhp, OBJ_ROOM, 9);
}

//���s�����\�b�h
void CSceneHomepreparationroom::Scene()
{

}