#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include <windows.h>
#include "HokenHako.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"

using namespace GameL;

CObjHokenHako::CObjHokenHako(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjHokenHako::Init()
{
	m_time = 0;
	
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_OBJECT, OBJ_HAKO, 1);
	if (HokenHakoOpen == true)
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_FIELD, OBJ_WALL, 1);
}

void CObjHokenHako::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (HokenHakoOpen == true)
		;
	else if (HIT_flag == true)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_FIELD, OBJ_WALL, 1);
			CObjHokenKey* k = new CObjHokenKey(HeroX+8,HeroY+8);
			Objs::InsertObj(k, HOKEN_KEY, 1);

			HokenHakoOpen = true;
			HokenKey = 1;
			Message = 4;
		}
	}

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		HIT_flag = true;
	else
		HIT_flag = false;
}

void CObjHokenHako::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;
	
	if (HokenHakoOpen == true)
	{
		src.m_top = 0.0f;
		src.m_left = 16.0f;
		src.m_right = 32.0f;
		src.m_bottom = 16.0f;

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 64.0f + m_x;
		dst.m_bottom = 64.0f + m_y;

		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
	else
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 16.0f;
		src.m_bottom = 16.0f;

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 64.0f + m_x;
		dst.m_bottom = 64.0f + m_y;

		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
}