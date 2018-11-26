#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

extern bool Hero;
extern int HeroStop;
extern float HeroX;
extern float HeroY;
extern bool UP_flag;
extern bool DOWN_flag;
extern bool LEFT_flag;
extern bool RIGHT_flag;
extern bool HIT_flag;
extern bool HAKO_flag;
extern bool DOOR_flag;
extern bool ITEM_flag;

extern bool Title;
extern bool room[32];
extern bool Rouka1L;
extern bool Rouka1C;
extern bool Rouka1R;
extern bool KouchouL;
extern bool KouchouR;
extern bool ShokuinL;
extern bool ShokuinR;
extern bool HokenL;
extern bool HokenR;

class CObjSwitchALL :public CObj
{
public:
	CObjSwitchALL(float x, float y);
	~CObjSwitchALL() {};
	void Init();
	void Action();
	void Draw();
	bool hoken_door;
private:
	float m_x;
	float m_y;
	float m_vx;
	bool m_del;
	bool HIT_flag;
	int m_time;
	RECT_F m_eff;
};