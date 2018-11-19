#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

class CObjHokenKey :public CObj
{
public:
	CObjHokenKey(float x, float y);
	~CObjHokenKey() {};
	void Init();
	void Action();
	void Draw();
	int hokenkey;
	bool hokenkey_flag;
private:
	float m_x;
	float m_y;
	float m_vx;
	bool m_del;
	bool Hero;
	bool UP_flag;
	bool LEFT_flag;
	bool RIGHT_flag;
	bool DOWN_flag;
	bool HIT_flag;
	bool DOOR_flag;
	bool HOKENDOOR_flag;
	int flag;
	bool t_flag;
	int m_time;
	int m_ani_time;
	int m_ani_frame;
	RECT_F m_eff;
};