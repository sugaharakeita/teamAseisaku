//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include <math.h>
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemy.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�ʒu���X�擾�p
float CObjEnemy::GetX()
{
	return m_px;
}

//�ʒu���X�擾�p
float CObjEnemy::GetY()
{
	return m_py;
}


//�R���X�g���N�^
CObjEnemy::CObjEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjEnemy::Init()
{
	m_x = x;
	m_y = y;
	m_px = 200.0f;
	m_py = 200.0f;
	m_vx = 1.0f;
	m_vy = 0.0f;
	m_posture = 1.0f;

	m_ani_time = 0;
	m_ani_frame = 1;

	m_speed_power = 2.5f;
	m_ani_max_time = 4;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 96, ELEMENT_ENEMY, OBJ_ENEMY, 11);
}

//�A�N�V����
void CObjEnemy::Action()
{

	m_vx = 0;
	m_vy = 0;

	//��l���ƒǔ��Ŋp�x�����
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float x = obj->GetX() - m_px;
	float y = obj->GetY() - m_py;

	float ar = atan2(y, x)*180.0f / 3.14;

	if (ar > 46 && ar < 135)//��
	{
		m_posture = 0.0f;
		m_vy += m_speed_power;
	}

	else if ((ar < 45 && ar >= 0) || ar > 316)//�E
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (ar > 226 && ar < 315)//��
	{
		m_vy -= m_speed_power;
		m_posture = 2.0f;
	}


	else if (ar > 136 && ar < 225)//��
	{
		m_vx -= m_speed_power;
		m_posture = 3.0f;
		m_ani_time += 1;
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



	//�G�̌��݌����Ă���p�x�����
	//float br = atan2(-m_vy, m_vx)* 180.0f / 3.14f;

	//�ړ�������-�P��������
	//m_vx =cos(ar*3.14 / 180);
	//m_vy =sin(ar*3.14 / 180);


	//�ʒu�X�V
	m_px += m_vx*1.75;
	m_py += m_vy*1.75;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_px, m_py);					//���������V�����ʒu(��l���@�̈ʒu)���ɒu��������

	//�G�@�I�u�W�F�N�g�ƐڐG�������l���@�폜
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);	//��l���@�����L����HitBox�ɍ폜����
	}
}
//�h���[
void CObjEnemy::Draw()
{
	int AniData[4] =
	{
		1 , 0 , 2 , 0 ,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	if (m_posture == 0)//�������
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 196.0f;
		src.m_left = 12.0f + AniData[m_ani_frame] * 64;
		src.m_right = 48.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 286.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 196.0f + m_py;
		dst.m_left = 12.0f + m_px;
		dst.m_right = 48.0f + m_px;
		dst.m_bottom = 286.0f + m_py;
	}

	else if (m_posture == 2)//�ォ�牺
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 4.0f;
		src.m_left = 12.0f + AniData[m_ani_frame] * 64;
		src.m_right = 50.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 93.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 4.0f + m_py;
		dst.m_left = 12.0f + m_px;
		dst.m_right = 50.0f + m_px;
		dst.m_bottom = 93.0f + m_py;
	}

	else if (m_posture == 1)//�E����
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 100.0f;
		src.m_left = 8.0f + AniData[m_ani_frame] * 64;
		src.m_right = 50.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 188.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 100.0f + m_py;
		dst.m_left = 8.0f + m_px;
		dst.m_right = 50.0f + m_px;
		dst.m_bottom = 188.0f + m_py;

	}

	else if (m_posture == 3)//������
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 292.0f;
		src.m_left = 15.0f + AniData[m_ani_frame] * 64;
		src.m_right = 55.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 380.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 292.0f + m_py;
		dst.m_left = 15.0f + m_px;
		dst.m_right = 55.0f + m_px;
		dst.m_bottom = 380.0f + m_py;
	}
	////�؂���ʒu�̐ݒ�
	//src.m_top    =  0.0f;
	//src.m_left   =  0.0f + AniData[m_ani_frame] * 64;
	//src.m_right  = 64.0f + AniData[m_ani_frame] * 64;
	//src.m_bottom = 93.0f;

	////�\���ʒu�̐ݒ�
	//dst.m_top    =  0.0f + m_py;
	//dst.m_left   = 64.0f + m_px;
	//dst.m_right  = 64 - 64.0f + m_px;
	//dst.m_bottom = 93.0f + m_py;

	//�`��
	Draw::Draw(11, &src, &dst, c, 0.0f);

}