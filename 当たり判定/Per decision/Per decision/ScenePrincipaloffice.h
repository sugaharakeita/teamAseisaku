#pragma once
//�g�p����w�b�^�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CScenePrincipaloffice :public CScene
{
public:
	CScenePrincipaloffice();
	~CScenePrincipaloffice();
	void InitScene(); //���������]�b�g
	void Scene(); //���s�����]�b�g
private:
	int m_time; //�o���J�E���g

};


