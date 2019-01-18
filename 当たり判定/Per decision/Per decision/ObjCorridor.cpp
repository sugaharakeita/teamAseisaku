#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "ObjCorridor.h"
#include "GameHead.h"

using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//�C�j�V�����C�Y
void CObjCorridor::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//�G���A�ړ��t���O������
	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = true;
	m_flag_Corridor1_3 = false;
	m_flag_Staffroom = false;
	m_flag_Principaloffice = false;
	m_flag_Infirmary = false;
	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;
	m_flag_Classroom = false;
	m_flag_Library = false;
	m_flag_Homeeconomicsroom = false;
	m_flag_Homepreparationroom = false;
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;
	m_flag_Computerroom = false;
	m_flag_Musicroom = false;
	m_flag_Conferenceroom = false;
	m_flag_Rooftop = false;


	//�K������
	m_Storey1 = true;
	m_Storey2 = false;
	m_Storey3 = false;
	m_Storey4 = false;
}

//�A�N�V����
void CObjCorridor::Action()
{

	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//1�K
	//�L��	
	if (hx < 0.0f && m_Storey1 == true)
	{
		//1-2����1-1
		if (m_flag_Corridor1_2 == true)
		{
			m_flag_Corridor1_1 = true;
			m_flag_Corridor1_2 = false;
			m_flag_Corridor1_3 = false;
		}
		//1-3����1-2
		if (m_flag_Corridor1_3 == true)
		{
			m_flag_Corridor1_1 = false;
			m_flag_Corridor1_2 = true;
			m_flag_Corridor1_3 = false;
		}
		m_Storey1 = true;
	}
	if (hx + 64.0f  > 800.0f && m_Storey1 == true)
	{
		//1-1����1-2
		if (m_flag_Corridor1_1 == true)
		{
			m_flag_Corridor1_1 = false;	
			m_flag_Corridor1_2 = true;
			m_flag_Corridor1_3 = false;
		}
		//1-2����1-3
		if (m_flag_Corridor1_2 == true)
		{
			m_flag_Corridor1_1 = false;
			m_flag_Corridor1_2 = false;
			m_flag_Corridor1_3 = true;
		}
		m_Storey1 = true;
	}


	//2�K��
	if (hy < 0.0f  && m_flag_Corridor1_2 == true
		 && m_Storey1 == true && Input::GetVKey(VK_RETURN) == true
		)
	{
		m_flag_Corridor1_2 = false;
		m_flag_Corridor2_2 = true;
		m_Storey1 = false;
		m_Storey2 = true;
	}


	//�E����
	if (hy > 450.0f  && m_flag_Corridor1_1 == true 
		&& m_Storey1 == true)
	{
		m_flag_Corridor1_1 = false;
		m_flag_Staffroom = true;
		m_Storey1 = true;
	}

	if (hy < 50.0f && (hx < 100.0f && hx + 64.0f > 0.0f || 
		hx < 800.0f && hx + 64.0f > 700.0f && m_Storey1 == true)
		&& m_flag_Staffroom == true )
	{
		m_flag_Staffroom = false;
		m_flag_Corridor1_1 = true;
		m_Storey1 = true;
	}

	//�Z����
	if (hy < 120 && m_flag_Corridor1_1 == true 
		&& m_Storey1 == true)
	{
		m_flag_Corridor1_1 = false;
		m_flag_Principaloffice = true;
		m_Storey1 = true;
	}
	
	if (hy + 64.0f > 600.0f && m_flag_Principaloffice == true 
		&& m_Storey1 == true)
	{
		m_flag_Principaloffice = false;
		m_flag_Corridor1_1 = true;
		m_Storey1 = true;
	}

	//�ی���
	if(hy < 120 && m_flag_Corridor1_3 == true && m_Storey1 == true)
	{
		m_flag_Corridor1_3 = false;
		m_flag_Infirmary = true;
		m_Storey1 = true;
	}

	if (hy + 64.0f > 600.0f && m_flag_Infirmary == true 
		&& m_Storey1 == true)
	{
		m_flag_Infirmary = false;
		m_flag_Corridor1_3 = true;
		m_Storey1 = true;
	}


	//2�K
	//�L��
	if (hx < 0.0f && m_Storey2 == true)
	{
		//2-2����2-1
		if (m_flag_Corridor2_2 == true)
		{
			m_flag_Corridor2_1 = true;
			m_flag_Corridor2_2 = false;
			m_flag_Corridor2_3 = false;
		}
		//2-3����2-2
		if (m_flag_Corridor2_3 == true)
		{
			m_flag_Corridor2_1 = false;
			m_flag_Corridor2_2 = true;
			m_flag_Corridor2_3 = false;
		}
		m_Storey2 = true;
	}
	if (hx + 64.0f  > 800.0f && m_Storey2 == true)
	{
		//2-1����2-2
		if (m_flag_Corridor2_1 == true)
		{
			m_flag_Corridor2_1 = false;
			m_flag_Corridor2_2 = true;
			m_flag_Corridor2_3 = false;
		}
		//2-2����2-3
		if (m_flag_Corridor2_2 == true)
		{
			m_flag_Corridor2_1 = false;
			m_flag_Corridor2_2 = false;
			m_flag_Corridor2_3 = true;
		}
		m_Storey2 = true;
	}

	//����
	if (hy > 500.0f  && m_flag_Corridor2_3 == true 
		&& m_Storey2 == true)
	{
		m_flag_Corridor2_3 = false;
		m_flag_Classroom = true;
		m_Storey2 = true;
	}

	if (hy < 50.0f && m_flag_Classroom == true 
		&& m_Storey2 == true)
	{
		m_flag_Classroom = false;
		m_flag_Corridor2_3 = true;
		m_Storey2 = true;
	}

	//�}����
	if (hy < 120 && m_flag_Corridor2_1 == true && m_Storey2 == true)
	{
		m_flag_Corridor2_1 = false;
		m_flag_Library = true;
		m_Storey2 = true;
	}

	if (hy + 64.0f > 600.0f && m_flag_Library == true 
		&& m_Storey2 == true)
	{
		m_flag_Library = false;
		m_flag_Corridor2_1 = true;
		m_Storey2 = true;
	}

	//�ƒ�Ȏ�
	if (hy > 450.0f && hx < 300.0 && m_flag_Corridor2_1 == true 
		&& m_Storey2 == true)
	{
		m_flag_Corridor2_1 = false;
		m_flag_Homeeconomicsroom = true;
		m_Storey2 = true;
	}

	if (hy < 50.0f && m_flag_Homeeconomicsroom == true
		 && m_Storey2 == true)
	{
		m_flag_Homeeconomicsroom = false;
		m_flag_Corridor2_1 = true;
		m_Storey2 = true;
	}

	//�ƒ돀�������ƒ�Ȏ�
	if (hx < 0.0f && m_flag_Homepreparationroom == true
		&& m_Storey2 == true)
	{
		m_flag_Homeeconomicsroom = true;
		m_flag_Homepreparationroom = false;
		m_Storey2 = true;
	}


	//�ƒ돀����
	if (hy > 450.0f && hx + 64.0f > 400.0f && m_Storey2 == true
		&& m_flag_Corridor2_1 == true)
	{
		m_flag_Homepreparationroom = true;
		m_flag_Corridor2_1 = false;
		m_Storey2 = true;
	}

	if (hy < 50.0f  && m_Storey2 == true
		&& m_flag_Homepreparationroom == true)
	{
		m_flag_Corridor2_1 = true;
		m_flag_Homepreparationroom = false;
		m_Storey2 = true;
	}
	//�ƒ�Ȏ����ƒ돀����
	if (hx + 64.0f > 800.0f&& m_Storey2 == true
		&& m_flag_Homeeconomicsroom == true)
	{
		m_flag_Homepreparationroom = true;
		m_flag_Homeeconomicsroom = false;
		m_Storey2 = true;
	}


	//3�K��
	if (hy < 0.0f  && m_flag_Corridor2_2 == true 
		&& m_Storey2 == true && Input::GetVKey(VK_RETURN) == true)
	{
		m_flag_Corridor2_2 = false;
		m_flag_Corridor3_2 = true;
		m_Storey2 = false;
		m_Storey3 = true;
	}


	//3�K
	//�L��
	if (hx < 0.0f && m_Storey3 == true)
	{
		m_Storey3 = true;
		//3-2����3-1
		if (m_flag_Corridor3_2 == true)
		{
			m_flag_Corridor3_1 = true;
			m_flag_Corridor3_2 = false;
			m_flag_Corridor3_3 = false;
		}
		//3-3����3-2
		if (m_flag_Corridor3_3 == true)
		{
			m_flag_Corridor3_1 = false;
			m_flag_Corridor3_2 = true;
			m_flag_Corridor3_3 = false;
		}
	}

	if (hx + 64.0f > 800.0f && m_Storey3 == true)
	{
		m_Storey3 = true;
		//3-1����3-2
		if (m_flag_Corridor3_1 == true)
		{
			m_flag_Corridor3_1 = false;
			m_flag_Corridor3_2 = true;
			m_flag_Corridor3_3 = false;
		}
		//3-2����3-3
		if (m_flag_Corridor3_2 == true)
		{
			m_flag_Corridor3_1 = false;
			m_flag_Corridor3_2 = false;
			m_flag_Corridor3_3 = true;
		}
	}

	//PC��
	if (hy > 450.0f && m_flag_Corridor3_3 == true 
		&& m_Storey3 == true)
	{
		m_flag_Computerroom = true;
		m_flag_Corridor3_3 = false;
		m_Storey3 = true;
	}

	if (hy < 50.0f  && m_flag_Computerroom == true 
		&& m_Storey3 == true)
	{
		m_flag_Corridor3_3 = true;
		m_flag_Computerroom = false;
		m_Storey3 = true;
	}


	//���y��
	if (hy < 120.0f && m_flag_Corridor3_1 == true 
		&& m_Storey3 == true)
	{
		m_flag_Musicroom = true;
		m_flag_Corridor3_1 = false;
		m_Storey3 = true;
	}

	if (hy + 64.0f > 600.0f&& m_flag_Musicroom == true 
		&& m_Storey3 == true)
	{
		m_flag_Corridor3_1 = true;
		m_flag_Musicroom = false;
		m_Storey3 = true;
	}


	//��c��
	//�L��3-1��ʉ��ɍs���Ɖ�c���ֈړ�
	if (hy > 450.0f && m_flag_Corridor3_1 == true 
		&& m_Storey3 == true)
	{
		m_flag_Conferenceroom = true;
		m_flag_Corridor3_1 = false;
		m_Storey3 = true;
	}

	//��c����ʏ�ɍs���ƘL��3-1�ֈړ�
	if (hy < 50.0f  && m_flag_Conferenceroom == true 
		&& m_Storey3 == true)
	{
		m_flag_Corridor3_1 = true;
		m_flag_Conferenceroom = false;
		m_Storey3 = true;
	}

	//�����
	if (hy < 0.0f && m_flag_Corridor3_2 == true 
		&& m_Storey3 == true && Input::GetVKey(VK_RETURN) == true)
	{
		m_flag_Rooftop = true;
		m_flag_Corridor3_2 = false;
		m_Storey3 = false;
		m_Storey4 = true;
	}

}

