#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "ObjKyoushituDoor.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "TrapALL.h"

using namespace GameL;

CObjKyoushituDoor::CObjKyoushituDoor(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjKyoushituDoor::Init()
{
	Hit_flag = 0;
	kyoushitu_door = false;

	if (room[8] == 1 || room[9] == 1)//‚QŠK˜L‰º’†‰›‚Ü‚½‚Í‰E‘¤‚É‹‚éê‡
		Hits::SetHitBox(this, m_x, m_y, 100, 158, ELEMENT_DOOR, KYOUSHITU_DOOR, 1);
	if (room[12] == 1)//‹³º‚É‹‚éê‡
		Hits::SetHitBox(this, m_x, m_y, 120, 120, ELEMENT_DOOR, KYOUSHITU_DOOR, 1);
}

void CObjKyoushituDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		Hit_flag = 1;
	else
		Hit_flag = 0;

	if (Hit_flag == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true && kyoushitu_door == false)
		{
			kyoushitu_door = true;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_FIELD, OBJ_WALL, 1);//©“®ˆÚ“®
			hit->SetPos(0, 0);
		}
	}
	
	if (kyoushitu_door == true)
	{
		if (Message == 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			if (Rouka2C == 1 || Rouka2R == 1)//‚QŠK˜L‰º’†‰›‚Ü‚½‚Í‰E‘¤‚É‹‚éê‡
			{
				room[8] = room[9] = 0;//‚±‚Ì•”‰®‚©‚ç‚Í‹‚È‚­‚È‚é
				Kyoushitu = room[12] = 1;//‹³º‚ÉˆÚ“®‚·‚é
				Scene::SetScene(new CSceneKyoushitu());
			}
			else if (Kyoushitu == 1)//‹³º‚É‹‚éê‡
			{
				room[12] = 0;//‚±‚Ì•”‰®‚©‚ç‚Í‹‚È‚­‚È‚é
				if (HeroL == true)
				{
					Rouka2R = room[9] = 1;//‚QŠK˜L‰º‰E‘¤‚ÉˆÚ“®‚·‚é
					Scene::SetScene(new CSceneRouka2());
				}
				else
				{

				}

			}
		}
	}
}

void CObjKyoushituDoor::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (Rouka2R == 1)//‚QŠK˜L‰º‰E‘¤‚É‹‚éê‡
	{
		if (kyoushitu_door == false)
		{
			src.m_top = 10.0f;
			src.m_left = 586.0f;
			src.m_right = 649.0f;
			src.m_bottom = 105.0f;
		}
		else
		{
			src.m_top = 106.0f;
			src.m_left = 586.0f;
			src.m_right = 649.0f;
			src.m_bottom = 169.0f;
		}
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 100.0f + m_x;
		dst.m_bottom = 158.0f + m_y;

		Draw::Draw(13, &src, &dst, c, 0.0f);
	}
	else if (Kyoushitu == 1)//‹³º‚É‹‚éê‡
	{
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 100.0f + m_x;
		dst.m_bottom = 158.0f + m_y;

		if (kyoushitu_door == false)
		{
			src.m_top = 10.0f;
			src.m_left = 586.0f;
			src.m_right = 649.0f;
			src.m_bottom = 105.0f;

			Draw::Draw(13, &src, &dst, c, 0.0f);
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