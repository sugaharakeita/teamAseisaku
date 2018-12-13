#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjKyoushituDoor :public CObj
{
public:
	CObjKyoushituDoor(float x, float y);
	~CObjKyoushituDoor() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int HIT_flag;
	bool kyoushitu_door;
};