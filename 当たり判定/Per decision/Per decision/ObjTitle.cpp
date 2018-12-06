#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

#include "ObjTitle.h"
#include "GameHead.h"

using namespace GameL;



//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
}

//アクション
void CObjTitle::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneCorridor1_2());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjTitle::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	Font::StrDraw(L"School",280, 200, 80, c);
	Font::StrDraw(L"Enterキーでスタート", 260, 400, 30, c);

}