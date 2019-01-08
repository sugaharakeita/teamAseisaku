#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjHero : public CObj
{
public:
	CObjHero(float x, float y);
	~CObjHero() {};
	void Init();
	void Action();
	void Draw();
private:
	int m_ani_time;
	int m_ani_frame;
};