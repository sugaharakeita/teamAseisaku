#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "SwitchALL.h"
#include "ObjKyoushitu.h"
#include "GameHead.h"

using namespace GameL;

int CObjKyoushitu::GetMap(int x, int y)
{
	if (x < MAP_MIN)return MAP_ERROR;
	if (y < MAP_MIN)return MAP_ERROR;
	if (x >= MAP_X_MAX)return MAP_WALL;
	if (y >= MAP_Y_MAX)return MAP_BOTTOM;
	return m_map[y][x];
}

void CObjKyoushitu::SetMap(int x, int y, int id)
{
	if (x < MAP_MIN)return;
	if (y < MAP_MIN)return;
	if (x >= MAP_X_MAX)return;
	if (y >= MAP_Y_MAX)return;
	m_map[y][x] = id;
	return;
}

void CObjKyoushitu::Init()
{
	m_time = 0;
}

void CObjKyoushitu::Action()
{
	m_time++;
	if (HeroX <= 0.0f)
		HeroX = 0.0f;
	if (HeroX >= 744.0f)
		HeroX = 744.0f;
	if (HeroY <= 86.0f)
		HeroY = 86.0f;
	if (HeroY >= 494.0f)
		HeroY = 494.0f;

	if (m_time == 5)
		Rouka2R = 0;//SwitchALLの混同を避けるため
}

void CObjKyoushitu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,0.45f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 660.0f;
	src.m_bottom = 442.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(13, &src, &dst, c, 0.0f);
}