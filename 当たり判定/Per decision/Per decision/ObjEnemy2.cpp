//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include <math.h>

#include "GameHead.h"
#include "ObjEnemy2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

float g_enemy2_x = 150.0f;
float g_enemy2_y = 0.0f;

//�ʒu���X�擾�p
float CObjEnemy2::GetX()
{
	return m_px;
}

//�ʒu���X�擾�p
float CObjEnemy2::GetY()
{
	return m_py;
}


//�R���X�g���N�^
CObjEnemy2::CObjEnemy2(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjEnemy2::Init()
{
	m_x = x;
	m_y = y;
	m_px = g_enemy2_x;
	m_py = g_enemy2_y;
	m_vx = 1.0f;
	m_vy = 0.0f;
	m_posture = 1.0f;

	m_ani_time = 0;
	m_ani_frame = 1;

	m_speed_power = 1.5f;
	m_ani_max_time = 4;


	//�Փˏ�Ԋm�F�p������
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;


	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 45, 60, ELEMENT_ENEMY, OBJ_ENEMY, 11);
}

//�A�N�V����
void CObjEnemy2::Action()
{
	m_vx = 0;
	m_vy = 0;

	//��l���̈ʒu���擾
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float hx = hero->GetX();
	//float hy = hero->GetY() ;

	//��l���ƒǔ��Ŋp�x�����
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float x = obj->GetX() - m_px;
	float y = obj->GetY() - m_py;

	//�G�̈ʒu
	CObjEnemy2*obje = (CObjEnemy2*)Objs::GetObj(OBJ_ENEMY);
	float ex = obj->GetX() - m_px;
	float ey = obj->GetY() - m_py;

	//�v�Z�p�x�𗎂Ƃ��A�΂߈ړ���h��
	static int   count = 0;
	static float br = 0.0f;
	count++;
	if (count > 30)
	{
		count = 0;
		int ar = atan2(y, x)*180.0f / 3.14;

		if (ar < 0)
		{
			ar = 360 + ar;
		}
		br = ar;
	}

	if (br >= 45 && br < 136)//�� 45�x�ȏ�@136�x����
	{

		m_vy += m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (br > 0 && br < 45 || br > 315) //�E�@0�x�ȏォ��45�x�����@315�x�ȏ�
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (br > 225 && br < 316)//���@225�x�ȏ�@316����
	{
		m_vy -= m_speed_power;
		m_posture = 2.0f;
		m_ani_time += 1;
	}
	else if (br > 135 && br < 225)//���@135�x�ȏ�@225�x����
	{
		m_vx -= m_speed_power;
		m_posture = 3.0f;
		m_ani_time += 1;
	}

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�G���X�e�[�W�̓����蔻��ɓ����������̏����i�S�X�e�[�W�Ή��j
	if (hit->CheckElementHit(ELEMENT_FIELD) == true)
	{

		HIT_DATA** hit_data;
		hit_data = hit->SearchElementHit(ELEMENT_FIELD);

		float r = hit_data[0]->r;

		//�p�x�ŏ㉺���E�𔻒�
		if (r > 0 && r < 45 || r >= 315)
		{
			//�E
			m_hit_right = true;
		}
		else if (r >= 45 && r < 136)
		{
			//��
			m_hit_up = true;
		}
		else if (r >= 135 && r <= 225)
		{
			//��
			m_hit_left = true;
		}
		else if (r > 225 && r < 316)
		{
			//��
			m_hit_down = true;
		}


		//���ɓ����蔻�肪�������ꍇ
		if (m_hit_left == true)
		{
			m_vx = m_vx + 2.0f;
		}

		//�E�ɓ����蔻�肪�������ꍇ
		if (m_hit_right == true)
		{
			m_vx = m_vx - 2.0f;
		}

		//���ɓ����蔻�肪�������ꍇ
		if (m_hit_down == true)
		{
			m_vy = m_vy - 2.0f;
		}

		//��ɓ����蔻�肪�������ꍇ
		if (m_hit_up == true)
		{
			m_vy = m_vy + 2.0f;
		}
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
	hit->SetPos(m_px, m_py);
}
//�h���[
void CObjEnemy2::Draw()
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
		src.m_top = 205.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 40;
		src.m_right = 40.0f + AniData[m_ani_frame] * 40;
		src.m_bottom = 254.0f;


	}
	else if (m_posture == 0)//�ォ�牺
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 13.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 40;
		src.m_right = 40.0f + AniData[m_ani_frame] * 40;
		src.m_bottom = 62.0f;


	}
	else if (m_posture == 1)//�E����
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 136.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 40;
		src.m_right = 41.0f + AniData[m_ani_frame] * 40;
		src.m_bottom = 189.0f;



	}
	else if (m_posture == 3)//������
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 76.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 40;
		src.m_right = 35.0f + AniData[m_ani_frame] * 40;
		src.m_bottom = 125.0f;

	}
	

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 40.0f + m_px;
	dst.m_bottom = 49.0f + m_py;

	//�`��
	Draw::Draw(11, &src, &dst, c, 0.0f);

}