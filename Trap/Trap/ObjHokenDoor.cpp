#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "ObjHokenDoor.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"

using namespace GameL;

CObjHokenDoor::CObjHokenDoor(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjHokenDoor::Init()
{
	hoken_door = false;
	
	if (room[3] == 1 && Rouka1R == 1)
		Hits::SetHitBox(this, m_x, m_y, 74, 160, ELEMENT_DOOR, HOKEN_DOOR, 1);
	else if (room[6] == 1 && Hoken == 1)
		Hits::SetHitBox(this, m_x, m_y, 68, 120, ELEMENT_DOOR, SHOKUIN_DOOR, 1); 
	
}

void CObjHokenDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (HokenDoorOpen == true)
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = 2;
		else
			HIT_flag = 0;
	}
	else
	{
		if (hit->CheckObjNameHit(HOKEN_KEY) != nullptr)
			HIT_flag = 2;
		else if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = 1;
		else
			HIT_flag = 0;
	}
	
	if (HIT_flag == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true && hoken_door == false)
		{
			hoken_door = true;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_FIELD, OBJ_WALL, 1);
			hit->SetPos(0, 0);

			if (HokenDoorOpen == false)
			{
				Message = 5;
				HokenDoorOpen = true;
			}
		}
	}
	else if (HIT_flag == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true && hoken_door == false)
			Message = 1;
	}

	if (hoken_door == true)
	{
		if (Message == 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			if (Rouka1R == 1)
			{
				Hoken = room[6] = 1;
				room[3] = 0;
				Scene::SetScene(new CSceneHoken());
			}
			else if (Hoken == 1)
			{
				Rouka1R = room[3] = 1;
				Scene::SetScene(new CSceneRouka1());
			}
		}
	}
}

void CObjHokenDoor::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (Rouka1R == 1)
	{
		if (hoken_door == false)
		{
			src.m_top = 10.0f;
			src.m_left = 96.0f;
			src.m_right = 128.0f;
			src.m_bottom = 105.0f;

			dst.m_top = 0.0f + m_y;
			dst.m_left = 0.0f + m_x;
			dst.m_right = 74.0f + m_x;
			dst.m_bottom = 160.0f + m_y;

			Draw::Draw(6, &src, &dst, c, 0.0f);
		}
		else
		{
			src.m_top = 201.0f;
			src.m_left = 73.0f;
			src.m_right = 136.0f;
			src.m_bottom = 321.0f;

			dst.m_top = 0.0f + m_y;
			dst.m_left = 0.0f + m_x;
			dst.m_right = 74.0f + m_x;
			dst.m_bottom = 160.0f + m_y;

			Draw::Draw(9, &src, &dst, c, 0.0f);
		}
	}
	else if (Hoken == 1)
	{
		if (hoken_door == false)
		{
			src.m_top = 10.0f;
			src.m_left = 96.0f;
			src.m_right = 128.0f;
			src.m_bottom = 105.0f;
		}
		else
		{
			src.m_top = 201.0f;
			src.m_left = 73.0f;
			src.m_right = 136.0f;
			src.m_bottom = 321.0f;
		}

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 76.0f + m_x;
		dst.m_bottom = 120.0f + m_y;

		Draw::Draw(6, &src, &dst, c, 0.0f);
	}
}