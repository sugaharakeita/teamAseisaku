#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "Message.h"
#include "SwitchALL.h"

CObjMessage::CObjMessage(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjMessage::Init()
{
	
}

void CObjMessage::Action()
{
	if (Message != 0 && Input::GetVKey(VK_BACK) == true)
		Message = 0;//�\���������B
}

void CObjMessage::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c2[4] = { 0,0,0,1 };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 600.0f;
	src.m_bottom = 160.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 784.0f + m_x;
	dst.m_bottom = 128.0f + m_y;

	if (Message == 0)
		;//�O�̎��͕\�����Ȃ��B
	else if (Message == 1)
	{
		Draw::Draw(0, &src, &dst, c, 0.0f);
		Font::StrDraw(L"�J�M���������Ă���c", m_x+16, m_y+16, 32, c2);
		Font::StrDraw(L"��", 760, 560, 16, c2);
	}
	else if (Message == 2)
	{
		Draw::Draw(0, &src, &dst, c, 0.0f);
		Font::StrDraw(L"�Z�����̃J�M����ɓ��ꂽ", m_x + 16, m_y + 16, 32, c2);
		Font::StrDraw(L"��", 760, 560, 16, c2);
	}
	else if (Message == 3)
	{
		Draw::Draw(0, &src, &dst, c, 0.0f);
		Font::StrDraw(L"�Z�����̃J�M���J����", m_x + 16, m_y + 16, 32, c2);
		Font::StrDraw(L"��", 760, 560, 16, c2);
	}
	else if (Message == 4)
	{
		Draw::Draw(0, &src, &dst, c, 0.0f);
		Font::StrDraw(L"�ی����̃J�M����ɓ��ꂽ", m_x + 16, m_y + 16, 32, c2);
		Font::StrDraw(L"��", 760, 560, 16, c2);
	}
	else if (Message == 5)
	{
		Draw::Draw(0, &src, &dst, c, 0.0f);
		Font::StrDraw(L"�ی����̃J�M���J����", m_x + 16, m_y + 16, 32, c2);
		Font::StrDraw(L"��", 760, 560, 16, c2);
	}
	else if (Message == 6)
	{
		Draw::Draw(0, &src, &dst, c, 0.0f);
		Font::StrDraw(L"�n���}�[����ɓ��ꂽ", m_x + 16, m_y + 16, 32, c2);
		Font::StrDraw(L"��", 760, 560, 16, c2);
	}

}