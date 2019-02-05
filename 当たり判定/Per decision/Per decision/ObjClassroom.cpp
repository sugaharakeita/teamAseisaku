//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjClassroom.h"
#include "ObjHitBox.h"

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//イニシャライズ
void CObjClassroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//教室当たり判定
	HitBoxs Hit[26] =
	{
		{ -208,     0,   220,  220,  0, },//上、左壁
		{ 90,  -477,   620,  620,  1, },//上、真ん中の壁
		{ 788,     0,   479,  479,  2, },//右壁
		{ -167,   220,   190,  190,  3, },//黒板
		{ -208,   410,   220,  220,  4, },//下、左壁
		{ 749,   479,   121,  121,  5, },//右下、棚
		{ 12,   578,   737,  737,  6, },//下壁
		{ 82,   305,    39,   39,  7, },//教卓
		{ 162,   198,    48,   48,  8, },//机上右から1
		{ 260,   198,    48,   48,  9, },//机上右から2
		{ 360,   198,    48,   48, 10, },//机上右から3
		{ 460,   198,    48,   48, 11, },//机上右から4
		{ 552,   198,    48,   48, 12, },//机上右から5
		{ 642,   196,    48,   48, 13, },//机上右から6
		{ 163,   314,    48,   48, 14, },//机真ん中右から1
		{ 260,   314,    48,   48, 15, },//机真ん中右から2
		{ 361,   314,    48,   48, 16, },//机真ん中右から3
		{ 460,   314,    48,   48, 17, },//机真ん中右から4
		{ 552,   314,    48,   48, 18, },//机真ん中右から5
		{ 646,   311,    48,   48, 19, },//机真ん中右から6
		{ 164,   431,    48,   48, 20, },//机下右から1
		{ 261,   431,    48,   48, 21, },//机下右から2
		{ 362,   431,    48,   48, 22, },//机下右から3
		{ 460,   428,    48,   48, 23, },//机下右から4
		{ 554,   428,    48,   48, 24, },//机下右から5
		{ 650,   426,    48,   48, 25, },//机下右から6

	};

	for (int i = 0; i <26; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}

	//左壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);

	//右壁
	Hits::SetHitBox(this, 780.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);


}

//アクション
void CObjClassroom::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//左のドアに行くと廊下2-3に出る
	if (hy < 100 && hx < 50)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 50;
		g_hero_y = 440;
	}

	//右のドアに行くと廊下2-3に出る
	if (hy < 100 && hx > 650)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 600;
		g_hero_y = 400;
	}
}

//ドロー
void CObjClassroom::Draw()
{
	
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 660.0f;
	src.m_bottom = 442.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	
}