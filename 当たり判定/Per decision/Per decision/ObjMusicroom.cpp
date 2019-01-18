//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMusicroom.h"
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
void CObjMusicroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//家庭科室当たり判定
	HitBoxs Hit[17] =
	{
		{   0,-685,	800,  800, 0, },//上壁
		{ 153, 175,  65,   65, 1, },//机1(左上から)
		{ 261, 175,  65,   65, 2, },//机2
		{ 375, 175,  65,   65, 3, },//机3
		{ 152, 355,  65,   65, 4, },//机4(左下から)
		{ 261, 355,  65,   65, 5, },//机5
		{ 377, 356,  65,   65, 6, },//机6
		{ 580, 167, 135,  110, 7, },//グランドピアノ
		{ 599, 314,  66,  66, 8, },//舞台(上)
		{ 599, 380,  66,  56, 9, },//舞台(下)
		{ 133, 545,  150,  150, 10, },//楽譜台
		{ 335, 515,  55,  70, 11, },//コントラバス
		{ 625, 520, 153,  153, 12, },//太鼓
		//{ 715,   333,   33,   33, 13, },
		//{ 715,   366,   33,   33, 14, },
		//{ 715,   399,   33,   33, 15, },
		//{ 715,   432,   33,   33, 16, },//11～16まで教卓


	};

	for (int i = 0; i <17; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//アクション
void CObjMusicroom::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//下に行くと廊下3-1に行く
	if (hy + 64.0f > 600.0f && hx > 480 && hx < 600)
	{
		//Scene::SetScene(new CSceneMain7());
		g_hero_x = 650;
		g_hero_y = 125;
		return;
	}


}

//ドロー
void CObjMusicroom::Draw()
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
	src.m_bottom = 722.0f;

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