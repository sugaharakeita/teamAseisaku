//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjPrologue.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjPrologue::Init()
{

}

//アクション
void CObjPrologue::Action()
{
	//エンターキーを押してシーン：ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
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