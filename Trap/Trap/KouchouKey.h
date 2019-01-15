#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

class CObjKouchouKey :public CObj
{
public:
	CObjKouchouKey(float x, float y);
	~CObjKouchouKey() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	bool KOUCHOUDOOR_flag;
	RECT_F m_eff;
};