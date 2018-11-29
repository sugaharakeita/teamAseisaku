#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "ObjKouchouDoor.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"

using namespace GameL;

CObjKouchouDoor::CObjKouchouDoor(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjKouchouDoor::Init()
{
	m_time = 0;
	kouchou_door = false;

	Hits::SetHitBox(this, m_x, m_y, 64, 110, ELEMENT_DOOR, KOUCHOU_DOOR, 1);
}

void CObjKouchouDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (KouchouDoorOpen == true)
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = 2;
		else
			HIT_flag = 0;
	}
	else
	{
		if (hit->CheckObjNameHit(KOUCHOU_KEY) != nullptr)
			HIT_flag = 2;
		else if(hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = 1;
		else
			HIT_flag = 0;
	}

	if (HIT_flag == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true && kouchou_door == false)
		{
			kouchou_door = true;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_FIELD, OBJ_WALL, 1);
			hit->SetPos(0, 0);

			if (KouchouDoorOpen == false)
			{
				Message = 3;
				KouchouDoorOpen = true;
			}
		}
	}
	else if (HIT_flag == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true && kouchou_door == false)
			Message = 1;
	}

	if (kouchou_door == true)
		m_time++;
	if (m_time >= 80)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneKouchou());
	}
}

void CObjKouchouDoor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (kouchou_door == false)
	{
		src.m_top = 10.0f;
		src.m_left = 491.0f;
		src.m_right = 522.0f;
		src.m_bottom = 105.0f;
	
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 44.0f + m_x;
		dst.m_bottom = 160.0f + m_y;
		
		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else
	{
		src.m_top = 653.0f;
		src.m_left = 341.0f;
		src.m_right = 404.0f;
		src.m_bottom = 730.0f;

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 64.0f + m_x;
		dst.m_bottom = 160.0f + m_y;

		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
}