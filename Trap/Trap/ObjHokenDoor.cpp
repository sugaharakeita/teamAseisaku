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
	m_time = 0;
	hoken_door = false;
	
	Hits::SetHitBox(this, m_x, m_y, 128, 110, ELEMENT_DOOR, HOKEN_DOOR, 1);
}

void CObjHokenDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (HokenDoorOpen == true)
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = true;
		else
			HIT_flag = false;
	}
	else
	{
		if (hit->CheckObjNameHit(HOKEN_KEY) != nullptr)
			HIT_flag = true;
		else
			HIT_flag = false;
	}
	
	if (HIT_flag == true)
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
	else if (HIT_flag == false)
	{
		if (Input::GetVKey(VK_RETURN) == true && hoken_door == false)
			Message = 1;
	}

	if (hoken_door == true)
		m_time++;
	if (m_time >= 80)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneHoken());
	}
}

void CObjHokenDoor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (hoken_door == true)
	{
		src.m_top = 201.0f;
		src.m_left = 73.0f;
		src.m_right = 136.0f;
		src.m_bottom = 361.0f;

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 128.0f + m_x;
		dst.m_bottom = 160.0f + m_y;

		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	else
	{
		src.m_top = 10.0f;
		src.m_left = 459.0f;
		src.m_right = 491.0f;
		src.m_bottom = 105.0f;
	
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 128.0f + m_x;
		dst.m_bottom = 160.0f + m_y;
		
		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
}