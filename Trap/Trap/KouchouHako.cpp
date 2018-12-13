#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "KouchouHako.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"

using namespace GameL;

CObjKouchouHako::CObjKouchouHako(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjKouchouHako::Init()
{
	m_time = 0;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_OBJECT, OBJ_HAKO, 1);
	if (KouchouHakoOpen == true)
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_FIELD, OBJ_WALL, 1);
}

void CObjKouchouHako::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (KouchouHakoOpen == true)
		;
	else if (HIT_flag == true)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_FIELD, OBJ_WALL, 1);//ただの置物になるため、！を出させない
			CObjKouchouKey* k = new CObjKouchouKey(HeroX+8, HeroY+8);
			Objs::InsertObj(k, KOUCHOU_KEY, 1);

			KouchouHakoOpen = true;
			KouchouKey = 1;
			Message = 2;
		}
	}

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		HIT_flag = true;
	else
		HIT_flag = false;
}

void CObjKouchouHako::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;
	if (KouchouHakoOpen == true)
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