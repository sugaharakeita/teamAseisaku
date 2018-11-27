#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "SwitchALL.h"
//ヒーロー関係
bool Hero;
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
//部屋関係。LCRはそれぞれ左側、中央側、右側を示す。
bool Title;
bool room[32];
bool Rouka1L;
bool Rouka1C;
bool Rouka1R;
bool KouchouL;
bool KouchouR;
bool ShokuinL;
bool ShokuinR;
bool HokenL;
bool HokenR;

void CObjSwitchALL::Init()
{
	m_x = 0.0f;
	m_y = 476.0f;
	Draw::LoadImage(L"メッセージウィンドウ.png", 0, TEX_SIZE_512);
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