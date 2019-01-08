//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false; //キーフラグ初期化
	m_gameover = false; //ゲームオーバーフラグ初期化
	m_gameover_co = 0; //ゲームオーバーカウント初期化
}

//アクション
void CObjGameOver::Action()
{
	//Enterキーを押したとき
	if (Input::GetVKey(VK_RETURN) == true && m_gameover == false)
	{
		Audio::Start(1);
		m_gameover = true;
		m_key_flag = true;
	}


	//キーフラグがtrueになった時、かつEnterキーを押したらタイトル表示
	//その後キーフラグ・ゲームオーバーフラグ・
	//ゲームオーバーカウント初期化
	if (m_key_flag == true)
	{
		m_gameover_co += 1.0f;
		if (m_gameover_co == 20)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
			m_gameover = false;
			m_gameover_co = 0;
		}
	}
}

//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"げーむおーばー！！", 250, 250, 32, c);
	Font::StrDraw(L"(´＾3 ^`）m9", 250, 300, 32, c);
	Font::StrDraw(L"タイトルへ(EnterKey)", 250, 400, 32, c);

}