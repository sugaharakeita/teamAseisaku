#pragma once
//�g�p����w�b�^�[�t�@�C��
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

using namespace GameL;

class CObjBackground :public CObj, private CObjPerdecision
{
public:
	CObjBackground() {};
	~CObjBackground() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[
private:

	float m_x1; //�w�i1�̈ʒu���
	float m_x2; //�w�i2�̈ʒu���
};