//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 100.0f;  //�ʒu
	m_py = 0.0f;
	m_vx = 0.0f;  //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0;   //�E����0.0f�@������1.0f ����2.0f ���3.0f



	m_ani_time = 0;   
	m_ani_frame = 1;  //�Î~�t���[���������ɂ���

	//block�Ƃ̏ՓˏՓˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�L�[�̓��͕���
	//��
	if (Input::GetVKey('W') == true)
	{
		m_vy = -4.0f;  
		m_posture = 3;
		m_ani_time += 1;
		
	}
	
	//��
	else if (Input::GetVKey('A') == true)
	{
		m_vx -=4.0f;
		m_posture = 1;
		m_ani_time += 1;
	}

	//��
	else if (Input::GetVKey('S') == true)
	{

		m_vy = +4.0f;
		m_posture = 2;
		m_ani_time += 1;
		
	}
	//�E
	else if (Input::GetVKey('D') == true)
	{
		m_vx += 4.0f;
		m_posture = 0;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 0; //�L�[���͂������ꍇ�͐Î~�t���[���ɂ���
		m_ani_time = 0;
	}


	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	
	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);  //�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_px, m_py);               //���������V�����ʒu�i��l���̈ʒu�j���ɒu��������
}



//�h���[

void CObjHero::Draw()
{
	int AniData[5] =
	{
		0,1,2,3,0,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu


	//d�i�E�j�����͂��ꂽ�Ƃ�
	if (m_posture == 0)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 128.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 192.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = (64.0f  *   m_posture) + m_px;
		dst.m_right = (64 - 64.0f  *   m_posture) + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//a�i���j�����͂��ꂽ�Ƃ�
	else if (m_posture == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 128.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f+m_px;
		dst.m_right =64.0f +m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//s�i���j�����͂��ꂽ�Ƃ�
	else if (m_posture == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 64.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left =0.0f  + m_px;
		dst.m_right = 64.0f  + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//w�i��j�����͂��ꂽ�Ƃ�
	else if (m_posture == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 192.0f;
		src.m_left = 0.0f+ AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 256.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f+ m_px;
		dst.m_right =  64.0f  + m_px;
		dst.m_bottom = 64.0f + m_py;
	}


	
	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
	
}

