#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

class CObjHokenKey :public CObj
{
public:
	CObjHokenKey(float x, float y);
	~CObjHokenKey() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int Hit_flag;
	int HOKENDOOR_flag;
	RECT_F m_eff;
};