#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjPrincipaloffice.h"
#include "GameHead.h"

using namespace GameL;



//ƒCƒjƒVƒƒƒ‰ƒCƒY
void CObjPrincipaloffice::Init()
{
	//ã•Ç
	Hits::SetHitBox(this, 0.0f, 0.0f, 800, 110, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//ŠÏ—tA•¨1
	Hits::SetHitBox(this, 0.0f, 110.0f, 80, 30, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//ŠÏ—tA•¨2
	Hits::SetHitBox(this, 720.0f, 110.0f, 80, 30, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//ˆÖŽq1
	Hits::SetHitBox(this, 350.0f, 170.0f, 65, 50, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//’I1
	Hits::SetHitBox(this, 0.0f, 175.0f, 100, 160, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//Š÷1
	Hits::SetHitBox(this, 300.0f, 230.0f, 165, 60, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//’I2
	Hits::SetHitBox(this, 700.0f, 290.0f, 100, 160, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//ˆÖŽq2
	Hits::SetHitBox(this, 155.0f, 350.0f, 88, 90, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//Š÷2
	Hits::SetHitBox(this, 348.0f, 355.0f, 86, 85, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//ˆÖŽq3
	Hits::SetHitBox(this, 535.0f, 350.0f, 90, 90, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//’I3
	Hits::SetHitBox(this, 0.0f, 430.0f, 100, 155, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//•~‹
	Hits::SetHitBox(this, 203.0f, 460.0f, 422, 75, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//‰º•Ç
	Hits::SetHitBox(this, 0.0f, 586.0f, 580, 20, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

	//‰º•Ç
	Hits::SetHitBox(this, 690.0f, 586.0f, 110, 20, ELEMENT_FIELD, OBJ_PRINCIPALOFFICE, 9);

}

//ƒAƒNƒVƒ‡ƒ“
void CObjPrincipaloffice::Action()
{
	//ŽålŒö‚ÌˆÊ’u‚ðŽæ“¾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	/*
	//‰æ–Ê’[‰º‚És‚­‚Æ˜L‰º1-1‚ÖˆÚ“®
	if (hy +64.0f > 600.0f && 580.0f < hx < 690.0f)
	{
	Scene::SetScene(new CSceneCorridor1_1());
	}
	*/
}

//ƒhƒ[
void CObjPrincipaloffice::Draw()
{
	//•`‰æƒJƒ‰[î•ñ
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//”wŒi
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 470.0f;
	src.m_bottom = 730.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

}