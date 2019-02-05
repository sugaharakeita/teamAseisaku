//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjConferenceroom.h"
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
void CObjConferenceroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//家庭科室当たり判定
	HitBoxs Hit[17] =
	{
		{ -41,     0,  114,  114, 0, },//左壁
		{ 171,  -344,  458,  458, 1, },//真ん中壁
		{ 726,     0,  114,  114, 2, },//右壁
		{   0,   190,   57,   57, 3, },//棚1(左)
		{   0,   247,   57,   57, 4, },//棚2
		{   0,   304,   57,   57, 5, },//棚3
		{   0,   361,   57,   57, 6, },//棚4
		{  741,  194,   59,   59, 7, },//棚1(右) 
		{  741,  253,   59,   59, 8, },//棚2
		{  741,  312,   59,   59, 9, },//棚3
		{  741,  371,   59,   59, 10, },//棚4
		{  120,  220,  260,  240, 11, },//中央机といす(左)
		{  380,  220,  260,  240, 12, },//中央机といす(右)
		{  225,  505,  327,  327, 13, },//ホワイトボード
		//{ 715,   366,   33,   33, 14, },
		//{ 715,   399,   33,   33, 15, },
		//{ 715,   432,   33,   33, 16, },//11～16まで教卓


	};

	for (int i = 0; i <17; i++)
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
void CObjConferenceroom::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//下に行くと廊下3-1に行く
	if (hy + 64.0f > 600.0f && hx < 500 )
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 400;
		g_hero_y = 100;
		return;
	}

}

//ドロー
void CObjConferenceroom::Draw()
{
	
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 788.0f;
	src.m_bottom = 730.0f;

	//背景１の位置の設定をし描画
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f + m_x1;
	dst.m_right  = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	
}