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

	if (KOUCHOUDOOR_flag == true && Input::GetVKey(VK_RETURN) == true)
		Kou_flag = true;
	
	if (hit->CheckObjNameHit(KOUCHOU_DOOR) != nullptr)
		KOUCHOUDOOR_flag = true;
	else
		KOUCHOUDOOR_flag = false;

	if (m_x > 736.f)
		m_x = 736.0f;
	if (m_x < 11.0f)
		m_x = 11.0f;
}

void CObjKouchouKey::Draw()
{
	
}