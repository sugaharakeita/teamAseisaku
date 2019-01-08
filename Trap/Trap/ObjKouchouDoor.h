#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjKouchouDoor :public CObj
{
public:
	CObjKouchouDoor(float x, float y);
	~CObjKouchouDoor() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int Hit_flag;
	bool kouchou_door;
};