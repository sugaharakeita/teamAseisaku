#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�}�b�v
class CObjRooftop :public CObj
{
public:
	CObjRooftop() {};
	~CObjRooftop() {};

	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

private:

	float m_x1;//�w�i�P�̈ʒu���
	float m_x2;//�w�i�Q�̈ʒu���

	bool m_key_flag;//�L�[�t���O

	float m_scroll;  //���E�X�N���[���p

};