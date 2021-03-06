#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjStaffroom.h"
#include "GameHead.h"


using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;


//イニシャライズ
void CObjStaffroom::Init()
{
	//棚
	Hits::SetHitBox(this, 65.0f, 0.0f, 103, 120, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//棚
	Hits::SetHitBox(this, 168.0f, 0.0f, 110, 140, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//壁
	Hits::SetHitBox(this, 278.0f, 0.0f, 160, 120, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//棚
	Hits::SetHitBox(this, 438.0f, 0.0f, 50, 140, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//壁
	Hits::SetHitBox(this, 488.0f, 0.0f, 244, 120, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//左から一番目の机
	Hits::SetHitBox(this, 75.0f, 241.0f, 40, 150, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//左から二番目の上側の机
	Hits::SetHitBox(this, 175.0f, 205.0f, 160, 70, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//左から二番目の下側の机
	Hits::SetHitBox(this, 175.0f, 383.0f, 160, 70, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//左から三番目の上側の机
	Hits::SetHitBox(this, 440.0f, 205.0f, 245, 70, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//左から三番目の下側の机
	Hits::SetHitBox(this, 440.0f, 383.0f, 245, 70, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//ロッカー
	Hits::SetHitBox(this, 745.0f, 362.0f, 55, 238, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//印刷機
	Hits::SetHitBox(this, 315.0f, 532.0f, 33, 55, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//左壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);

	//右壁
	Hits::SetHitBox(this, 780.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);

}


//アクション
void CObjStaffroom::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//主人公のy座標が120.0f以下になると廊下1-1へ移動1
	if (hy < 50.0f && hx < 70.0f)
	{
		g_hero_x = 100;
		g_hero_y = 520;
		Scene::SetScene(new CSceneCorridor());
	}

	//主人公のy座標が120.0f以下になると廊下1-1へ移動2
	if (hy < 50.0f &&  hx + 64.0f > 750.0f)
	{
		g_hero_x = 650;
		g_hero_y = 520;
		Scene::SetScene(new CSceneCorridor());
	}

}

//ドロー
void CObjStaffroom::Draw()
{
	
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//背景
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 896.0f;
	src.m_bottom = 640.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	

}