#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjKateikaJunbiDoor :public CObj
{
public:
	CObjKateikaJunbiDoor(float x, float y);
	~CObjKateikaJunbiDoor() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int Hit_flag;
	bool kateikajunbi_door;
};