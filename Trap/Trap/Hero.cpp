#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "Hero.h"
#include "TrapALL.h"
#include "ItemALL.h"

using namespace GameL;

CObjHero::CObjHero(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjHero::Init()
{
	UP_flag = false;
	LEFT_flag = false;
	RIGHT_flag = false;
	DOWN_flag = false;
	Hero = false;//死亡用
	HIT_flag = false;//後で使うかも
	DOOR_flag = false;
	flag = 0;//向きの変数。ラジアンに従い、右向きを0とする。
	t_flag = false;
	m_time = 0;
	m_ani_time = 0;
	m_ani_frame = 1;
	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_PLAYER, OBJ_HERO, 1);
}

void CObjHero::Action()
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
			hit->SetPos(m_x+8, m_y);
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
			hit->SetPos(m_x+8, m_y+16);
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
			hit->SetPos(m_x, m_y+8);
		}
	}
	else if (Input::GetVKey(VK_RIGHT) == true && RIGHT_flag == false)
	{
		if (HIT_flag == true || t_flag == true)
			;
		else
		{
			m_x += 4.0f;
			flag = 0;
			m_ani_time += 1;
			hit->SetPos(m_x+16, m_y+8);
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

void CObjHero::Draw()
{
	int AniData[5] ={0,1,2,3,0};

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	if (flag == 0)
	{
		src.m_top = 128.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 192.0f;
	}
	else if (flag == 1)
	{
		src.m_top = 64.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 128.0f;
	}
	else if (flag == 2)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 64.0f;
	}
	else if (flag == 3)
	{
		src.m_top = 192.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 256.0f;
	}

	Draw::Draw(2, &src, &dst, c, 0.0f);
}