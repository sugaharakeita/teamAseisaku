#pragma once
//�g�p����w�b�^�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CSceneInfirmary :public CScene
{
public:
	CSceneInfirmary();
	~CSceneInfirmary();
	void InitScene(); //���������]�b�g
	void Scene(); //���s�����]�b�g
private:
	int m_time; //�o���J�E���g

};


