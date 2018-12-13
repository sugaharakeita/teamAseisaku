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
	float c2[4] = { 1.0f,0.2f,0.2f,1.0f };
	float c3[4] = { 0,0,0,1 };
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

	if (Text != 0 || Menu != 0)
		;
	else
	{
		if (room[0] == 1 || room[1] == 1 || room[2] == 1 || room[3] == 1)
			Font::StrDraw(L"�P�K�L��", 10, 16, 32, c2);
		else if (room[4] == 1)
			Font::StrDraw(L"�Z����", 10, 16, 32, c2);
		else if (room[5] == 1)
			Font::StrDraw(L"�E����", 10, 16, 32, c2);
		else if (room[6] == 1)
			Font::StrDraw(L"�ی���", 10, 16, 32, c2);
		else if(room[7] == 1 || room[8] == 1 || room[9] == 1)
			Font::StrDraw(L"�Q�K�L��", 10, 16, 32, c2);
		else if (room[10] == 1)
			Font::StrDraw(L"�ƒ�Ȏ�", 10, 16, 32, c2);
	}
	if (Message == 0)
		;//0�̎��͕\�����Ȃ��B
	else if (Message != 0)
	{
		Draw::Draw(0, &src, &dst, c, 0.0f);
		if (Message == 1)
		{
			Font::StrDraw(L"�J�M���������Ă���c", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 2)
		{
			Font::StrDraw(L"�Z�����̃J�M����ɓ��ꂽ", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 3)
		{
			Font::StrDraw(L"�Z�����̃J�M���J����", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 4)
		{
			Font::StrDraw(L"�ی����̃J�M����ɓ��ꂽ", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 5)
		{
			Font::StrDraw(L"�ی����̃J�M���J����", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 6)
		{
			Font::StrDraw(L"�n���}�[����ɓ��ꂽ", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 7)
		{
			Font::StrDraw(L"�s���ȋC�z������I", m_x + 16, m_y + 16, 64, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 8)
		{
			Font::StrDraw(L"�}�����̃J�M����ɓ��ꂽ", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 9)
		{
			Font::StrDraw(L"�}�����̃J�M���J����", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 10)
		{
			Font::StrDraw(L"�ƒ�Ȏ��̃J�M����ɓ��ꂽ", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 11)
		{
			Font::StrDraw(L"�ƒ�Ȏ��̃J�M���J����", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}
		else if (Message == 12)
		{
			Font::StrDraw(L"�ƒ�ȏ������̃J�M���J����", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"��", 760, 560, 16, c3);
		}

	}
}