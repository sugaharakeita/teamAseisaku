#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

class CObjKouchouKey :public CObj
{
public:
	CObjKouchouKey(float x, float y);
	~CObjKouchouKey() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	bool m_del;
	bool KOUCHOUDOOR_flag;
	int flag;
	bool t_flag;
	int m_time;
	int m_ani_time;
	int m_ani_frame;
	RECT_F m_eff;
};