//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneClear.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//���������]�b�g
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"���ł͂����܂łł�");
	Font::SetStrTex(L"�����̓��ł�");
	Font::SetStrTex(L"Enter�L�[�Ń^�C�g����");

	//�N���A�I�u�W�F�N�g����
	CObjClear* obj = new CObjClear();
	Objs::InsertObj(obj, OBJ_CLEAR, 10);

}


//���s�����]�b�g
void CSceneClear::Scene()
{

}
