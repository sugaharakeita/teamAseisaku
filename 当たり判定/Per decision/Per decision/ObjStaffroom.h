#pragma once
//�g�p����w�b�^�[�t�@�C��
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

using namespace GameL;

class CObjStaffroom :public CObj, private CObjPerdecision
{
public:
	CObjStaffroom() {};
	~CObjStaffroom() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[

};