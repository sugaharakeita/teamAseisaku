//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "ScenePrologue.h"
#include "GameHead.h"

//�R���X�g���N�^
CScenePrologue::CScenePrologue()
{

}

//�f�X�g���N�^
CScenePrologue::~CScenePrologue()
{

}

//���������\�b�h
void CScenePrologue::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"���炷��");
	Font::SetStrTex(L"��l���͖Y�ꕨ�����Ɋw�Z�֖K�ꂽ�B");
	Font::SetStrTex(L"�����ŁA��l���͗l�X�ȉ��قɏo��E�E�E");
	Font::SetStrTex(L"���ق̖ڂ�~������Ȃ��牮���ڎw���A�E�o���悤��");
	Font::SetStrTex(L"�����ڎw���A�E�o���悤��");
	Font::SetStrTex(L"Enter��Let's go!!");

	//�Q�[���I�[�o�[�I�u�W�F�N�g�̍쐬
	CObjPrologue* objp = new CObjPrologue();
	Objs::InsertObj(objp, OBJ_PROLOGUE, 10);
}

//���s�����\�b�h
void CScenePrologue::Scene()
{

}