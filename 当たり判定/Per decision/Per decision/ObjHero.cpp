
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
	m_px = 400.0f;  //�ʒu Principaloffice 600.0f Infirmary 85.0f
	m_py = 300.0f; // Saff60.0f Corr1_1,2,3 240.0f Principaloffice 520.0f Infirmary 520.0f
	m_vx = 0.0f;  //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0;   //�E����0.0f�@������1.0f ����2.0f ���3.0f


	m_ani_time = 0;
	m_ani_frame = 1;  //�Î~�t���[���������ɂ���

	//�Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	
	//�����蔻��                                �v���C���[
	Hits::SetHitBox(this, m_px+15 , m_py+20 , 32, 32,ELEMENT_PLAYER, OBJ_HERO, 1);
	//					���J�n �c�J�n ���傫�� �c�傫�� ���� ���O
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
		m_vx -= 4.0f;
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



	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);
	if (hit->CheckElementHit(ELEMENT_STAFFROOM) == true)
	{
		//�E
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			m_vx = m_vx - 4.0f;
		}
		//��
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			m_vx = m_vx + 4.0f;
		}
		//��
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			m_vy = m_vy - 4.0f;
		}
		//��
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			m_vy = m_vy + 4.0f;
		}
	}

	if (hit->CheckElementHit(ELEMENT_PRINCIPALOFFICE) == true)
	{
		//�E
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			m_vx = m_vx - 4.0f;
		}
		//��
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			m_vx = m_vx + 4.0f;
		}
		//��
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			m_vy = m_vy - 4.0f;
		}
		//��
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			m_vy = m_vy + 4.0f;
		}
	}

	if (hit->CheckElementHit(ELEMENT_INFIRMARY) == true)
	{
		//�E
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			m_vx = m_vx - 4.0f;
		}
		//��
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			m_vx = m_vx + 4.0f;
		}
		//��
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			m_vy = m_vy - 4.0f;
		}
		//��
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			m_vy = m_vy + 4.0f;
		}
	}

	if (hit->CheckElementHit(ELEMENT_CORRIDOR1_1) == true)
	{
		//�E
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			/*m_vx = m_vx - 4.0f;*/
		}
		//��
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			/*m_vx = m_vx + 4.0f;*/
		}
		//��
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			/*m_vy = m_vy - 4.0f;*/
		}
		//��
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			/*m_vy = m_vy + 4.0f*/;
		}
	}

	if (hit->CheckElementHit(ELEMENT_CORRIDOR1_2) == true)
	{
		

		////�E
		//if (m_posture == 0)
		//{
		//	m_ani_frame = 0;

		//	m_vx = -0.4;
		//}
		////��
		//if (m_posture == 1)
		//{
		//	m_ani_frame = 0;

		//	m_vx = +0.4;
		//}
		////��
		//if (m_posture == 2)
		//{
		//	m_ani_frame = 0;

		//	m_vy = -0.4;
		//}
		////��
		//if (m_posture == 3)
		//{
		//	m_ani_frame = 0;

		//	m_vy = +0.4;
		//}
		////�E��
		//if (Input::GetVKey('D') == true && Input::GetVKey('S') == true)
		//{
		//	m_posture == 2;

		//	m_vx = m_vx + 0.1f;

		//	m_vy = m_vy - 0.1f;
		//}
		////�E��
		//if (Input::GetVKey('D') == true && Input::GetVKey('W') == true)
		//{
		//	m_posture == 3;

		//	m_vx = m_vx - 0.1f;

		//	m_vy = m_vy + 0.1f;
		//}
		////����
		//if (Input::GetVKey('A') == true && Input::GetVKey('S') == true)
		//{
		//	m_posture == 2;

		//	m_vx = m_vx + 0.1f;

		//	m_vy = m_vy + 0.1f;
		//}
		////����
		//if (Input::GetVKey('A') == true && Input::GetVKey('W') == true)
		//{
		//	m_posture == 3;

		//	m_vx = m_vx + 0.1f;

		//	m_vy = m_vy - 0.1f;
		//}

	}

	if (hit->CheckElementHit(ELEMENT_CORRIDOR1_3) == true)
	{
		//�E
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			m_vx = m_vx - 4.0f;
		}
		//��
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			m_vx = m_vx + 4.0f;
		}
		//��
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			m_vy = m_vy - 4.0f;
		}
		//��
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			m_vy = m_vy + 4.0f;
		}
	}


	//if (m_px+64.0f > 800.0f)
	//{
	//	m_px = 800.0f -64.0f;
	//}
	//else if (m_py + 64.0f > 600.0f)
	//{
	//	m_py = 600.0f - 64.0f;
	//}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
	else if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}


	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	
	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_px + 15, m_py + 20);//���������V�����ʒu�i��l���̈ʒu�j���ɒu��������

	//�G�@�I�u�W�F�N�g�ƐڐG�������l���@�폜
	if (hit->CheckObjNameHit(OBJ_ENEMY) !=nullptr)
	{
    	this->SetStatus(false);    //���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);  //��l���@�����L����HitBox�ɍ폜����
    	Scene::SetScene(new CSceneGameOver());
	}
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
		dst.m_left = 0.0f + m_px;
		dst.m_right = 64.0f + m_px;
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
		dst.m_left = 0.0f + m_px;
		dst.m_right = 64.0f + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//w�i��j�����͂��ꂽ�Ƃ�
	else if (m_posture == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 192.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 256.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 64.0f + m_px;
		dst.m_bottom = 64.0f + m_py;
	}



	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}
