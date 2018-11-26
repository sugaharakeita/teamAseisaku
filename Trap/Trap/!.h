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
	int flag;
	bool t_flag;
	int m_time;
	int m_ani_time;
	int m_ani_frame;
};