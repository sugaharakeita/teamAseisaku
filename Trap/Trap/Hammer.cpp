#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"
#include "ItemALL.h"
#include "Hammer.h"

using namespace GameL;

CObjHammer::CObjHammer(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjHammer::Init()
{
	Hit_flag = false;
	if (Hammer == 1)
		Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_PLAYER, OBJ_HAMMER, 1);
	else if (Hammer == 0)
		Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_ITEM, OBJ_HAMMER, 1);
}

void CObjHammer::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (Hammer == 0)
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			Hit_flag = true;
		else
			Hit_flag = false;

		if (Hit_flag == true)
		{
			if (Input::GetVKey(VK_RETURN) == true && Hammer == 0)
			{
				Hammer = 1;
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				Message = 6;
			}
		}
	}
	else if (Hammer == 1)
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

		/*if (Input::GetVKey(VK_RETURN) == true)
			hit->SetPos(HeroX + 64, HeroY);
		if(CheckObjNamehit->(OBJ_KINJIRO) != nullptr)
		二宮金次郎とぶつかった判定↑を追加しなければならない
		これはイベント用に後で編集する
			Ham_flag = true;*/
			
		if (m_x > 736.f)
			m_x = 736.0f;
		if (m_x < 11.0f)
			m_x = 11.0f;

		if (Ham_flag == true)
			m_time++;
		if (m_time >= 40)
		{
			Ham_flag = false;
			m_time = 0;
		}
	}
}

void CObjHammer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,0.8f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 188.0f;
	src.m_right = 203.0f;
	src.m_bottom = 15.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 48.0f + m_x;
	dst.m_bottom = 48.0f + m_y;

	if (Hammer == 0)
		Draw::Draw(3, &src, &dst, c, 0.0f);
}