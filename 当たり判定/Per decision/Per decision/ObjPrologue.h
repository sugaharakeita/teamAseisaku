#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjPrologue :public CObj
{
	public:
		CObjPrologue() {};
		~CObjPrologue() {};
		void Init();			//�C�j�V�����C�Y
		void Action();			//�A�N�V����
		void Draw();			//�h���[

	private:
		bool m_key_flag;//�L�[�t���O
		bool m_start; //�X�^�[�g�t���O
		int m_start_co; //�X�^�[�g�J�E���g

};

