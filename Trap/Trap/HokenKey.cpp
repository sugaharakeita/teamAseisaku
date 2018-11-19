#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "TrapALL.h"
#include "HokenKey.h"

using namespace GameL;

CObjHokenKey::CObjHokenKey(float x, float y)
{
	m_x = x + 64;
	m_y = y;
}

void CObjHokenKey::Init()
{
	hokenkey = 1;
	hokenkey_flag = false;
	UP_flag = false;
	LEFT_flag = false;
	RIGHT_flag = false;
	DOWN_flag = false;
	Hero = false;
	HIT_flag = false;
	DOOR_flag = false;
	HOKENDOOR_flag = false;
	m_ani_time = 0;
	m_ani_frame = 1;
	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_ITEM, HOKEN_KEY, 1);

	/*hammer = 0;
	ham_flag = false;
	kouchoukey = 0;
	kouchoukey_flag = false;
	toshokey = 0;
	toshokey_flag = false;
	kateikajunbikey = 0;
	kateikajunbikey_flag = false;
	salt = 0;
	salt_flag = false;
	cup = 0;
	kateikakey = 0;
	kateikakey_flag = false;
	water_flag = false;
	saltwater = 0;
	saltwater_flag = false;
	kyoushitukey = 0;
	kyoushitukey_flag = false;
	PCkey = 0;
	PCkey_flag = false;
	kaigikey = 0;
	kaigikey_flag = false;
	ongakukey = 0;
	ongakukey_flag = false;
	gakuf = 0;
	gakufu_flag = false;
	parachute = 0;
	parachute_flag = false;
	giftA = 0;
	giftA_flag = false;
	giftB = 0;
	giftB_flag = false;
	giftC = 0;
	giftC_flag = false; これらはコピペ用に置いてあるだけ*/
}

void CObjHokenKey::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_HERO) == nullptr)
		;
	else if (Input::GetVKey('B') == true)
	{
		hokenkey_flag = true;
		hokenkey = 1;
		Hits::DeleteHitBox(this);
		Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_PLAYER, HOKEN_KEY, 1);
	}
	
	if (hokenkey_flag == true)
	{
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
			if (HIT_flag == true || t_flag == true)
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

		if (HOKENDOOR_flag == true && Input::GetVKey('A') == true)
			hokenkey = 0;
		
		if (DOOR_flag == true && Input::GetVKey('A') == true)
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

		if (hit->CheckObjNameHit(HOKEN_DOOR) == nullptr)
			HOKENDOOR_flag = false;
		else
			HOKENDOOR_flag = true;
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
	}
}

void CObjHokenKey::Draw()
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

	if (hokenkey_flag == false)
		Draw::Draw(0, &src, &dst, c, 0.0f);
	else
		;
}