#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjCorridor1_2 :public CObj, private CObjPerdecision
{
public:
	CObjCorridor1_2() {};
	~CObjCorridor1_2() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[

};