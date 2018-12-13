#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

extern int KouchouKey;
extern bool Kou_flag;
extern int HokenKey;
extern bool Hok_flag;
extern int Hammer;
extern bool Ham_flag;
extern int Kateika_Key;
extern bool Kate_flag;
extern int Tosho_Key;
extern bool Tosho_flag;

class CObjItemALL :public CObj
{
public:
	CObjItemALL(float x, float y);
	~CObjItemALL() {};
	static int ItemALL;
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	bool m_del;
	int m_time;
	static char ITEM[36];
	RECT_F m_eff;
};