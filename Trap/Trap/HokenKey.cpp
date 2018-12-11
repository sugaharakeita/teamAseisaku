#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"
#include "ItemALL.h"
#include "HokenKey.h"

using namespace GameL;

CObjHokenKey::CObjHokenKey(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjHokenKey::Init()
{
	HOKENDOOR_flag = false;
	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_PLAYER, HOKEN_KEY, 1);
}

void CObjHokenKey::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (Input::GetVKey('W') == true && Text == 0
		&& Message == 0 && Menu == 0 && HeroStop != 4)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 3)
			;
		else
			hit->SetPos(HeroX+8, HeroY);
	}
	else if (Input::GetVKey('S') == true && Text == 0
		&& Message == 0 && Menu == 0 && HeroStop != 4)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 2)
			;
		else
			hit->SetPos(HeroX+8, HeroY+16);
	}
	else if (Input::GetVKey('A') == true && Text == 0
		&& Message == 0 && Menu == 0 && HeroStop != 4)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 1)
			;
		else
			hit->SetPos(HeroX, HeroY+8);
	}
	else if (Input::GetVKey('D') == true && Text == 0
		&& Message == 0 && Menu == 0 && HeroStop != 4)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 0)
			;
		else
			hit->SetPos(HeroX+16, HeroY+8);
	}
	
	if (Hero == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (HOKENDOOR_flag == true && Input::GetVKey(VK_RETURN) == true)
	{
		HokenKey = 0;
		Hok_flag = true;
	}

	if (hit->CheckObjNameHit(HOKEN_DOOR) != nullptr)
		HOKENDOOR_flag = true;
	else
		HOKENDOOR_flag = false;

	if (m_x > 736.f)
		m_x = 736.0f;
	if (m_x < 11.0f)
		m_x = 11.0f;

	if (m_time >= 79)
	{
		t_flag = false;
		m_time = 0;
	}
}

void CObjHokenKey::Draw()
{
	float c[4] = { 1.0f,1.0f,0.5f,0.8f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 16.0f;
	src.m_left = 0.0f;
	src.m_right = 150.0f;
	src.m_bottom = 315.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 60.0f + m_x;
	dst.m_bottom = 120.0f + m_y;

	if (HokenKey == 1)
	{
		if (Menu == 2)
		{
			do
			{
				CObjHokenKey* k2 = new CObjHokenKey(32, 32);
				Objs::InsertObj(k2, HOKEN_KEY, 1);
			} while (HokenKey == 0);

			dst.m_top = 0.0f + m_y;
			dst.m_left = 0.0f + m_x;
			dst.m_right = 32.0f + m_x;
			dst.m_bottom = 32.0f + m_y;
				
			Draw::Draw(3, &src, &dst, c, 0.0f);
		}
		else
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			do
			{
				CObjHokenKey* k2 = new CObjHokenKey(HeroX+8, HeroY+8);
				Objs::InsertObj(k2, HOKEN_KEY, 1);
			} while (HokenKey == 0);
		}
	}
	else if (Hok_flag == false && HokenKey == 0)
		Draw::Draw(3, &src, &dst, c, 0.0f);
}