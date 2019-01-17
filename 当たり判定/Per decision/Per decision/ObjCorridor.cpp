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

//イニシャライズ
void CObjCorridor::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//エリア移動フラグ初期化
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
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;

	m_Storey = 1;
}

//アクション
void CObjCorridor::Action()
{

	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//1階
	//廊下	
	if (hx < 0.0f && m_Storey == 1)
	{
		//1-2から1-1
		if (m_flag_Corridor1_2 == true)
		{
			m_flag_Corridor1_1 = true;
			m_flag_Corridor1_2 = false;
			m_flag_Corridor1_3 = false;
		}
		//1-3から1-2
		if (m_flag_Corridor1_3 == true)
		{
			m_flag_Corridor1_1 = false;
			m_flag_Corridor1_2 = true;
			m_flag_Corridor1_3 = false;
		}
		m_Storey = 1;
	}
	if (hx + 64.0f  > 800.0f && m_Storey == 1)
	{
		//1-1から1-2
		if (m_flag_Corridor1_1 == true)
		{
			m_flag_Corridor1_1 = false;	
			m_flag_Corridor1_2 = true;
			m_flag_Corridor1_3 = false;
		}
		//1-2から1-3
		if (m_flag_Corridor1_2 == true)
		{
			m_flag_Corridor1_1 = false;
			m_flag_Corridor1_2 = false;
			m_flag_Corridor1_3 = true;
		}
		m_Storey = 1;
	}


	//2階へ
	if (hy < 0.0f  && m_flag_Corridor1_2 == true
		 && m_Storey == 1)
	{
		m_flag_Corridor1_2 = false;
		m_flag_Corridor2_2 = true;
		m_Storey = 2;
	}


	//職員室
	if (hy > 450.0f  && m_flag_Corridor1_1 == true && m_Storey == 1)
	{
		m_flag_Corridor1_1 = false;
		m_flag_Staffroom = true;
		m_Storey = 1;
	}

	if (hy < 50.0f && (hx < 100.0f && hx + 64.0f > 0.0f || 
		hx < 800.0f && hx + 64.0f > 700.0f) 
		&& m_flag_Staffroom == true && m_Storey == 1)
	{
		m_flag_Staffroom = false;
		m_flag_Corridor1_1 = true;
		m_Storey = 1;
	}

	//校長室
	if (hy < 120 && m_flag_Corridor1_1 == true && m_Storey == 1)
	{
		m_flag_Corridor1_1 = false;
		m_flag_Principaloffice = true;
		m_Storey = 1;
	}
	
	if (hy + 64.0f > 600.0f && m_flag_Principaloffice == true && m_Storey == 1)
	{
		m_flag_Principaloffice = false;
		m_flag_Corridor1_1 = true;
		m_Storey = 1;
	}

	//保健室
	if(hy < 120 && m_flag_Corridor1_3 == true && m_Storey == 1)
	{
		m_flag_Corridor1_3 = false;
		m_flag_Infirmary = true;
		m_Storey = 1;
	}

	if (hy + 64.0f > 600.0f && m_flag_Infirmary == true && m_Storey == 1)
	{
		m_flag_Infirmary = false;
		m_flag_Corridor1_3 = true;
		m_Storey = 1;
	}


	//2階
	//廊下
	if (hx < 0.0f && m_Storey == 2)
	{
		//2-2から2-1
		if (m_flag_Corridor2_2 == true)
		{
			m_flag_Corridor2_1 = true;
			m_flag_Corridor2_2 = false;
			m_flag_Corridor2_3 = false;
		}
		//2-3から2-2
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
		//2-1から2-2
		if (m_flag_Corridor2_1 == true)
		{
			m_flag_Corridor2_1 = false;
			m_flag_Corridor2_2 = true;
			m_flag_Corridor2_3 = false;
		}
		//2-2から2-3
		if (m_flag_Corridor2_2 == true)
		{
			m_flag_Corridor2_1 = false;
			m_flag_Corridor2_2 = false;
			m_flag_Corridor2_3 = true;
		}
		m_Storey = 2;
	}

	//教室
	if (hy > 500.0f  && m_flag_Corridor2_1 == true && m_Storey == 2)
	{
		m_flag_Corridor2_1 = false;
		m_flag_Classroom = true;
		m_Storey = 2;
	}

	if (hy < 50.0f && (hx < 100.0f && hx + 64.0f > 0.0f ||
		hx < 800.0f && hx + 64.0f > 700.0f)
		&& m_flag_Classroom == true && m_Storey == 2)
	{
		m_flag_Classroom = false;
		m_flag_Corridor2_1 = true;
		m_Storey = 2;
	}

	//図書館
	if (hy < 120 && m_flag_Corridor2_1 == true && m_Storey == 2)
	{
		m_flag_Corridor2_1 = false;
		m_flag_Library = true;
		m_Storey = 2;
	}

	if (hy + 64.0f > 600.0f && m_flag_Library == true 
		&& m_Storey == 2)
	{
		m_flag_Library = false;
		m_flag_Corridor2_1 = true;
		m_Storey = 2;
	}


	//3階へ
	if (hy < 0.0f  && m_flag_Corridor2_2 == true && m_Storey == 2)
	{
		m_flag_Corridor2_2 = false;
		m_flag_Corridor3_2 = true;
		m_Storey = 3;
	}


	//3階
	//廊下
	if (hx < 0.0f && m_Storey == 3)
	{
		//3-2から3-1
		if (m_flag_Corridor3_2 == true)
		{
			m_flag_Corridor3_1 = true;
			m_flag_Corridor3_2 = false;
		}
		//3-3から3-2
		if (m_flag_Corridor3_3 == true)
		{
			m_flag_Corridor3_2 = true;
			m_flag_Corridor3_3 = false;
		}
	}

	if (hx + 64.0f > 800.0f && m_Storey == 3)
	{
		//3-1から3-2
		if (m_flag_Corridor3_1 == true)
		{
			m_flag_Corridor3_1 = false;
			m_flag_Corridor3_2 = true;
		}
		//3-2から3-3
		if (m_flag_Corridor3_2 == true)
		{
			m_flag_Corridor3_2 = false;
			m_flag_Corridor3_3 = true;
		}
	}

}

