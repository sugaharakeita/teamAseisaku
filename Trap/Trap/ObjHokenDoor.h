#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjHokenDoor :public CObj
{
public:
	CObjHokenDoor(float x, float y);
	~CObjHokenDoor() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int m_time;
	bool HIT_flag;
	bool hoken_door;
};