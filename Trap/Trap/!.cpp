#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "!.h"

using namespace GameL;

CObjExcla::CObjExcla(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjExcla::Init()
{
	UP_flag = false;
	LEFT_flag = false;
	RIGHT_flag = false;
	DOWN_flag = false;
	Hero = false;
	HIT_flag = false;
	HAKO_flag = false;
	DOOR_flag = false;
	flag = 0;//向きの変数。ラジアンに従い、右向きを0とする。
	t_flag = false;
	m_time = 0;
	m_ani_time = 0;
	m_ani_frame = 1;
	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_PLAYER, OBJ_HERO, 1);
}

void CObjExcla::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (Input::GetVKey(VK_UP) == true && UP_flag == false)
	{
		if (HIT_flag == true || t_flag == true)
			;
		else
		{
			m_y -= 4.0f;
			flag = 3;
			m_ani_time += 1;
			hit->SetPos(m_x + 8, m_y);
		}
	}
	else if (Input::GetVKey(VK_DOWN) == true && DOWN_flag == false)
	{
		if (HIT_flag == true || t_flag == true)
			;
		else
		{
			m_y += 4.0f;
			flag = 2;
			m_ani_time += 1;
			hit->SetPos(m_x + 8, m_y + 16);
		}
	}
	else if (Input::GetVKey(VK_LEFT) == true && LEFT_flag == false)
	{
		if (HIT_flag == true || t_flag == true)
			;
		else
		{
			m_x -= 4.0f;
			flag = 1;
			m_ani_time += 1;
			hit->SetPos(m_x, m_y + 8);
		}
	}
	else if (Input::GetVKey(VK_RIGHT) == true && RIGHT_flag == false)
	{
		if (HIT_flag == true || t_flag ==true)
			;
		else
		{
			m_x += 4.0f;
			flag = 0;
			m_ani_time += 1;
			hit->SetPos(m_x + 16, m_y + 8);
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

	if (Hero == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (Input::GetVKey('A') == true && DOOR_flag == true)
		UP_flag = DOWN_flag = LEFT_flag = RIGHT_flag = t_flag = true;
	if (hit->CheckElementHit(ELEMENT_WALL) == true
		|| hit->CheckElementHit(ELEMENT_OBJECT) == true
		|| hit->CheckElementHit(ELEMENT_ITEM) == true)
	{
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
		UP_flag = DOWN_flag = LEFT_flag = RIGHT_flag = false;
	
	if (hit->CheckElementHit(ELEMENT_DOOR) == true)
		DOOR_flag = true;
	else
		DOOR_flag = false;
	if (hit->CheckObjNameHit(OBJ_HAKO) != nullptr)
		HAKO_flag = true;
	else
		HAKO_flag = false;
	
	if (m_y > 432.0f)
		m_y = 432.0f;
	if (m_y < 174.0f)
		m_y = 174.0f;
	if (m_x > 736.f)
		m_x = 736.0f;
	if (m_x < 11.0f)
		m_x = 11.0f;
	if (t_flag == true)
		m_time++;
	if (m_time >= 79)
	{
		UP_flag = DOWN_flag = LEFT_flag = RIGHT_flag = t_flag = false;
		m_time = 0;
	}
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
	
	dst.m_top = 0.0f + (m_y-24);
	dst.m_left = 0.0f + (m_x+16);
	dst.m_right = 32.0f + (m_x+16);
	dst.m_bottom = 32.0f + (m_y-24);

	if (HAKO_flag == true || DOOR_flag == true)
		Draw::Draw(1, &src, &dst, c, 0.0f);
	else
		;
}