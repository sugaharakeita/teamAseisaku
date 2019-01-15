#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "ObjKateikaDoor.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"

using namespace GameL;

CObjKateikaDoor::CObjKateikaDoor(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjKateikaDoor::Init()
{
	Hit_flag = 0;
	kateika_door = false;

	if (room[7] == 1)//２階廊下左側に居る場合
		Hits::SetHitBox(this, m_x, m_y, 100, 158, ELEMENT_DOOR, KATEIKA_DOOR, 1);
	if (room[10] == 1)//家庭科室に居る場合
		Hits::SetHitBox(this, m_x, m_y, 120, 120, ELEMENT_DOOR, KATEIKA_DOOR, 1);
}

void CObjKateikaDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (KateikaDoorOpen == true)
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = 1;//開けることができる
		else
			HIT_flag = 0;
	}
	else
	{
		if (hit->CheckObjNameHit(KATEIKA_KEY) != nullptr)
			HIT_flag = 1;//鍵を開ける
		else if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = 2;//鍵がなくて開けられない
		else
			HIT_flag = 0;
	}

	if (HIT_flag == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true && kateika_door == false)
		{
			kateika_door = true;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_FIELD, OBJ_WALL, 1);//自動移動
			hit->SetPos(0, 0);

			if (KateikaDoorOpen == false)
			{
				Message = 14;//14番にセットしたメッセージを表示する
				KateikaDoorOpen = true;
			}
		}
	}
	else if (HIT_flag == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true && kateika_door == false)
			Message = 1;//1番にセットしたメッセージを表示する
	}

	if (kateika_door == true)
	{
		if (Message == 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			if (Rouka2L == 1)//２階廊下左側に居る場合
			{
				room[7] = 0;//この部屋からは居なくなる
				Kateika = room[10] = 1;//家庭科室に移動する
				Scene::SetScene(new CSceneKateika());
			}
			else if (Kateika == 1)//家庭科室に居る場合
			{
				room[10] = 0;//この部屋からは居なくなる
				Rouka2L = room[7] = 1;//２階廊下左側に移動する
				Scene::SetScene(new CSceneRouka2());
			}
		}
	}
}

void CObjKateikaDoor::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (Rouka2L == 1)//２階廊下左側に居る場合
	{
		if (kateika_door == false)
		{
			src.m_top = 12.0f;
			src.m_left = 75.0f;
			src.m_right = 138.0f;
			src.m_bottom = 107.0f;
		}
		else
		{
			src.m_top = 108.0f;
			src.m_left = 75.0f;
			src.m_right = 138.0f;
			src.m_bottom = 171.0f;
		}
			dst.m_top = 0.0f + m_y;
			dst.m_left = 0.0f + m_x;
			dst.m_right = 100.0f + m_x;
			dst.m_bottom = 158.0f + m_y;

			Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	else if (Kateika == 1)//家庭科室に居る場合
	{
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 100.0f + m_x;
		dst.m_bottom = 158.0f + m_y;

		if (kateika_door == false)
		{
			src.m_top = 12.0f;
			src.m_left = 75.0f;
			src.m_right = 138.0f;
			src.m_bottom = 107.0f;

			Draw::Draw(11, &src, &dst, c, 0.0f);
		}
		else
		{
			src.m_top = 298.0f;
			src.m_left = 139.0f;
			src.m_right = 202.0f;
			src.m_bottom = 361.0f;

			Draw::Draw(10, &src, &dst, c, 0.0f);
		}
	}
}