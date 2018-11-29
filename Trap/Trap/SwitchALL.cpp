#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "SwitchALL.h"
//ヒーロー関係
bool Hero;
int HERO = 3;
int HeroStop;
float HeroX;
float HeroY;
bool UP_flag;
bool DOWN_flag;
bool LEFT_flag;
bool RIGHT_flag;
bool HIT_flag;
bool HAKO_flag;
bool DOOR_flag;
bool ITEM_flag;
//システム関係
int Message;
//部屋関係。LCRはそれぞれ左側、中央側、右側を示す。
int Title;
int room[32];
int Rouka1L;
int Rouka1CL;
int Rouka1CR;
int Rouka1R;
int KouchouL;
int KouchouR;
int ShokuinL;
int ShokuinR;
int HokenL;
int HokenR;

void CObjSwitchALL::Init()
{
	m_x = 0.0f;
	m_y = 476.0f;
}

void CObjSwitchALL::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 600.0f;
	src.m_bottom = 160.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 800.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	if(HokenHakoOpen==true)
	{
		Draw::Draw(7, &src, &dst, c, 0.0f);
		Font::StrDraw(L"保健室のカギを手に入れた", 260, 220, 96, c);
	}
}