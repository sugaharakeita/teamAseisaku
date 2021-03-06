#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjInfirmary.h"
#include "GameHead.h"

using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;


//イニシャライズ
void CObjInfirmary::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 800, 15, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//机
	Hits::SetHitBox(this, 15.0f, 15.0f, 60, 205, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//カーテン・ベット（３つ分）
	Hits::SetHitBox(this, 305.0f, 15.0f, 405, 210, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//椅子1
	Hits::SetHitBox(this, 100.0f, 145.0f, 25, 55, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//椅子2
	Hits::SetHitBox(this, 105.0f, 255.0f, 20, 50, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//机
	Hits::SetHitBox(this, 340.0f, 335.0f, 50, 200, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//ソファ
	Hits::SetHitBox(this, 482.0f, 322.0f, 53, 213, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//体重計
	Hits::SetHitBox(this, 690.0f, 430.0f, 35, 150, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//身長測定器
	Hits::SetHitBox(this, 725.0f, 375.0f, 60, 205, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 585.0f, 80, 10, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//下壁
	Hits::SetHitBox(this, 153.0f, 585.0f, 647, 10, ELEMENT_FIELD, OBJ_INFIRMARY, 9);

	//左壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);

	//右壁
	Hits::SetHitBox(this, 780.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);
}

//アクション
void CObjInfirmary::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//下に行くと廊下2-1に出る
	if (hy + 64.0f > 600.0f)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 220;
		g_hero_y = 120;
		return;
	}


}

//ドロー
void CObjInfirmary::Draw()
{
	
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//背景
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 720.0f;
	src.m_bottom = 370.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	

}