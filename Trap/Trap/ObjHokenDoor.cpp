#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "ObjHokenDoor.h"
#include "GameHead.h"
#include "TrapALL.h"

using namespace GameL;

CObjHokenDoor::CObjHokenDoor(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjHokenDoor::Init()
{
	m_time = 0;
	hoken_door = false;
	
	Hits::SetHitBox(this, m_x, m_y, 128, 160, ELEMENT_DOOR, HOKEN_DOOR, 1);
}

void CObjHokenDoor::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	if (HokenDoorOpen == true)
	{
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
			HIT_flag = true;
		else
			HIT_flag = false;
	}
	else
	{
		if (hit->CheckObjNameHit(HOKEN_KEY) != nullptr)
			HIT_flag = true;
		else
			HIT_flag = false;
	}
	
	if (HIT_flag == true && hoken_door == false)
	{
		if (Input::GetVKey('A') == true)
		{
			m_x -= 64;
			hoken_door = true;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, 0, 0, 800, 600, ELEMENT_WALL, OBJ_WALL, 1);
			hit->SetPos(0, 0);

			HokenDoorOpen = true;
			/*このままではシーン移動のたびに鍵が閉まるので、
			鍵が開いた状態をシーンが変わっても維持したい!
			グローバル変数はexternを使っても多重定義になるし、
			クラス化しても多重使用になってしまう…*/
		}
	}
	
	if (hoken_door == true)
		m_time++;
	if (m_time >= 80)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneRouka1());
	}
}

void CObjHokenDoor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 384.0f;
	src.m_right = 448.0f;
	src.m_bottom = 64.0f;
	
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 128.0f + m_x;
	dst.m_bottom = 160.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}