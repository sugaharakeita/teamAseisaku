#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjShokuinDoor :public CObj
{
public:
	CObjShokuinDoor(float x, float y);
	~CObjShokuinDoor() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int Hit_flag;
	bool shokuin_door;
};