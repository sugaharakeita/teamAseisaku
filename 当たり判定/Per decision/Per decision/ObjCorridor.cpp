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

//ÉCÉjÉVÉÉÉâÉCÉY
void CObjCorridor::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//ÉGÉäÉAà⁄ìÆÉtÉâÉOèâä˙âª
	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = true;
	m_flag_Corridor1_3 = false;
	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;
	m_flag_Rooftop = false;


	//äKêîï™ÇØ
	m_Storey = 1;
}

//ÉAÉNÉVÉáÉì
void CObjCorridor::Action()
{

	//éÂêlåˆÇÃà íuÇéÊìæ
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//2äK
	//òLâ∫
	if (hx < 0.0f && m_Storey == 2)
	{
		//2-2Ç©ÇÁ2-1
		if (m_flag_Corridor2_2 == true)
		{
			m_flag_Corridor2_1 = true;
			m_flag_Corridor2_2 = false;
			m_flag_Corridor2_3 = false;
		}
		//2-3Ç©ÇÁ2-2
		if (m_flag_Corridor2_3 == true)
		{
			m_flag_Corridor2_1 = false;
			m_flag_Corridor2_2 = true;
			m_flag_Corridor2_3 = false;
		}
		m_Storey = 2;
	}
	if (hx + 64.0f  > 800.0f && m_Storey == 2)
	{
		//2-1Ç©ÇÁ2-2
		if (m_flag_Corridor2_1 == true)
		{
			m_flag_Corridor2_1 = false;
			m_flag_Corridor2_2 = true;
			m_flag_Corridor2_3 = false;
		}
		//2-2Ç©ÇÁ2-3
		if (m_flag_Corridor2_2 == true)
		{
			m_flag_Corridor2_1 = false;
			m_flag_Corridor2_2 = false;
			m_flag_Corridor2_3 = true;
		}
		m_Storey = 2;
	}


	//3äKÇ÷
	if (hy < 0.0f  && m_flag_Corridor2_2 == true 
		&& m_Storey == 2 && Input::GetVKey(VK_RETURN) == true)
	{
		m_flag_Corridor2_2 = false;
		m_flag_Corridor3_2 = true;
		m_Storey = 3;
	}


	//3äK
	//òLâ∫
	if (hx < 0.0f && m_Storey == 3)
	{
		m_Storey = 3;
		//3-2Ç©ÇÁ3-1
		if (m_flag_Corridor3_2 == true)
		{
			m_flag_Corridor3_1 = true;
			m_flag_Corridor3_2 = false;
			m_flag_Corridor3_3 = false;
		}
		//3-3Ç©ÇÁ3-2
		if (m_flag_Corridor3_3 == true)
		{
			m_flag_Corridor3_1 = false;
			m_flag_Corridor3_2 = true;
			m_flag_Corridor3_3 = false;
		}
	}

	if (hx + 64.0f > 800.0f && m_Storey == 3)
	{
		m_Storey = 3;
		//3-1Ç©ÇÁ3-2
		if (m_flag_Corridor3_1 == true)
		{
			m_flag_Corridor3_1 = false;
			m_flag_Corridor3_2 = true;
			m_flag_Corridor3_3 = false;
		}
		//3-2Ç©ÇÁ3-3
		if (m_flag_Corridor3_2 == true)
		{
			m_flag_Corridor3_1 = false;
			m_flag_Corridor3_2 = false;
			m_flag_Corridor3_3 = true;
		}
	}


	//âÆè„Ç÷
	if (hy < 0.0f && m_flag_Corridor3_2 == true 
		&& m_Storey == 3 && Input::GetVKey(VK_RETURN) == true)
	{
		m_flag_Rooftop = true;
		m_flag_Corridor3_2 = false;
		m_Storey = 4;
	}

}

//ÉhÉçÅ[
void CObjCorridor::Draw()
{
	//ï`âÊÉJÉâÅ[èÓïÒ
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//1äK
	if (m_flag_Corridor1_1 == true)
	{
		//îwåi
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
		//îwåi
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
		//îwåi
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


	//2äK
	if (m_flag_Corridor2_1 == true)
	{
		//îwåi
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

	if (m_flag_Corridor2_2 == true)
	{
		//îwåi
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

	if (m_flag_Corridor2_3 == true)
	{
		//îwåi
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


	//3äK
	if (m_flag_Corridor3_1 == true)
	{
		//êÿÇËéÊÇËà íuÇÃê›íË
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 1035.0f;
		src.m_bottom = 362.0f;

		////îwåiÇPÇÃà íuÇÃê›íËÇÇµï`âÊ
		//dst.m_top = 0.0f;
		//dst.m_left = 0.0f + m_x1;
		//dst.m_right = 1716.0f + m_x1;
		//dst.m_bottom = 600.0f;
		//Draw::Draw(0, &src, &dst, c, 0.0f);


		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				//îwåiÇPÇÃà íuÇÃê›íËÇÇµï`âÊ
				dst.m_top = 0.0f;
				dst.m_left = 0.0f + m_scroll;
				dst.m_right = 1716.0f + m_scroll;
				dst.m_bottom = 600.0f;
				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

	if (m_flag_Corridor3_2 == true)
	{
		//êÿÇËéÊÇËà íuÇÃê›íË
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 384.0f;
		src.m_bottom = 362.0f;

		//îwåiÇPÇÃà íuÇÃê›íËÇÇµï`âÊ
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);

	}

	if (m_flag_Corridor3_3 == true)
	{
		//êÿÇËéÊÇËà íuÇÃê›íË
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 360.0f;
		src.m_bottom = 362.0f;

		//îwåiÇPÇÃà íuÇÃê›íËÇÇµï`âÊ
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}


	//âÆè„
	if (m_flag_Rooftop == true)
	{
		//êÿÇËéÊÇËà íuÇÃê›íË
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 852.0f;
		src.m_bottom = 506.0f;

		//îwåiÇPÇÃà íuÇÃê›íËÇÇµï`âÊ
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
}