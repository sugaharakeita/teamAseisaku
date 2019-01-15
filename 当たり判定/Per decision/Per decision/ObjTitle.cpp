#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "ObjTitle.h"
#include "GameHead.h"

using namespace GameL;



//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false; //キーフラグ初期化
	m_start = false; //スタートフラグ初期化
	m_start_co = 0; //スタートカウント初期化
}

//アクション
void CObjTitle::Action()
{
	//Enterキーを押したとき
	if (Input::GetVKey(VK_RETURN) == true && m_start == false)
	{
		Audio::Start(1);
		m_start = true;
		m_key_flag = true;
	}

	//キーフラグがtrueになった時、かつEnterキーを押したら廊下1-2表示
	//その後キーフラグ・スタートフラグ・スタートカウント初期化
	if (m_key_flag == true)
	{
		m_start_co += 1.0f;
		if (m_start_co == 20)
		{
			Scene::SetScene(new CScenePrologue());
			m_key_flag = false;
			m_start = false;
			m_start_co = 0;
		}
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