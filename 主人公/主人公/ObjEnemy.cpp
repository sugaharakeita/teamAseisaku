//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include <math.h>

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
CObjEnemy::CObjEnemy(float x,float y)
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
	m_ani_frame =1;

	m_speed_power = 0.5f;
	m_ani_max_time = 4;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 50, 100, ELEMENT_ENEMY, OBJ_ENEMY,1);
}

//�A�N�V����
void CObjEnemy::Action()
{
	m_vx = 0;
	m_vy = 0;

	//��l���̈ʒu���擾
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float hx = hero->GetX();
	//float hy = hero->GetY() ;

	//��l���ƒǔ��Ŋp�x�����
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	int x = obj->GetX()- m_px ;
	int y = obj->GetY()- m_py ;




	int ar = atan2(y,x)*180.0f / 3.14;

	if (ar < 0)
	{
		ar = 360 + ar;
	}

	if (ar >= 45 && ar < 136)//�� 45�x�ȏ�@136�x����
	{
		
		m_vy += m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (ar > 0 && ar < 45 || ar >= 315 ) //�E�@0�x�ȏォ��45�x�����@315�x�ȏ�
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (ar > 225 && ar < 316)//���@225�x�ȏ�@316����
	{
		m_vy -= m_speed_power;
		m_posture = 2.0f;
		m_ani_time += 1;
	}
	else if (ar >= 135 && ar <= 225)//���@135�x�ȏ�@225�x����
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

	//�ʒu�X�V
	m_px += m_vx*1.75;
	m_py += m_vy*1.75;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit -> SetPos(m_px, m_py);

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

	 if (m_posture == 2)//�������
	{
		//�؂���ʒu�̐ݒ�
		src.m_top    = 196.0f;
		src.m_left   =  12.0f + AniData[m_ani_frame] * 64;
		src.m_right  =  48.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 286.0f;

	
	}
	else if (m_posture == 0)//�ォ�牺
	{
		//�؂���ʒu�̐ݒ�
		src.m_top    =  4.0f;
		src.m_left   = 12.0f + AniData[m_ani_frame] * 64;
		src.m_right  = 50.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 93.0f;

	
	}
	else if (m_posture == 1)//�E����
	{
		//�؂���ʒu�̐ݒ�
		src.m_top    = 100.0f;
		src.m_left   =   8.0f + AniData[m_ani_frame] * 64;
		src.m_right  =  50.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 188.0f;

	

	}
	else if (m_posture == 3)//������
	{
		//�؂���ʒu�̐ݒ�
		src.m_top    = 292.0f;
		src.m_left   =  15.0f + AniData[m_ani_frame] * 64;
		src.m_right  =  55.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 380.0f;

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

	//�\���ʒu�̐ݒ�
	 dst.m_top = 0.0f + m_py;
	 dst.m_left = 0.0f + m_px;
	 dst.m_right = 48.0f + m_px;
	 dst.m_bottom = 96.0f + m_py;

	//�`��
	Draw::Draw(2, &src, &dst, c, 0.0f);

}