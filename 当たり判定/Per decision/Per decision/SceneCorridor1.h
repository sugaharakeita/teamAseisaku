#pragma once
//�g�p����w�b�^�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CSceneCorridor1 :public CScene
{
public:
	CSceneCorridor1();
	~CSceneCorridor1();
	void InitScene(); //���������]�b�g
	void Scene(); //���s�����]�b�g
private:
	int m_time; //�o���J�E���g
	//�G���A�ړ��t���O
	bool m_flag_Corridor1_1;
	bool m_flag_Corridor1_2;
	bool m_flag_Corridor1_3;
	//�G���A�ԍ�
	int m_Corridor1_co;
	//�A���ړ��h�~�t���O
	bool m_flag_go;
};
