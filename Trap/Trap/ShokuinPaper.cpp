#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include <windows.h>
#include "ShokuinPaper.h"
#include "GameHead.h"
#include "SwitchALL.h"

using namespace GameL;

CObjShokuinPaper::CObjShokuinPaper(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjShokuinPaper::Init()
{
	m_time = 0;
	Hit_flag = 0;

	Hits::SetHitBox(this, m_x, m_y, 60, 68, ELEMENT_OBJECT, OBJ_TEXTURE, 1);
}

void CObjShokuinPaper::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (Hit_flag == 1 && Input::GetVKey(VK_RETURN) == true)
		Text = 1;//1番目にセットしたテキストを表示する

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		Hit_flag = 1;
	else
		Hit_flag = 0;
}

void CObjShokuinPaper::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 27.0f;
	src.m_right = 42.0f;
	src.m_bottom = 17.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 60.0f + m_x;
	dst.m_bottom = 68.0f + m_y;

	Draw::Draw(3, &src, &dst, c, 0.0f);
}