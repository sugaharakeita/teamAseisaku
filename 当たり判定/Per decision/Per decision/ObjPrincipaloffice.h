#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjPrincipaloffice :public CObj, private CObjPerdecision
{
public:
	CObjPrincipaloffice() {};
	~CObjPrincipaloffice() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[

};
