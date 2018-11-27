#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "!.h"
#include "SwitchALL.h"

using namespace GameL;

CObjExcla::CObjExcla(float x, float y)
{
	
}

void CObjExcla::Init()
{
	flag = 0;//Œü‚«‚Ì•Ï”B‰EŒü‚«‚ð0‚Æ‚·‚éB
	t_flag = false;
	m_time = 0;
	m_ani_time = 0;
	m_ani_frame = 1;
	Hits::SetHitBox(this, HeroX,HeroY, 48, 48, ELEMENT_PLAYER, OBJ_HERO, 1);
}

void CObjExcla::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (Input::GetVKey('W') == true && UP_flag == false)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 3)
			;
		else
		{
			HeroY -= 0.0f;
			flag = 3;
			m_ani_time += 1;
			hit->SetPos(HeroX + 8, HeroY);
		}
	}
	else if (Input::GetVKey('S') == true && DOWN_flag == false)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 2)
			;
		else
		{
			HeroY += 0.0f;
			flag = 2;
			m_ani_time += 1;
			hit->SetPos(HeroX + 8, HeroY + 16);
		}
	}
	else if (Input::GetVKey('A') == true && LEFT_flag == false)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 1)
			;
		else
		{
			HeroX -= 0.0f;
			flag = 1;
			m_ani_time += 1;
			hit->SetPos(HeroX, HeroY + 8);
		}
	}
	else if (Input::GetVKey('D') == true && RIGHT_flag == false)
	{
		if (HIT_flag == true || t_flag ==true || HeroStop == 0)
			;
		else
		{
			HeroX += 0.0f;
			flag = 0;
			m_ani_time += 1;
			hit->SetPos(HeroX + 16, HeroY + 8);
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

	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		Hero = true;
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (Hero == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (Input::GetVKey(VK_RETURN) == true && DOOR_flag == true)
		UP_flag = DOWN_flag = LEFT_flag = RIGHT_flag = t_flag = true;
	if (hit->CheckElementHit(ELEMENT_FIELD) == true
		|| hit->CheckElementHit(ELEMENT_OBJECT) == true
		|| hit->CheckElementHit(ELEMENT_ITEM) == true)
	{
		if (flag == 0)
		{
			RIGHT_flag = true;
			HeroStop = 0;
		}
		if (flag == 1)
		{
			LEFT_flag = true;
			HeroStop = 1;
		}
		if (flag == 2)
		{
			DOWN_flag = true;
			HeroStop = 2;
		}
		if (flag == 3)
		{
			UP_flag = true;
			HeroStop = 3;
		}
	}
	else
	{
		UP_flag = DOWN_flag = LEFT_flag = RIGHT_flag = false;
		HeroStop = 4;
	}
	
	if (t_flag == true)
		m_time++;
	if (m_time >= 79)
	{
		UP_flag = DOWN_flag = LEFT_flag = RIGHT_flag = t_flag = false;
		m_time = 0;
	}

	if (hit->CheckElementHit(ELEMENT_DOOR) == true)
	{
		DOOR_flag = true;
		if (flag == 0)
			RIGHT_flag = true;
		if (flag == 1)
			LEFT_flag = true;
		if (flag == 2)
			DOWN_flag = true;
		if (flag == 3)
			UP_flag = true;
	}
	else
		DOOR_flag = false;
	if (hit->CheckObjNameHit(OBJ_HAKO) != nullptr)
		HAKO_flag = true;
	else
		HAKO_flag = false;
	if (hit->CheckElementHit(ELEMENT_ITEM) == true)
		ITEM_flag = true;
	else
		ITEM_flag = false;
}

void CObjExcla::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 440.0f;
	src.m_bottom = 440.0f;
	
	dst.m_top = 0.0f + (HeroY-24);
	dst.m_left = 0.0f + (HeroX+16);
	dst.m_right = 32.0f + (HeroX+16);
	dst.m_bottom = 32.0f + (HeroY-24);

	if (HAKO_flag == true || DOOR_flag == true || ITEM_flag == true)
		Draw::Draw(2, &src, &dst, c, 0.0f);
	else
		;
}