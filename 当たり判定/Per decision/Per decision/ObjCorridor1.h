#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjCorridor1 :public CObj, private CObjPerdecision
{
public:
	CObjCorridor1() {};
	~CObjCorridor1() {};
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
	bool m_flag_Corridor3_1;
	bool m_flag_Corridor3_2;
	bool m_flag_Corridor3_3;
	//�K�w����
	int m_Storey;
};