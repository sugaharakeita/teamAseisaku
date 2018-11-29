#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

#include "ObjClear.h"
#include "GameHead.h"

using namespace GameL;



//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = false;
}

//アクション
void CObjClear::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjClear::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	Font::StrDraw(L"α版はここまでです", 270, 200, 30, c);
	Font::StrDraw(L"続きはβ版で", 320, 280, 30, c);
	Font::StrDraw(L"Enterキーでタイトルへ",250,360,30,c);
	
}