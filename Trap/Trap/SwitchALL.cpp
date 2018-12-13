#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "SwitchALL.h"
//ヒーロー関係
bool Hero;
int HERO = 3;//主人公の向き
int HeroStop;//主人公の動きを止める。数字によって止まる向きが変わる。４なら動けず、５なら止まらない
float HeroX;//主人公のＸ座標を取得する
float HeroY;
bool HeroL;//主人公は左側に居る
bool HeroR;
//以下主人公のヒットフラグ
bool HIT_flag;
bool HAKO_flag;
bool DOOR_flag;
bool ITEM_flag;
bool TEXT_flag;
//システム関係
int Message;
int Text;
int Menu;
//部屋関係。LCRはそれぞれ左側、中央側、右側を示す。
int Title;
int room[32];//切り替え用
//切り替え用。roomとは別に動く
int Rouka1L;
int Rouka1CL;
int Rouka1CR;
int Rouka1R;
int Kouchou;
int Shokuin;
int Hoken;
int Rouka2L;
int Rouka2C;
int Rouka2R;
int Kateika;
int KateikaJunbi;
int Kyoushitu;
int Tosho;

void CObjSwitchALL::Init()
{
	m_x = 0.0f;
	m_y = 476.0f;
}

void CObjSwitchALL::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,0.25f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 768.0f;
	src.m_bottom = 614.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 800.0f + m_x;
	dst.m_bottom = 600.0f + m_y;
}