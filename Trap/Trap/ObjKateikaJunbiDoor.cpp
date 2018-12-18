#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "ObjKateikaJunbiDoor.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"

using namespace GameL;

CObjKateikaJunbiDoor::CObjKateikaJunbiDoor(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjKateikaJunbiDoor::Init()
{
	kateikajunbi_door = false;

	if (room[8] == 1)
		Hits::SetHitBox(this, m_x, m_y, 100, 158, ELEMENT_DOOR, KATEIKAJUNBI_DOOR, 1);
	if (room[11] == 1)
		Hits::SetHitBox(this, m_x, m_y, 120, 120, ELEMENT_DOOR, KATEIKAJUNBI_DOOR, 1);
}

void CObjKateikaJunbiDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (KateikaJunbiDoorOpen == true)
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = 2;
		else
			HIT_flag = 0;
	}
	else
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			if (room[11] == 1)
				HIT_flag = 2;
			else if (room[8] == 1)
				HIT_flag = 1;//ŠO‘¤‚©‚ç‚ÍŠJ‚¯‚ç‚ê‚È‚¢
		else
			HIT_flag = 0;
	}

	if (HIT_flag == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true && kateikajunbi_door == false)
		{
			kateikajunbi_door = true;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_FIELD, OBJ_WALL, 1);//Ž©“®ˆÚ“®
			hit->SetPos(0, 0);

			if (KateikaJunbiDoorOpen == false)
			{
				Message = 14;
				ToshoDoorOpen = true;
			}
		}
	}
	else if (HIT_flag == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true && kateikajunbi_door == false)
			Message = 1;
	}
}

void CObjKateikaJunbiDoor::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (Rouka2C == 1)
	{
		src.m_top = 10.0f;
		src.m_left = 74.0f;
		src.m_right = 137.0f;
		src.m_bottom = 105.0f;
		
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 100.0f + m_x;
		dst.m_bottom = 158.0f + m_y;

		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	else if (KateikaJunbi == 1)
	{
		src.m_top = 10.0f;
		src.m_left = 74.0f;
		src.m_right = 137.0f;
		src.m_bottom = 105.0f;

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 100.0f + m_x;
		dst.m_bottom = 158.0f + m_y;

		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
}