#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjCorridor1_1 :public CObj , private CObjPerdecision
{
public:
	CObjCorridor1_1() {};
	~CObjCorridor1_1() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
private:
	int m_x; //�����蔻��ʒu x
	int m_y; //�����蔻��ʒu y
	//�G���A�ړ��t���O
	//bool m_flag_Corridor1_1;
};