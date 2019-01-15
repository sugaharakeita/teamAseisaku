//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"


#include"GameHead.h"
#include"ObjPrologue.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjPrologue::Init()
{
	m_key_flag = false; //キーフラグ初期化
	m_start = false; //スタートフラグ初期化
	m_start_co = 0; //スタートカウント初期化
}

//アクション
void CObjPrologue::Action()
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
			Scene::SetScene(new CSceneCorridor());
			m_key_flag = false;
			m_start = false;
			m_start_co = 0;
		}
	}

}

//ドロー
void CObjPrologue::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"あらすじ", 50, 100, 32, c);
	Font::StrDraw(L"主人公は忘れ物を取りに学校へ訪れた。", 50, 150, 32, c);
	Font::StrDraw(L"そこで、主人公は様々な怪異に出会う・・・", 50, 200, 32, c);
	Font::StrDraw(L"怪異の目を掻い潜りながら", 150, 300, 40, c);
	Font::StrDraw(L"屋上を目指し、脱出しよう☆", 150, 350, 40, c);
	Font::StrDraw(L"EnterでLet's go!!", 250, 500, 32, c);


}