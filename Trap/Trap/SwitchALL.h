#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

extern bool Hero;
extern int HERO;
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

extern int Message;

extern int Title;
extern int room[32];
extern int Rouka1L;
extern int Rouka1CL;
extern int Rouka1CR;
extern int Rouka1R;
extern int KouchouL;
extern int KouchouR;
extern int ShokuinL;
extern int ShokuinR;
extern int HokenL;
extern int HokenR;

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