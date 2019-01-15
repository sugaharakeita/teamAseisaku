#pragma once
#include "GameL\SceneObjManager.h"

#define MAP_X_MAX (768)
#define MAP_Y_MAX (568)
#define MAP_MIN (32)
#define MAP_ERROR (96)
#define MAP_WALL (768)
#define MAP_BOTTOM (568)

using namespace GameL;

class CObjRouka2 :public CObj
{
public:
	CObjRouka2() {};
	~CObjRouka2() {};
	void Init();
	void Action();
	void Draw();
	int GetMap(int x, int y);
	void SetMap(int x, int y, int id);
private:
	int m_map[MAP_Y_MAX][MAP_X_MAX];
	int m_time;
	int ev_mass;
};