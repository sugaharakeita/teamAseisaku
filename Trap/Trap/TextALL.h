#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjTextALL : public CObj
{
public:
	CObjTextALL(float x, float y);
	~CObjTextALL() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
};