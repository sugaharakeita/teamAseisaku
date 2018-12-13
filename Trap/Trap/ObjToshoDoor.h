#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjToshoDoor :public CObj
{
public:
	CObjToshoDoor(float x, float y);
	~CObjToshoDoor() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int HIT_flag;
	bool tosho_door;
};