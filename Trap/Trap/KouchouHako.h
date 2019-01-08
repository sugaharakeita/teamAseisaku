#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjKouchouHako :public CObj
{
public:
	CObjKouchouHako(float x, float y);
	~CObjKouchouHako() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int m_time;
	int Hit_flag;
};