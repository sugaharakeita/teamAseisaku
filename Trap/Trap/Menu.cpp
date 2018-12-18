#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "Menu.h"
#include "SwitchALL.h"

CObjMenu::CObjMenu(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjMenu::Init()
{

}

void CObjMenu::Action()
{
	if (Menu != 0 && Input::GetVKey(VK_BACK) == true)
		Menu--;
	if (Menu == 1)
	{
		/*if (Input::GetVKey('W') == true)
			;
		else if (Input::GetVKey('S') == true)
			;メニュー行動の選択*/
		if (/* && */Input::GetVKey(VK_RETURN) == true)
		{
			Menu = 2;//アイテムコマンドを選んでいた場合
		}
	}
}

void CObjMenu::Draw()
{
	float c[4] = { 0.0f,0.0f,1.0f,0.5f };
	float c2[4] = { 0.45f,0.45f,0.45f,1.0f };
	float c3[4] = { 1.0f,1.0f,1.0f,0.8f };
	float c4[4] = { 1.0f,0.5f,0.5f,0.8f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 338.0f;
	src.m_left = 223.0f;
	src.m_right = 224.0f;
	src.m_bottom = 339.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 800.0f + m_x;
	dst.m_bottom = 600.0f + m_y;

	if (Menu != 0)
		Draw::Draw(2, &src, &dst, c, 0.0f);
	if (Menu == 1)
	{
		Font::StrDraw(L"アイテム", m_x + 16, m_y + 16, 32, c3);
		Font::StrDraw(L"セーブ", m_x + 16, m_y + 64, 32, c3);
		
	}
	if (Menu == 2)
	{
		if (HokenKey == 1)
		{
			src.m_top = 0.0f;
			src.m_left = 13.0f;
			src.m_right = 23.0f;
			src.m_bottom = 13.0f;

			dst.m_top = 0.0f + m_y;
			dst.m_left = 0.0f + m_x;
			dst.m_right = 40.0f + m_x;
			dst.m_bottom = 52.0f + m_y;

			if(Hok_flag == true)
				Draw::Draw(3, &src, &dst, c2, 0.0f);
			else
				Draw::Draw(3, &src, &dst, c3, 0.0f);
		}
		if (KouchouKey == 1)
		{
			src.m_top = 0.0f;
			src.m_left = 13.0f;
			src.m_right = 23.0f;
			src.m_bottom = 13.0f;

			dst.m_top = 0.0f + m_y;
			dst.m_left = 0.0f + 60;
			dst.m_right = 40.0f + 60;
			dst.m_bottom = 52.0f + m_y;

			if (Kou_flag == true)
				Draw::Draw(3, &src, &dst, c2, 0.0f);
			else
				Draw::Draw(3, &src, &dst, c4, 0.0f);
		}
		if (Hammer == 1)
		{
			src.m_top = 0.0f;
			src.m_left = 188.0f;
			src.m_right = 203.0f;
			src.m_bottom = 15.0f;

			dst.m_top = 0.0f + m_y;
			dst.m_left = 0.0f + 120;
			dst.m_right = 52.0f + 120;
			dst.m_bottom = 52.0f + m_y;

			if (Ham_flag == true)
				Draw::Draw(3, &src, &dst, c2, 0.0f);
			else
				Draw::Draw(3, &src, &dst, c3, 0.0f);
		}

	}
}