//�h���[
void CObjCorridor::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//1�K
	if (m_flag_Corridor1_1 == true && m_Storey1 == true)
	{
		//�w�i
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 519.0f;
		src.m_bottom = 360.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	if (m_flag_Corridor1_2 == true && m_Storey1 == true)
	{
		//�w�i
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 380.0f;
		src.m_bottom = 360.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	if (m_flag_Corridor1_3 == true && m_Storey1 == true)
	{
		//�w�i
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 360.0f;
		src.m_bottom = 360.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	//�E����
	if (m_flag_Staffroom == true && m_Storey1 == true)
	{
		//�w�i
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 896.0f;
		src.m_bottom = 640.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	//�Z����
	if (m_flag_Principaloffice == true && m_Storey1 == true)
	{
		//�w�i
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 470.0f;
		src.m_bottom = 730.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	//�ی���
	if (m_flag_Infirmary == true && m_Storey1 == true)
	{
		//�w�i
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 720.0f;
		src.m_bottom = 370.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	//2�K
	if (m_flag_Corridor2_1 == true && m_Storey2 == true)
	{
		//�w�i
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1030.0f;
		src.m_bottom = 360.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	if (m_flag_Corridor2_2 == true && m_Storey2 == true)
	{
		//�w�i
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 380.0f;
		src.m_bottom = 360.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	if (m_flag_Corridor2_3 == true && m_Storey2 == true)
	{
		//�w�i
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 360.0f;
		src.m_bottom = 360.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	//����
	if (m_flag_Classroom == true && m_Storey2 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 660.0f;
		src.m_bottom = 442.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//�}����
	if (m_flag_Library == true && m_Storey2 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 852.0f;
		src.m_bottom = 506.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//�ƒ�Ȏ�
	if (m_flag_Homeeconomicsroom == true && m_Storey2 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 852.0f;
		src.m_bottom = 506.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}	

	//�ƒ돀����
	if (m_flag_Homepreparationroom == true && m_Storey2 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 404.0f;
		src.m_bottom = 506.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//3�K
	if (m_flag_Corridor3_1 == true && m_Storey3 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 1035.0f;
		src.m_bottom = 362.0f;

		////�w�i�P�̈ʒu�̐ݒ�����`��
		//dst.m_top = 0.0f;
		//dst.m_left = 0.0f + m_x1;
		//dst.m_right = 1716.0f + m_x1;
		//dst.m_bottom = 600.0f;
		//Draw::Draw(0, &src, &dst, c, 0.0f);


		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				//�w�i�P�̈ʒu�̐ݒ�����`��
				dst.m_top = 0.0f;
				dst.m_left = 0.0f + m_scroll;
				dst.m_right = 1716.0f + m_scroll;
				dst.m_bottom = 600.0f;
				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

	if (m_flag_Corridor3_2 == true && m_Storey3 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 384.0f;
		src.m_bottom = 362.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);

	}

	if (m_flag_Corridor3_3 == true && m_Storey3 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 360.0f;
		src.m_bottom = 362.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//PC��
	if (m_flag_Computerroom = true && m_Storey3 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 788.0f;
		src.m_bottom = 698.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//���y��
	if (m_flag_Musicroom == true && m_Storey3 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 788.0f;
		src.m_bottom = 722.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//��c��
	if (m_flag_Conferenceroom == true && m_Storey3 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 788.0f;
		src.m_bottom = 730.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);

	}

	//����
	if (m_flag_Rooftop == true && m_Storey4 == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 852.0f;
		src.m_bottom = 506.0f;

		//�w�i�P�̈ʒu�̐ݒ�����`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
}