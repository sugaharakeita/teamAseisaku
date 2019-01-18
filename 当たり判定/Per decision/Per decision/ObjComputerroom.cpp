//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjComputerroom.h"
//#include "ObjHitBoxHER.h"//家庭科室

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;
//
//extern float g_enemy_x = 150.0f;
//extern float g_enemy_y = 0.0f;
//


//イニシャライズ
void CObjComputerroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//家庭科室当たり判定
	HitBoxs Hit[35] =
	{
		{    0, -708, 800, 800, 0, },//上壁
		{   77,   90,  57,  57, 1, },//教卓(上)
		{   67,  147,  67,  67, 2, },//教卓(下)
		{    0,  150,  16, 325, 3, },//ホワイトボード
		{  170,  112,  80,  80, 4, },//机1(上)
		{  250,  112,  80,  80, 5, },//机2
		{  330,  112,  80,  80, 6, },//机3
		{  410,  112,  80,  80, 7, },//机4
		{  490,  112,  80,  80, 8, },//机5
		{  570,  112,  80,  80, 9, },//机6
		{  650,  142,  27,  27, 10, },//机左端2分割(上)
		{  650,  169,  27,  23, 11, },//机左端2分割(下)
		{  170,  258,  80,  80, 12, },//机1(中)
		{  250,  258,  80,  80, 13, },//机2
		{  330,  258,  80,  80, 14, },//机3
		{  410,  258,  80,  80, 15, },//机4
		{  490,  258,  80,  80, 16, },//机5
		{  570,  258,  80,  80, 17, },//机6
		{  650,  287,  27,  27, 18, },//机左端2分割(上)
		{  650,  314,  27,  24, 19, },//机左端2分割(下)
		{  170,  422,  60,  60, 20, },//机1(下)
		{  230,  422,  60,  60, 21, },//机2
		{  290,  422,  60,  60, 22, },//机3
		{  350,  422,  60,  60, 23, },//机4
		{  410,  422,  60,  60, 24, },//机5
		{  470,  422,  60,  60, 25, },//机6
		{  530,  422,  60,  60, 26, },//机7
		{  590,  422,  60,  60, 27, },//机8
		{  650,  433,  25,  27, 28, },//机左端2分割(上)
		{  650,  460,  25,  22, 29, },//机左端2分割(下)
		{    0,  587, 725, 800, 30, },//下壁
		{  790,   92, 600, 600, 31, },//右端壁
	};

	for (int i = 0; i <35; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//アクション
void CObjComputerroom::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	////敵の位置
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();


	//上に行くと廊下2-1に行く
	if (hy > 500 == true && hy < 600 == true)
	{
		if (m_key_flag == true)
		{
			//主人公
			g_hero_x = hx;
			g_hero_y = 550;
			//敵
			//g_enemy_x = 110;

			//Scene::SetScene(new CSceneMain9());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}



}

//ドロー
void CObjComputerroom::Draw()
{
	/*
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 788.0f;
	src.m_bottom = 698.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);
	*/



	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		//背景１の位置の設定をし描画
	//		dst.m_top = 0.0f;
	//		dst.m_left = 0.0f + m_scroll;
	//		dst.m_right = 1716.0f + m_scroll;
	//		dst.m_bottom = 600.0f;
	//		Draw::Draw(0, &src, &dst, c, 0.0f);

	//	}
	//}

}