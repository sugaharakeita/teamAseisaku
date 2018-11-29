#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"
#include "ItemALL.h"
#include "KouchouKey.h"

using namespace GameL;

CObjKouchouKey::CObjKouchouKey(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjKouchouKey::Init()
{
	KOUCHOUDOOR_flag = false;
	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_PLAYER, KOUCHOU_KEY, 1);
}

void CObjKouchouKey::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

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

	if (KOUCHOUDOOR_flag == true && Input::GetVKey(VK_RETURN) == true)
		HokenKey = 0;

	if (hit->CheckObjNameHit(KOUCHOU_DOOR) != nullptr)
		KOUCHOUDOOR_flag = true;
	else
		KOUCHOUDOOR_flag = false;

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

void CObjKouchouKey::Draw()
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