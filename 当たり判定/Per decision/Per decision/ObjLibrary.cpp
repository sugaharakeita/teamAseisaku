//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjLibrary.h"

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;
//
//extern float g_enemy_x = 150.0f;
//extern float g_enemy_y = 0.0f;
//


//イニシャライズ
void CObjLibrary::Init()
{
	m_x1 = 0.0f;

	//教室当たり判定
	HitBoxs Hit[31] =
	{
		{   0, 	 -674,   800,  800, 0, },//上、壁
		{ 765,    126,   474,  474, 1, },//右の本棚
		{-590,    126,   600,  600, 2, },//左の壁
		{  71,    129,    29,   29, 3, },//左のカウンター1(上から)
		{  71,    158,    29,   29, 4, },//左のカウンター2
		{  71,    187,    29,   29, 5, },//左のカウンター3
		{  71,    216,    29,   29, 6, },//左のカウンター4
		{  71,    245,    29,   29, 7, },//左のカウンター5
		{  71,    274,    29,   29, 8, },//左のカウンター6
		{ 253,    151,    65,   65, 9, },//左上の本棚1(上から)
		{ 253,    216,    65,   65, 10, },//左上の本棚2
		{ 371,    171,    90,   90, 11, },//左側の机
		{ 521,    171,    90,   90, 12, },//右側の机
		{ 371,    350,    45,   45, 13, },//左側の机の下の本棚(左側)
		{ 416,    350,    45,   45, 14, },//右側の机の下の本棚(右側)
		{ 521,    350,    45,   45, 15, },//右側の机の下の本棚(左側)
		{ 566,    350,    45,   45, 16, },//右側の机の下の本棚(右側)
		{ 222,    434,    26,   26, 17, },//左下の本棚1(上から)
		{ 222,    460,    26,   26, 18, },//左下の本棚2(上から)
		{ 222,    486,    26,   26, 19, },//左下の本棚3(上から)
		{ 222,    512,    26,   26, 20, },//左下の本棚4(上から)
		{ 222,    538,    26,   26, 21, },//左下の本棚5(上から)
		{ 222,    564,    26,   18, 22, },//左下の本棚6(上から)
		{ 270,    507,    76,   76, 23, },//下の本棚(背を向けてるやつ)1(左から)
		{ 346,    507,    76,   76, 24, },//下の本棚2
		{ 422,    507,    76,   76, 25, },//下の本棚3
		{ 498,    507,    76,   76, 26, },//下の本棚4
		{ 574,    507,    76,   76, 27, },//下の本棚5
		{ 650,    507,    70,   76, 28, },//下の本棚6
		{  10,    583,   121,  121, 29, },//左下の壁(入口から見て左側)
		{ 190,    583,   575,  625, 30, },//右下の壁(入口から見て右側)
		

	};

	for (int i = 0; i <31; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//アクション
void CObjLibrary::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	////敵の位置
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();


	//上に行くと廊下2-1に出る
	if (hy > 450 == true)
	{
		if (m_key_flag == true)
		{
			//主人公
			g_hero_x = hx;
			g_hero_y = 450;
			//敵
			//g_enemy_x = 110;

			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	


}

//ドロー
void CObjLibrary::Draw()
{
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

				//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 852.0f;
	src.m_bottom = 506.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);



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