#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "SwitchALL.h"
#include "ObjKouchou.h"
#include "GameHead.h"

using namespace GameL;

int CObjKouchou::GetMap(int x, int y)
{
	if (x < MAP_MIN)return MAP_ERROR;
	if (y < MAP_MIN)return MAP_ERROR;
	if (x >= MAP_X_MAX)return MAP_WALL;
	if (y >= MAP_Y_MAX)return MAP_BOTTOM;
	return m_map[y][x];
}

void CObjKouchou::SetMap(int x, int y, int id)
{
	if (x < MAP_MIN)return;
	if (y < MAP_MIN)return;
	if (x >= MAP_X_MAX)return;
	if (y >= MAP_Y_MAX)return;
	m_map[y][x] = id;
	return;
}

void CObjKouchou::Init()
{
	m_time = 0;
}

void CObjKouchou::Action()
{
	m_time++;
	if (HeroX <= 16.0f)
		HeroX = 16.0f;
	if (HeroX >= 736.0f)
		HeroX = 736.0f;
	if (HeroY <= 100.0f)
		HeroY = 100.0f;
	if (HeroY >= 540.0f)
		HeroY = 540.0f;

	if (m_time == 5)
		Rouka1L = 0;
}

void CObjKouchou::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,0.45f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 467.0f;
	src.m_bottom = 730.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(7, &src, &dst, c, 0.0f);
}