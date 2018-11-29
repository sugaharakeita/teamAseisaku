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
	bool t_flag;
	int m_time;
};