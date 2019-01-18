#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:��l��
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }

private:
	float m_px;  //�ʒu
	float m_py;
	float m_vx;  //�ړ��x�N�g��
	float m_vy;
	float m_posture; //�p��
	int m_go_cox; //�L���ړ���x
	int m_go_coy; //�����ړ���y

	bool m_key_flag;//�L�[�t���O

	int m_ani_time; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;//�`��t���[��
	int m_footsteps_co; //�����b���J�E���g
	bool m_footsteps_switching; //�����I���E�I�t

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//�������Ă���block�̎�ނ̊m�F�p
	int m_Obstacle_type;

	//��_
	float px, py; 

};

