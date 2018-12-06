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
	t_flag = false;
	m_time = 0;
	Hits::SetHitBox(this, HeroX,HeroY, 48, 48, ELEMENT_PLAYER, OBJ_HERO, 1);
}

void CObjExcla::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (Input::GetVKey('W') == true && Message == 0)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 3)
			;
		else
		{
			HeroY -= 0.0f;
			hit->SetPos(HeroX + 8, HeroY);
		}
	}
	else if (Input::GetVKey('S') == true && Message == 0)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 2)
			;
		else
		{
			HeroY += 0.0f;
			hit->SetPos(HeroX + 8, HeroY + 16);
		}
	}
	else if (Input::GetVKey('A') == true && Message == 0)
	{
		if (HIT_flag == true || t_flag == true || HeroStop == 1)
			;
		else
		{
			HeroX -= 0.0f;
			hit->SetPos(HeroX, HeroY + 8);
		}
	}
	else if (Input::GetVKey('D') == true && Message == 0)
	{
		if (HIT_flag == true || t_flag ==true || HeroStop == 0)
			;
		else
		{
			HeroX += 0.0f;
			hit->SetPos(HeroX + 16, HeroY + 8);
		}
	}

	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		Hero = true;
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (Hero == false)//主人公が喪失すればこれらも喪失する
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (hit->CheckElementHit(ELEMENT_FIELD) == true
		|| hit->CheckElementHit(ELEMENT_OBJECT) == true
		|| hit->CheckElementHit(ELEMENT_ITEM) == true)
		HeroStop = HERO;
	else
		HeroStop = 4;
	
	if (hit->CheckElementHit(ELEMENT_DOOR) == true)
	{
		DOOR_flag = true;
		HeroStop = HERO;
	}
	else
	{
		DOOR_flag = false;
		HeroStop = 4;
	}
	if (hit->CheckObjNameHit(OBJ_HAKO) != nullptr)
		HAKO_flag = true;
	else
	{
		HAKO_flag = false;
		HeroStop = 4;
	}
	if (hit->CheckElementHit(ELEMENT_ITEM) == true)
		ITEM_flag = true;
	else
	{
		ITEM_flag = false;
		HeroStop = 4;
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
	
	dst.m_top = 0.0f + (HeroY-24);
	dst.m_left = 0.0f + (HeroX+16);
	dst.m_right = 32.0f + (HeroX+16);
	dst.m_bottom = 32.0f + (HeroY-24);

	if (HAKO_flag == true || DOOR_flag == true || ITEM_flag == true)
		Draw::Draw(2, &src, &dst, c, 0.0f);
	else
		;
}