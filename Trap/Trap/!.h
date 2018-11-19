#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjExcla : public CObj
{
public:
	CObjExcla(float x, float y);
	~CObjExcla() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	bool Hero;
	bool UP_flag;
	bool LEFT_flag;
	bool RIGHT_flag;
	bool DOWN_flag;
	bool HIT_flag;
	bool HAKO_flag;
	bool DOOR_flag;
	int flag;
	bool t_flag;
	int m_time;
	int m_ani_time;
	int m_ani_frame;
};