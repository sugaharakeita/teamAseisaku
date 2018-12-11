#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjShokuinPaper :public CObj
{
public:
	CObjShokuinPaper(float x, float y);
	~CObjShokuinPaper() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int m_time;
	bool HIT_flag;
};