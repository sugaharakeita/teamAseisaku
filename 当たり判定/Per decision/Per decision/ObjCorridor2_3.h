#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjCorridor2_3 :public CObj, private CObjPerdecision
{
public:
	CObjCorridor2_3() {};
	~CObjCorridor2_3() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[

};