#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjGameOver :public CObj
{
public:
	CObjGameOver() {};
	~CObjGameOver() {};
	void Init();			//�C�j�V�����C�Y
	void Action();			//�A�N�V����
	void Draw();			//�h���[

private:
	bool m_key_flag;//�L�[�t���O
	bool m_gameover; //�Q�[���I�[�o�[�t���O
	int m_gameover_co; //�Q�[���I�[�o�[�J�E���g

};


