#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "ObjShokuinDoor.h"
#include "GameHead.h"

using namespace GameL;

CObjShokuinDoor::CObjShokuinDoor(float x, float y)
{
	m_x = x;
	m_y = y;
}


void CObjShokuinDoor::Init()
{
	m_time = 0;
	shokuin_door = false;

	Hits::SetHitBox(this, m_x, m_y, 64, 110, ELEMENT_DOOR, SHOKUIN_DOOR, 1);
}

void CObjShokuinDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (HIT_flag == true)
	{
		if (shokuin_door == false)
		{
			if (Input::GetVKey(VK_RETURN) == true)
			{
				m_x -= 64;
				shokuin_door = true;
				Hits::DeleteHitBox(this);
				Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_FIELD, OBJ_WALL, 1);
				hit->SetPos(0,0);
			}
		}
	}

	if(shokuin_door==true)
		m_time++;
	if (m_time >= 80)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneShokuin());
	}
	
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		HIT_flag = true;
	else
		HIT_flag = false;
}

void CObjShokuinDoor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 10.0f;
	src.m_left = 459.0f;
	src.m_right = 491.0f;
	src.m_bottom = 105.0f;

	dst.m_top = (0.0f + m_y);
	dst.m_left = (0.0f + m_x);
	dst.m_right = (64.0f + m_x);
	dst.m_bottom = (106.0f + m_y);

	Draw::Draw(4, &src, &dst, c, 0.0f);
}