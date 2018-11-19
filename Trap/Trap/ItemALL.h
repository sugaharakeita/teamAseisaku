#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

class CObjItemALL :public CObj
{
public:
	CObjItemALL(float x, float y);
	~CObjItemALL() {};
	static int ItemALL;
	void Init();
	void Action();
	void Draw();
	int hammer;
	bool ham_flag;
	int kouchoukey;
	bool kouchoukey_flag;
	int hokenkey;
	bool hokenkey_flag;
	int toshokey;
	bool toshokey_flag;
	int kateikajunbikey;
	bool kateikajunbikey_flag;
	int salt;
	bool salt_flag;
	int cup;
	int kateikakey;
	bool kateikakey_flag;
	bool water_flag;
	int saltwater;
	bool saltwater_flag;
	int kyoushitukey;
	bool kyoushitukey_flag;
	int PCkey;
	bool PCkey_flag;
	int kaigikey;
	bool kaigikey_flag;
	int ongakukey;
	bool ongakukey_flag;
	int gakuf;
	bool gakufu_flag;
	int parachute;
	bool parachute_flag;
	int giftA;
	bool giftA_flag;
	int giftB;
	bool giftB_flag;
	int giftC;
	bool giftC_flag; //ç°ÇÕégÇÌÇ»Ç¢Ç‡ÇÃÇ‡íuÇ¢ÇƒÇ†ÇÈ
private:
	float m_x;
	float m_y;
	float m_vx;
	bool m_del;
	bool Hero;
	bool UP_flag;
	bool LEFT_flag;
	bool RIGHT_flag;
	bool DOWN_flag;
	bool HIT_flag;
	bool HAKO_flag;
	bool DOOR_flag;
	int flag;
	bool t_flag;
	int m_time;
	static char ITEM[36];
	RECT_F m_eff;
};