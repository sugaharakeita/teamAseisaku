#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjHokenHako :public CObj
{
public:
	CObjHokenHako(float x, float y);
	~CObjHokenHako() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int m_time;
	bool HIT_flag;
};