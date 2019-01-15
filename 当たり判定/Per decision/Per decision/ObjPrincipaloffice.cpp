#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjPrincipaloffice.h"
#include "GameHead.h"

using namespace GameL;



//イニシャライズ
void CObjPrincipaloffice::Init()
{
	//上壁
	Hits::SetHitBox(this, 0.0f, 0.0f, 800, 110, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//観葉植物1
	Hits::SetHitBox(this, 0.0f, 110.0f, 80, 30, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//観葉植物2
	Hits::SetHitBox(this, 720.0f, 110.0f, 80, 30, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//椅子1
	Hits::SetHitBox(this, 350.0f, 170.0f, 65, 50, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//棚1
	Hits::SetHitBox(this, 0.0f, 175.0f, 100, 160, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//机1
	Hits::SetHitBox(this, 300.0f, 230.0f, 165, 60, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//棚2
	Hits::SetHitBox(this, 700.0f, 290.0f, 100, 160, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//椅子2
	Hits::SetHitBox(this, 155.0f, 350.0f, 88, 90, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//机2
	Hits::SetHitBox(this, 348.0f, 355.0f, 86, 85, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//椅子3
	Hits::SetHitBox(this, 535.0f, 350.0f, 90, 90, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//棚3
	Hits::SetHitBox(this, 0.0f, 430.0f, 100, 155, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//敷居
	Hits::SetHitBox(this, 203.0f, 460.0f, 422, 75, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//下壁
	Hits::SetHitBox(this, 0.0f, 586.0f, 580, 20, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//下壁
	Hits::SetHitBox(this, 690.0f, 586.0f, 110, 20, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

}

//アクション
void CObjPrincipaloffice::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	if (hy + 64.0f > 580.0f)
	{
		Hits::DeleteHitBox(this);
	}

}

//ドロー
void CObjPrincipaloffice::Draw()
{
	/*
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//背景
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 470.0f;
	src.m_bottom = 730.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	*/

}