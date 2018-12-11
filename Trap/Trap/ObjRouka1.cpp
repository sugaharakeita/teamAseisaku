#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
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
	m_time = 0;
}

void CObjRouka1::Action()
{
	m_time++;
	if (room[0] == 1)
	{
		if (HeroX <= 11.0f)
			HeroX = 11.0f;
		if (HeroX >= 756.0f)
		{
			room[0] = 0;
			Rouka1CL = room[1] = 1;
			Scene::SetScene(new CSceneRouka1());
		}
		if (HeroY <= 140.0f)
			HeroY = 140.0f;
		if (HeroY >= 440.0f)
			HeroY = 440.0f;
		if (m_time == 5)
			Rouka1CL = Kouchou = Shokuin = 0;
	}
	else if (room[1] == 1)
	{
		if (HeroX <= -20.0f)
		{
			Rouka1L = room[0] = 1;
			room[1] = 0;
			Scene::SetScene(new CSceneRouka1());
		}
		if (HeroX >= 756.0f)
		{
			Rouka1CR = room[2] = 1;
			room[1] = 0;
			Scene::SetScene(new CSceneRouka1());
		}
		if (HeroY <= 140.0f)
			HeroY = 140.0f;
		if (HeroY >= 440.0f)
			HeroY = 440.0f;
		if (m_time == 5)
			Rouka1L = Rouka1CR = Shokuin = 0;
	}
	else if (room[2] == 1)
	{
		if (Hammer == 1)
		{
			Message = 7;//ここに金次郎が突っ込んでくるイベント
		}

		if (HeroX <= -20.0f)
		{
			room[2] = 0;
			Rouka1CL = room[1] = 1;
			Scene::SetScene(new CSceneRouka1());
		}
		if (HeroX >= 756.0f)
		{
			Rouka1R = room[3] = 1;
			room[2] = 0;
			Scene::SetScene(new CSceneRouka1());
		}
		if (HeroY <= 140.0f)
			HeroY = 140.0f;
		if (HeroY >= 540.0f)
			HeroY = 540.0f;
		if (m_time == 5)
			Rouka1CL = Rouka1R = 0;
	}
	else if (room[3] == 1)
	{
		if (HeroX <= -20.0f)
		{
			room[3] = 0;
			Rouka1CR = room[2] = 1;
			Scene::SetScene(new CSceneRouka1());
		}
		if (HeroX >= 736.0f)
			HeroX = 736.0f;
		if (HeroY <= 140.0f)
			HeroY = 140.0f;
		if (HeroY >= 440.0f)
			HeroY = 440.0f;
		if (m_time == 5)
			Rouka1CR = Hoken = 0;
	}
}

void CObjRouka1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,0.45f };
	RECT_F src;
	RECT_F dst;

	if (room[0] == 1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 518.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (room[1] == 1)
	{
		src.m_top = 0.0f;
		src.m_left = 518.0f;
		src.m_right = 1035.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (room[2] == 1)
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
	else if (room[3] == 1)
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