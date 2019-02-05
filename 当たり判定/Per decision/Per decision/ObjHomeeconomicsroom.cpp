//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjHomeeconomicsroom.h"
#include "ObjHitBox.h"

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//イニシャライズ
void CObjHomeeconomicsroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//家庭科室当たり判定
	HitBoxs Hit[20] =
	{
		{ -58, 	0,	128,  128,  0, },//左壁
		{ 130,  -413,  541,  541,  1, },//真ん中壁
		{ 731,     0,  128,  128,  2, },//右壁
		{ 0,   584,  400,  400,  3, },//下
		{ 400,   584,  400,  400,  4, },//下
		{ -399,   146,  438,  438,  5, },//左棚
		{ 170,   190,  110,  110,  6, },//上、左の机1
		{ 200,   190,  110,  110,  7, },//上、左の机2
		{ 363,   190,  130,  120,  8, },//上、真ん中の机
		{ 550,   190,  125,  120,  9, },//上、右の机
		{ 167,   410,  128,  125, 10, },//下、左の机
		{ 367,   410,  125,  125, 11, },//下、真ん中の机
		{ 545,   410,  120,  120, 12, },//下、右の机
		{ 715,   295,   33,   35, 13, },
		{ 715,   330,   33,   35, 14, },
		{ 715,   365,   33,   35, 15, },
		{ 715,   400,   33,   35, 16, },//11～15まで教卓
		{ 790,   129,   70,   70 ,17, },


	};

	for (int i = 0; i <20; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}

	//左壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);

	//右壁
	Hits::SetHitBox(this, 780.0f, 0.0f, 20, 200, ELEMENT_FIELD, OBJ_ROOM, 9);

	Hits::SetHitBox(this, 780.0f, 280.0f, 20, 400, ELEMENT_FIELD, OBJ_ROOM, 9);

}

//アクション
void CObjHomeeconomicsroom::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//廊下2-1に行く(左側のドア)
	if (hy < 100 && hx < 100)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 50;
		g_hero_y = 500;
		return;
	}

	//廊下2-1に行く(右側のドア)
	if (hy < 100 && hx > 200)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 500;
		g_hero_y = 500;
		return;
	}

	//右に行くと二階・家庭準備室
	if (hx +64.0f > 800.0f)
	{
		Scene::SetScene(new CSceneHomepreparationroom);
		g_hero_x = 10;
		g_hero_y = 200;
		return;
	}

}

//ドロー
void CObjHomeeconomicsroom::Draw()
{
	
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 852.0f;
	src.m_bottom = 506.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);



}