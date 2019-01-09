#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "ObjCorridor1.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjCorridor1::Init()
{

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
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;

	m_Storey = 0;
}

//�A�N�V����
void CObjCorridor1::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//1�K
	if (hx < 0.0f && m_flag_Corridor1_2 == true)
	{
		m_flag_Corridor1_1 = true;
		m_flag_Corridor1_2 = false;
	}

	if (hx + 64.0f > 800.0f && m_flag_Corridor1_1 == true)
	{
		m_flag_Corridor1_1 = false;
		m_flag_Corridor1_2 = true;
	}

	if (hx + 64.0f > 800.0f && m_flag_Corridor1_2 == true)
	{
		m_flag_Corridor1_2 = false;
		m_flag_Corridor1_3 = true;
	}

	if (hx < 0.0f&& m_flag_Corridor1_3 == true)
	{
		m_flag_Corridor1_2 = true;
		m_flag_Corridor1_3 = false;
	}

	//�E����
	if (hy > 450.0f && m_flag_Corridor1_1 == true)
	{
		m_flag_Corridor1_1 = false;
		m_flag_Staffroom = true;
	}

	if (hy < 70.0f && m_flag_Staffroom == true)
	{
		m_flag_Staffroom = false;
		m_flag_Corridor1_1 = true;
	}

	//�Z����
	if (hy < 120 && m_flag_Corridor1_1 == true)
	{
		m_flag_Corridor1_1 = false;
		m_flag_Principaloffice = true;
	}
	
	if (hy + 64.0f > 600.0f && m_flag_Principaloffice == true)
	{
		m_flag_Principaloffice = false;
		m_flag_Corridor1_1 = true;
	}

	//�ی���
	if(hy < 120 && m_flag_Corridor1_3 == true)
	{
		m_flag_Corridor1_3 = false;
		m_flag_Infirmary = true;
	}

	if (hy + 64.0f > 600.0f && m_flag_Infirmary == true)
	{
		m_flag_Infirmary = false;
		m_flag_Corridor1_3 = true;
	}


	//2�K


	//3�K
}

//�h���[
void CObjCorridor1::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//1�K
	if (m_flag_Corridor1_1 == true)
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

	if (m_flag_Corridor1_2 == true)
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

	if (m_flag_Corridor1_3 == true)
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
	if (m_flag_Staffroom == true)
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
	if (m_flag_Principaloffice == true)
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
	if (m_flag_Infirmary == true)
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
	if (m_flag_Corridor2_1 == true)
	{

	}

	if (m_flag_Corridor2_2 == true)
	{

	}

	if (m_flag_Corridor2_3 == true)
	{

	}

	//3�K
	if (m_flag_Corridor3_1 == true)
	{

	}

	if (m_flag_Corridor3_2 == true)
	{

	}

	if (m_flag_Corridor3_3 == true)
	{

	}
}