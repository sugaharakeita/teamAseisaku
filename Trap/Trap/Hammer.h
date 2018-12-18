#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

class CObjHammer :public CObj
{
public:
	CObjHammer(float x, float y);
	~CObjHammer() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	bool m_del;
	bool Hit_flag;
	int m_time;
	RECT_F m_eff;
};