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
	Hit_flag = 0;

	if (room[3] == 1 && Rouka1R == 1)//１階廊下右側に居る場合
		Hits::SetHitBox(this, m_x, m_y, 74, 160, ELEMENT_DOOR, HOKEN_DOOR, 1);
	else if (room[6] == 1 && Hoken == 1)//保健室に居る場合
		Hits::SetHitBox(this, m_x, m_y, 68, 120, ELEMENT_DOOR, SHOKUIN_DOOR, 1); 
	
}

void CObjHokenDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (HokenDoorOpen == true)
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			Hit_flag = 1;//開けることができる
		else
			Hit_flag = 0;
	}
	else
	{
		if (hit->CheckObjNameHit(HOKEN_KEY) != nullptr)
			Hit_flag = 1;//鍵を開ける
		else if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			Hit_flag = 2;//鍵がなくて開けられない
		else
			Hit_flag = 0;
	}
	
	if (Hit_flag == 1 && Menu == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true && hoken_door == false)
		{
			hoken_door = true;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_FIELD, OBJ_WALL, 1);//自動移動
			hit->SetPos(0, 0);

			if (HokenDoorOpen == false)
			{
				Message = 6;//6番にセットしたメッセージを表示する
				HokenDoorOpen = true;
			}
		}
	}
	else if (Hit_flag == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true && hoken_door == false)
			Message = 1;//1番にセットしたメッセージを表示する
	}

	if (hoken_door == true)
	{
		if (Message == 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			if (Rouka1R == 1)//１階廊下右側に居る場合
			{
				room[3] = 0;//この部屋からは居なくなる
				Hoken = room[6] = 1;//保健室に移動する
				Scene::SetScene(new CSceneHoken());
			}
			else if (Hoken == 1)//保健室に居る場合
			{
				Rouka1R = room[3] = 1;//１階廊下右側に移動する
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

	if (room[3] == 1)//１階廊下右側に居る場合
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
	else if (room[6] == 1)//保健室に居る場合
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