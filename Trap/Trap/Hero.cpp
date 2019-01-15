#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "Hero.h"
#include "SwitchALL.h"
#include "TrapALL.h"
#include "ItemALL.h"

using namespace GameL;

CObjHero::CObjHero(float x, float y)
{
	HeroX = x;
	HeroY = y;
}

void CObjHero::Init()
{
	Hero = true;
	m_ani_time = 0;
	m_ani_frame = 1;
	Hits::SetHitBox(this, HeroX,HeroY, 16, 16, ELEMENT_PLAYER, OBJ_HERO, 1);
}

void CObjHero::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(HeroX + 24, HeroY + 48);

	if (Input::GetVKey('W') == true && Text == 0
		&& Message == 0 && Menu == 0 && HeroStop != 4)
		{
		if (HIT_flag == true || HeroStop == 3)
				;
			else
			{
				HeroY -= 4.0f;
				HERO = 3;
				m_ani_time += 1;
			}
		}
		else if (Input::GetVKey('S') == true && Text == 0
			&& Message == 0 && Menu == 0 && HeroStop != 4)
		{
			if (HIT_flag == true || HeroStop == 2)
				;
			else
			{
				HeroY += 4.0f;
				HERO = 2;
				m_ani_time += 1;
			}
		}
		else if (Input::GetVKey('A') == true && Text == 0
			&& Message == 0 && Menu == 0 && HeroStop != 4)
		{
			if (HIT_flag == true || HeroStop == 1)
				;
			else
			{
				HeroX -= 4.0f;
				HERO = 1;
				m_ani_time += 1;
			}
		}
		else if (Input::GetVKey('D') == true && Text == 0
			&& Message == 0 && Menu == 0 && HeroStop != 4)
		{
			if (HIT_flag == true || HeroStop == 0)
				;
			else
			{
				HeroX += 4.0f;
				HERO = 0;
				m_ani_time += 1;
			}
		}
	else
	{
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
		m_ani_frame = 0;

	if (Text == 0 && Message == 0 && Input::GetVKey('X') == true)
	{
		Menu = 1;
	}

	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		Hero = false;//“G‚Æ‚Ô‚Â‚©‚é‚Æ‘r¸‚·‚é
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

void CObjHero::Draw()
{
	int AniData[5] ={0,1,2,3,0};

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	
	dst.m_top = 0.0f + HeroY;
	dst.m_left = 0.0f + HeroX;
	dst.m_right = 64.0f + HeroX;
	dst.m_bottom = 64.0f + HeroY;

	//ålŒö‚ÌŒü‚«‚É‰‚¶‚Ä•`‰æî•ñ‚ğ•ÏX‚·‚é
	if (HERO == 0)
	{
		src.m_top = 128.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 192.0f;
	}
	else if (HERO == 1)
	{
		src.m_top = 64.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 128.0f;
	}
	else if (HERO == 2)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 64.0f;
	}
	else if (HERO == 3)
	{
		src.m_top = 192.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 256.0f;
	}

	Draw::Draw(1, &src, &dst, c, 0.0f);
}