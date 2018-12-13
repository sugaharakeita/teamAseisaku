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

	Hits::SetHitBox(this, m_x, m_y, 36, 48, ELEMENT_OBJECT, OBJ_TEXTURE, 1);
}

void CObjShokuinPaper::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (HIT_flag == true)
	{
		if (Input::GetVKey(VK_RETURN) == true)
			Text = 1;
	}

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		HIT_flag = true;
	else
		HIT_flag = false;
}

void CObjShokuinPaper::Draw()
{
	float c[4] = { 0.45f,0.45f,0.45f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 190.0f;
	src.m_right = 356.0f;
	src.m_bottom = 214.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 36.0f + m_x;
	dst.m_bottom = 48.0f + m_y;

	Draw::Draw(3, &src, &dst, c, 0.0f);
}