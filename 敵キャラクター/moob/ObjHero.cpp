//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�ʒu���X�擾�p
float CObjHero::GetX()
{
	return m_px;
}

//�ʒu���X�擾�p
float CObjHero::GetY()
{
	return m_py;
}


//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 0.0f;	//�ʒu
	m_py = 0.0f;
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0.0f;		//�E����0.0f ������1.0f

	m_ani_time = 0;		
	m_ani_frame = 1;		//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��
}

//�A�N�V����
void CObjHero::Action()
{
	//�ړ��x�N�g���̔j��
	m_vy = 0.0f;

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy = m_speed_power;
		m_vy = -2.0f;
	}
	
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += m_speed_power;
		m_vy = +2.0f;
	}


	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;	//�L�[���͂������ꍇ�͐Î~�t���[���ɂ���
		m_ani_time = 0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//���C
	m_vx += -(m_vx*0.098);

	//�ʒu�X�V
	m_px += m_vx*1.0;
	m_py += m_vy*1.0;
}

//�h���[
void CObjHero::Draw()
{
	int AniData[4] =
	{
		1 , 0 , 2 , 0 ,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   =  0.0f + AniData[m_ani_frame] * 64;
	src.m_right  = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (		 64.0f * m_posture ) + m_px;
	dst.m_right  = ( 64   -  64.0f * m_posture ) + m_px;
	dst.m_bottom = 64.0f+m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

}

