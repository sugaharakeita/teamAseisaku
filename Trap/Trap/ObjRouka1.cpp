#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "SwitchALL.h"
#include "ObjRouka1.h"
#include "GameHead.h"

using namespace GameL;

int CObjRouka1::GetMap(int x, int y)
{
	if (x < MAP_MIN)return MAP_ERROR;
	if (y < MAP_MIN)return MAP_ERROR;
	if (x >= MAP_X_MAX)return MAP_WALL;
	if (y >= MAP_Y_MAX)return MAP_BOTTOM;
	return m_map[y][x];
}

void CObjRouka1::SetMap(int x, int y, int id)
{
	if (x < MAP_MIN)return;
	if (y < MAP_MIN)return;
	if (x >= MAP_X_MAX)return;
	if (y >= MAP_Y_MAX)return;
	m_map[y][x] = id;
	return;
}

void CObjRouka1::Init()
{
	if (room[0] == 1)
	{
		if (HeroX < 11.0f)
			HeroX = 11.0f;
		if (HeroX > 736.0f)
			HeroX = 736.0f;
		if (HeroY < 110.0f)
			HeroY = 110.0f;
		if (HeroY > 494.0f)
			HeroY = 494.0f;
		Hits::SetHitBox(this, 0, 0, 800, 125, ELEMENT_FIELD, OBJ_WALL, 1);
		Hits::SetHitBox(this, 0, 0, 10, 600, ELEMENT_FIELD, OBJ_WALL, 1);


	}
	else if (room[1] == 1)
	{
		
	}
	else if (room[2] == 1)
	{

	}
}

void CObjRouka1::Action()
{
	
}

void CObjRouka1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	if (room[0] == 1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1035.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 1035.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (room[1] == 1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 384.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	else if (room[2] == 1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 360.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(6, &src, &dst, c, 0.0f);
	}
}