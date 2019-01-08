//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneGameOver.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//���������\�b�h
void CSceneGameOver::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"��������C.wav", BACK_MUSIC); 
	Audio::LoadAudio(1, L"�V�X�e��49�@���艹 .wav", SOUND_TYPE::EFFECT);


	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"���[�ނ��[�΁[�I�I");
	Font::SetStrTex(L"(�L�O3 ^`�jm9");
	Font::SetStrTex(L"�^�C�g����");

	//�Q�[���I�[�o�[�I�u�W�F�N�g�̍쐬
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}

//���s�����\�b�h
void CSceneGameOver::Scene()
{

}