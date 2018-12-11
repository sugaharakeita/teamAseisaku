#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

extern bool Hero;
extern int HERO;
extern int HeroStop;
extern float HeroX;
extern float HeroY;
extern bool HeroL;
extern bool HeroR;
extern bool HIT_flag;
extern bool HAKO_flag;
extern bool DOOR_flag;
extern bool ITEM_flag;

extern int Message;
extern int Menu;

extern int Title;
extern int room[32];
extern int Rouka1L;
extern int Rouka1CL;
extern int Rouka1CR;
extern int Rouka1R;
extern int Kouchou;
extern int Shokuin;
extern int Hoken;

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