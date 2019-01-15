#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "ObjShokuinDoor.h"
#include "GameHead.h"
#include "SwitchALL.h"

using namespace GameL;

CObjShokuinDoor::CObjShokuinDoor(float x, float y)
{
	m_x = x;
	m_y = y;
}


void CObjShokuinDoor::Init()
{
	shokuin_door = false;
	Hit_flag = 0;

	if (room[0] == 1 && Rouka1L == 1 || room[1] == 1 && Rouka1CL == 1)//‚PŠK˜L‰º¶‘¤‚Ü‚½‚Í’†‰›¶‘¤‚É‹‚éê‡
		Hits::SetHitBox(this, m_x, m_y, 102, 160, ELEMENT_DOOR, SHOKUIN_DOOR, 1);
	else if (room[5] == 1 && Shokuin == 1)//Eˆõº‚É‹‚éê‡
		Hits::SetHitBox(this, m_x, m_y, 68,120, ELEMENT_DOOR, SHOKUIN_DOOR, 1);
}

void CObjShokuinDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (Hit_flag == 1 && Menu == 0)
	{
		if (shokuin_door == false)
		{
			if (Input::GetVKey(VK_RETURN) == true)
			{
				shokuin_door = true;
				Hits::DeleteHitBox(this);
				Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_FIELD, OBJ_WALL, 1);//©“®ˆÚ“®
				hit->SetPos(0,0);
			}
		}
	}

	if (shokuin_door == true)
	{
		if (Message == 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			if (Rouka1L == 1 || Rouka1CL == 1)//‚PŠK˜L‰º¶‘¤‚Ü‚½‚Í’†‰›¶‘¤‚É‹‚éê‡
			{
				room[0] = room[1] = 0;//‚±‚Ì•”‰®‚©‚ç‚Í‹‚È‚­‚È‚é
				Shokuin = room[5] = 1;//Eˆõº‚ÉˆÚ“®‚·‚é
				Scene::SetScene(new CSceneShokuin());
			}
			else if (Shokuin == 1)//Eˆõº‚É‹‚éê‡
			{
				room[5] = 0;//‚±‚Ì•”‰®‚©‚ç‚Í‹‚È‚­‚È‚é
				if (HeroL == true)//ålŒö‚ª¶‘¤‚Ì”à‚ğŠJ‚¯‚½ê‡
				{
					Rouka1L = room[0] = 1;//‚PŠK˜L‰º¶‘¤‚ÉˆÚ“®‚·‚é
					Scene::SetScene(new CSceneRouka1());
				}
				else//ålŒö‚ª‰E‘¤‚Ì”à‚ğŠJ‚¯‚½ê‡
				{
					Rouka1CL = room[1] = 1;//‚PŠK˜L‰º’†‰›¶‘¤‚ÉˆÚ“®‚·‚é
					Scene::SetScene(new CSceneRouka1());
				}
			}
		}
	}
	
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		Hit_flag = 1;
	else
		Hit_flag = 0;
}

void CObjShokuinDoor::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (shokuin_door == false)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 74.0f;
		src.m_bottom = 128.0f;
	}
	else
	{
		src.m_top = 128.0f;
		src.m_left = 0.0f;
		src.m_right = 74.0f;
		src.m_bottom = 208.0f;
	}
	if (Rouka1L == 1 || Rouka1CL == 1)//‚PŠK˜L‰º¶‘¤‚Ü‚½‚Í‚PŠK˜L‰º’†‰›¶‘¤‚É‹‚éê‡
	{
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 102.0f + m_x;
		dst.m_bottom = 160.0f + m_y;
	}
	else if (Shokuin == 1)//Eˆõº‚É‹‚éê‡
	{
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 68.0f + m_x;
		dst.m_bottom = 120.0f + m_y;
	}

	Draw::Draw(8, &src, &dst, c, 0.0f);
}