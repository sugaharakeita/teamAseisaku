//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "ObjBackground.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjBackground::Init()
{
	m_x1 = 0.0f;
	m_x2 = 800.0f;
}

//アクション
void CObjBackground::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//画面左移動
	if (hx < 0.0f)
	{
		m_x1 += 5.0f;
		m_x2 += 5.0f;
		if (m_x2 > 800.0f)
		{
			m_x1 = 0;
		}
	}

	//画面右移動
	if (hx + 64.0f > 800.0f)
	{
		m_x1 -= 5.0f;
		m_x2 -= 5.0f;
		if (m_x1 < -800.0f)
		{
			m_x2 = 0;
		}
	}
}

//ドロー
void CObjBackground::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//背景1-2
	src.m_top = 0.0f;
	src.m_left = 1035.0f;
	src.m_right = 1420.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//背景1-3
	src.m_top = 0.0f;
	src.m_left = 1420.0f;
	src.m_right = 1780.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x2;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

}