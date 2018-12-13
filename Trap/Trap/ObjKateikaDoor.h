#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjKateikaDoor :public CObj
{
public:
	CObjKateikaDoor(float x, float y);
	~CObjKateikaDoor() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int HIT_flag;
	bool kateika_door;
};