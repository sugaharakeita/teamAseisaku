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
	Hit_flag = false;
	HOKENDOOR_flag = false;
	if(HokenKey==1)
		Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_PLAYER, HOKEN_KEY, 1);
	else if(HokenKey==0)
		Hits::SetHitBox(this, m_x, m_y, 18, 18, ELEMENT_ITEM, HOKEN_KEY, 1);
}

void CObjHokenKey::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (HokenKey == 0)
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			Hit_flag = true;
		else
			Hit_flag = false;

		if (Hit_flag == true)
		{
			if (Input::GetVKey(VK_RETURN) == true && HokenKey == 0)
			{
				HokenKey = 1;
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				Message = 4;
			}
		}
	}
	else if (HokenKey == 1)
	{
		if (Input::GetVKey('W') == true && Text == 0
			&& Message == 0 && Menu == 0 && HeroStop != 4)
		{
			if (HIT_flag == true || HeroStop == 3)
				;
			else
				hit->SetPos(HeroX + 8, HeroY);
		}
		else if (Input::GetVKey('S') == true && Text == 0
			&& Message == 0 && Menu == 0 && HeroStop != 4)
		{
			if (HIT_flag == true || HeroStop == 2)
				;
			else
				hit->SetPos(HeroX + 8, HeroY + 16);
		}
		else if (Input::GetVKey('A') == true && Text == 0
			&& Message == 0 && Menu == 0 && HeroStop != 4)
		{
			if (HIT_flag == true || HeroStop == 1)
				;
			else
				hit->SetPos(HeroX, HeroY + 8);
		}
		else if (Input::GetVKey('D') == true && Text == 0
			&& Message == 0 && Menu == 0 && HeroStop != 4)
		{
			if (HIT_flag == true || HeroStop == 0)
				;
			else
				hit->SetPos(HeroX + 16, HeroY + 8);
		}

		if (Hero == false)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		if (HOKENDOOR_flag == true && Input::GetVKey(VK_RETURN) == true)
			Hok_flag = true;

		if (hit->CheckObjNameHit(HOKEN_DOOR) != nullptr)
			HOKENDOOR_flag = true;
		else
			HOKENDOOR_flag = false;

		if (m_x > 736.f)
			m_x = 736.0f;
		if (m_x < 11.0f)
			m_x = 11.0f;
	}
}

void CObjHokenKey::Draw()
{
	float c[4] = { 1.0f,1.0f,0.5f,0.8f };
	RECT_F src;
	RECT_F dst;

	if (HokenKey == 0)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 9.0f;
		src.m_bottom = 4.0f;

		dst.m_top = 0.0f + m_y - 16.0f;
		dst.m_left = 0.0f + m_x - 10.0f;
		dst.m_right = 36.0f + m_x - 10.0f;
		dst.m_bottom = 16.0f + m_y - 16.0f;

		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
}