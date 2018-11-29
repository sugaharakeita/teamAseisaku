#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

extern bool KouchouDoorOpen;
extern bool HokenDoorOpen;
extern bool KouchouHakoOpen;
extern bool HokenHakoOpen;

class CObjTrapALL :public CObj
{
public:
	CObjTrapALL(float x, float y) ;
	~CObjTrapALL() {};
	void Init();
	void Action();
	void Draw();
	bool hoken_door;
private:
	float m_x;
	float m_y;
	float m_vx;
	bool m_del;
	bool HIT_flag;
	int m_time;
	RECT_F m_eff;
};