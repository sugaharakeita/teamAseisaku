#pragma once
//�g�p����w�b�^�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CSceneCorridor2_1 :public CScene
{
public:
	CSceneCorridor2_1();
	~CSceneCorridor2_1();
	void InitScene(); //���������]�b�g
	void Scene(); //���s�����]�b�g
private:
	int m_time; //�o���J�E���g

};

