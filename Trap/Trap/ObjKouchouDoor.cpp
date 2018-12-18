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
	kouchou_door = false;

	if (room[0] == 1)
		Hits::SetHitBox(this, m_x, m_y, 100, 158, ELEMENT_DOOR, KOUCHOU_DOOR, 1);
	if (room[4] == 1)
		Hits::SetHitBox(this, m_x, m_y, 120, 120, ELEMENT_DOOR, KOUCHOU_DOOR, 1);
}

void CObjKouchouDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (KouchouDoorOpen == true)//鍵開け済み
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = 2;//開けることができる
		else
			HIT_flag = 0;
	}
	else
	{
		if (hit->CheckObjNameHit(KOUCHOU_KEY) != nullptr)
			HIT_flag = 2;//鍵を開ける
		else if(hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = 1;//鍵がなくて開けられない
		else
			HIT_flag = 0;
	}

	if (HIT_flag == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true && kouchou_door == false)
		{
			kouchou_door = true;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_FIELD, OBJ_WALL, 1);//自動移動
			hit->SetPos(0, 0);
			
			if (KouchouDoorOpen == false)
			{
				Message = 3;//３番にセットしたメッセージを表示する
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
	{
		if (Message == 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			if (Rouka1L == 1)
			{
				Kouchou = room[4] = 1;
				room[0] = 0;
				Scene::SetScene(new CSceneKouchou());
			}
			else if (Kouchou == 1)
			{
				Rouka1L = room[0] = 1;
				room[4] = 0;
				Scene::SetScene(new CSceneRouka1());
			}
		}
	}
}

void CObjKouchouDoor::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (room[0] == 1)
	{
		if (kouchou_door == false)
		{
			src.m_top = 10.0f;
			src.m_left = 490.0f;
			src.m_right = 522.0f;
			src.m_bottom = 105.0f;

			dst.m_top = 0.0f + m_y;
			dst.m_left = 0.0f + m_x;
			dst.m_right = 100.0f + m_x;
			dst.m_bottom = 158.0f + m_y;

			Draw::Draw(4, &src, &dst, c, 0.0f);
		}
		else
		{
			src.m_top = 654.0f;
			src.m_left = 341.0f;
			src.m_right = 404.0f;
			src.m_bottom = 729.0f;

			dst.m_top = 0.0f + m_y;
			dst.m_left = 0.0f + m_x;
			dst.m_right = 100.0f + m_x;
			dst.m_bottom = 158.0f + m_y;

			Draw::Draw(7, &src, &dst, c, 0.0f);
		}
	}
	else if (room[4] == 1)
	{
		if (kouchou_door == false)
		{
			src.m_top = 10.0f;
			src.m_left = 490.0f;
			src.m_right = 522.0f;
			src.m_bottom = 105.0f;
		}
		else
		{
			src.m_top = 106.0f;
			src.m_left = 490.0f;
			src.m_right = 522.0f;
			src.m_bottom = 201.0f;
		}

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 120.0f + m_x;
		dst.m_bottom = 120.0f + m_y;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
}