#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjMenu : public CObj
{
public:
	CObjMenu(float x, float y);
	~CObjMenu() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
};