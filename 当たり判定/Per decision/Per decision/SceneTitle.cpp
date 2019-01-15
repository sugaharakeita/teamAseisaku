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
#include "SceneClear.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//���������]�b�g
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"School");
	Font::SetStrTex(L"Enter�L�[�ŃX�^�[�g");

	//���y�̓ǂݍ���
	Audio::LoadAudio(0, L"VEIL �I�[�v�j���O.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"�V�X�e��49�@���艹 .wav", SOUND_TYPE::EFFECT);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(-0.6f); //�{�����[����0.6������
	Audio::Start(0);

	//�^�C�g���I�u�W�F�N�g����
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);

}


//���s�����]�b�g
void CSceneTitle::Scene()
{

}