//ドロー
void CObjCorridor::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//1階
	if (m_flag_Corridor1_1 == true)
	{
		//背景
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
		//背景
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
		//背景
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

	//職員室
	if (m_flag_Staffroom == true)
	{
		//背景
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

	//校長室
	if (m_flag_Principaloffice == true)
	{
		//背景
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

	//保健室
	if (m_flag_Infirmary == true)
	{
		//背景
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

	//2階
	if (m_flag_Corridor2_1 == true)
	{
		//背景
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
		//背景
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
		//背景
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

	//教室
	if (m_flag_Classroom == true)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 660.0f;
		src.m_bottom = 442.0f;

		//背景１の位置の設定をし描画
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//図書館
	if (m_flag_Library == true)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 852.0f;
		src.m_bottom = 506.0f;

		//背景１の位置の設定をし描画
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//3階
	if (m_flag_Corridor3_1 == true)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 1035.0f;
		src.m_bottom = 362.0f;

		////背景１の位置の設定をし描画
		//dst.m_top = 0.0f;
		//dst.m_left = 0.0f + m_x1;
		//dst.m_right = 1716.0f + m_x1;
		//dst.m_bottom = 600.0f;
		//Draw::Draw(0, &src, &dst, c, 0.0f);


		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				//背景１の位置の設定をし描画
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
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 384.0f;
		src.m_bottom = 362.0f;

		//背景１の位置の設定をし描画
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);

	}

	if (m_flag_Corridor3_3 == true)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 360.0f;
		src.m_bottom = 362.0f;

		//背景１の位置の設定をし描画
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
}