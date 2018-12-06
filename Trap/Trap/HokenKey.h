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
private:
	float m_x;
	float m_y;
	float m_vx;
	bool m_del;
	bool HOKENDOOR_flag;
	bool t_flag;
	int m_time;
	RECT_F m_eff;
};