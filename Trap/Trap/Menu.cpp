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
		Menu = 0;
	if (Menu == 1)
	{
		if (Input::GetVKey(VK_UP) == true)
			;//メニュー行動の選択
		if (/* && */Input::GetVKey(VK_RETURN) == true)
		{
			Menu = 2;//アイテムコマンドを選んでいた場合
		}
	}
}

void CObjMenu::Draw()
{
	float c[4] = { 0.0f,0.0f,1.0f,0.5f };
	float c2[4] = { 1,1,1,1 };
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
		Font::StrDraw(L"アイテム", m_x + 16, m_y + 16, 32, c2);
		Font::StrDraw(L"セーブ", m_x + 16, m_y + 64, 32, c2);
		
	}
}