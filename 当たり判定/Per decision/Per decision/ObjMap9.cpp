//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjMap9.h"

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;


//イニシャライズ
void CObjMap9::Init()
{
	m_x1 = 0.0f;


	//廊下2-3当たり判定
	HitBoxs Hit[3] =
	{
		{ 0, -625,  800, 800, 0, },//上の壁
		{ 778,  175,  465, 465, 1, },//一番右端
		{ 143,  495,  494, 494, 2, },//家庭科室扉(後ろ側)右側の壁
									 //{ 563, 495, 127, 127, 4, },//家庭科室扉(前側)右側の壁

	};
	for (int i = 0; i < 5; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//アクション
void CObjMap9::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	
	if (hx < 60.0f)
	{
		Hits::DeleteHitBox(this);
	}
	

	//下に行くと三階・PC室に行く
	if (hy > 450 == true)
	{
		Scene::SetScene(new CSceneComputerroom());
		g_hero_x = 650;
		g_hero_y = hy;
		m_key_flag = false;
	}



}

//ドロー
void CObjMap9::Draw()
{
	/*
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置


	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 360.0f;
	src.m_bottom = 362.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	*/




}