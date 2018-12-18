#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "TextALL.h"
#include "SwitchALL.h"

CObjTextALL::CObjTextALL(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjTextALL::Init()
{

}

void CObjTextALL::Action()
{
	if (Text != 0 && Input::GetVKey(VK_BACK) == true)
		Text = 0;
}

void CObjTextALL::Draw()
{
	float c[4] = { 0.0f,0.0f,1.0f,0.5f };
	float c2[4] = { 1.0f,1.0f,1.0f,1.0f };
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

	if (Text == 0)
		;
	else if (Text != 0)
	{
		Draw::Draw(2, &src, &dst, c, 0.0f);
		if (Text == 1)
		{
			Font::StrDraw(L"�}���ψ��̐l��", m_x + 16, m_y + 16, 32, c2);
			Font::StrDraw(L"�}�����̖{���U�炩���Ă��܂��B", m_x+16, m_y+64, 32, c2);
			Font::StrDraw(L"�Еt���Ă��������B", m_x + 16, m_y + 96, 32, c2);
		}
		else if (Text == 2)
		{
			;
		}
		else if (Text == 3)
		{
			;
		}
	}

}