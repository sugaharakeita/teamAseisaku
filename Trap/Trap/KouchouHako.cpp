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
	Hit_flag = 0;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_OBJECT, OBJ_HAKO, 1);
}

void CObjKouchouHako::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (KouchouHakoOpen == true)
		;
	else if (Hit_flag == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			Hits::DeleteHitBox(this);
			CObjKouchouKey* k = new CObjKouchouKey(HeroX+8, HeroY+8);
			Objs::InsertObj(k, KOUCHOU_KEY, 1);

			if (KouchouHakoOpen == false)
			{
				KouchouHakoOpen = true;
				KouchouKey = 1;
				Message = 2;//2番目にセットしたメッセージを表示する
			}
			else
				Message = 3;//3番目にセットしたメッセージを表示する
		}
	}

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		Hit_flag = 1;//開けることができる
	else
		Hit_flag = 0;
}

void CObjKouchouHako::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;
	if (KouchouHakoOpen == true)
	{
		src.m_top = 0.0f;
		src.m_left = 69.0f;
		src.m_right = 84.0f;
		src.m_bottom = 15.0f;

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 64.0f + m_x;
		dst.m_bottom = 64.0f + m_y;

		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
	else
	{
		src.m_top = 0.0f;
		src.m_left = 48.0f;
		src.m_right = 63.0f;
		src.m_bottom = 15.0f;

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 64.0f + m_x;
		dst.m_bottom = 64.0f + m_y;

		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
}