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
	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_ITEM, OBJ_HAMMER, 1);
}

void CObjHammer::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		HIT_flag = true;
	else
		HIT_flag = false;

	if (HIT_flag == true)
	{
		if (Input::GetVKey(VK_RETURN) == true && Hammer == 0)
		{
			Hammer = 1;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_PLAYER, OBJ_HAMMER, 1);
			hit->SetPos(HeroX+8, HeroY+8);
			Message = 6;
		}
	}

	if (Hammer == 1)
	{
		if (Input::GetVKey('W') == true && UP_flag == false && Message == 0)
		{
			if (HIT_flag == true || t_flag == true || HeroStop == 3)
				;
			else
				hit->SetPos(HeroX + 8, HeroY);
		}
		else if (Input::GetVKey('S') == true && DOWN_flag == false && Message == 0)
		{
			if (HIT_flag == true || t_flag == true || HeroStop == 2)
				;
			else
				hit->SetPos(HeroX + 8, HeroY + 16);
		}
		else if (Input::GetVKey('A') == true && LEFT_flag == false && Message == 0)
		{
			if (HIT_flag == true || t_flag == true || HeroStop == 1)
				;
			else
				hit->SetPos(HeroX, HeroY + 8);
		}
		else if (Input::GetVKey('D') == true && RIGHT_flag == false && Message == 0)
		{
			if (HIT_flag == true || t_flag == true || HeroStop == 0)
				;
			else
				hit->SetPos(HeroX + 16, HeroY + 8);
		}
		
		if (Hero == true)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		if (Input::GetVKey(VK_RETURN) == true)
			Ham_flag == true;
			
		if (Ham_flag == true/* && CheckObjNamehit->(KINJIRO) != nullptr*/)
			//Hammer = 0;“ñ‹{‹àŽŸ˜Y‚Æ‚Ô‚Â‚©‚Á‚½”»’èª‚ð’Ç‰Á‚µ‚È‚¯‚ê‚Î‚È‚ç‚È‚¢

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
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 64.0f;
	src.m_left = 448.0f;
	src.m_right = 512.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(3, &src, &dst, c, 0.0f);
}