#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjCorridor :public CObj, private CObjPerdecision
{
public:
	CObjCorridor() {};
	~CObjCorridor() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
private:
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
	bool m_flag_Classroom;
	bool m_flag_Library;
	bool m_flag_Homeeconomicsroom;
	bool m_flag_Homepreparationroom;
	bool m_flag_Corridor3_1;
	bool m_flag_Corridor3_2;
	bool m_flag_Corridor3_3;
	bool m_flag_Computerroom;
	bool m_flag_Musicroom;
	bool m_flag_Conferenceroom;
	bool m_flag_Rooftop;


	//�K�w����
	bool m_Storey1;
	bool m_Storey2;
	bool m_Storey3;
	bool m_Storey4;

	float m_x1;//�w�i�P�̈ʒu���
	float m_x2;//�w�i�Q�̈ʒu���


	float m_scroll;//���E�X�N���[���p
};