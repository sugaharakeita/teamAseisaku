#pragma once
//�g�p����w�b�^�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CSceneCorridor :public CScene
{
public:
	CSceneCorridor();
	~CSceneCorridor();
	void InitScene(); //���������]�b�g
	void Scene(); //���s�����]�b�g
private:
	int m_time; //�o���J�E���g
	//�G���A�ړ��t���O
	bool m_flag_Corridor1_1;
	bool m_flag_Corridor1_2;
	bool m_flag_Corridor1_3;
	bool m_flag_Staffroom;
	bool m_flag_Principaloffice;
	bool m_flag_Infirmary;
	bool m_flag_Corridor2_1;
	bool m_flag_Corridor2_2;
	bool m_flag_Corridor2_3;
	bool m_flag_Corridor3_1;
	bool m_flag_Corridor3_2;
	bool m_flag_Corridor3_3;
	//�G���A�ԍ�
	int m_Corridor_co;
	//�A���ړ��h�~�t���O
	bool m_flag_go;
	//�K�w���� 1=1�K 2=2�K 3=3�K
	int m_Storey;
	
};
