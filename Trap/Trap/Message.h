#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjMessage : public CObj
{
public:
	CObjMessage(float x, float y);
	~CObjMessage() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
};