#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjHokensitu :public CObj
{

	public:
		CObjHokensitu() {};
		~CObjHokensitu() {};
		void Init();
		void Action();
		void Draw();
	
	private:
		int m_x;
		int m_y;

};
