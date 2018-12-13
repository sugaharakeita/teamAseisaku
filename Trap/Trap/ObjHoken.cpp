#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "SwitchALL.h"
#include "ObjHoken.h"
#include "GameHead.h"

using namespace GameL;

int CObjHoken::GetMap(int x, int y)
{
	if (x < MAP_MIN)return MAP_ERROR;
	if (y < MAP_MIN)return MAP_ERROR;
	if (x >= MAP_X_MAX)return MAP_WALL;
	if (y >= MAP_Y_MAX)return MAP_BOTTOM;
	return m_map[y][x];
}

void CObjHoken::SetMap(int x, int y, int id)
{
	if (x < MAP_MIN)return;
	if (y < MAP_MIN)return;
	if (x >= MAP_X_MAX)return;
	if (y >= MAP_Y_MAX)return;
	m_map[y][x] = id;
	return;
}

void CObjHoken::Init()
{
	m_time = 0;
}

void CObjHoken::Action()
{
	m_time++;
	if (HeroX <= 16.0f)
		HeroX = 16.0f;
	if (HeroX >= 736.0f)
		HeroX = 736.0f;
	if (HeroY <= 16.0f)
		HeroY = 16.0f;
	if (HeroY >= 540.0f)
		HeroY = 540.0f;

	if (m_time == 5)
		Rouka1R = 0;
}

void CObjHoken::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,0.45f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 721.0f;
	src.m_bottom = 375.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(9, &src, &dst, c, 0.0f);
}