#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjTitle.h"
#include "ObjHelp.h"

using namespace GameL;

void CObjHelp::Init()
{

}

void CObjHelp::Action()
{
	if (Input::GetVKey(VK_BACK) == true)
	{
		this->SetStatus(false);
		Scene::SetScene(new CSceneTitle());
	}
}

void CObjHelp::Draw()
{
	float c[4] = { 1,1,1,1 };

	Font::StrDraw(L"W：上に移動", 160, 96, 32, c);
	Font::StrDraw(L"S：下に移動", 160, 144, 32, c);
	Font::StrDraw(L"A：左に移動", 160, 192, 32, c);
	Font::StrDraw(L"D：右に移動", 160, 240, 32, c);
	Font::StrDraw(L"Enter：ドアを開ける/箱を開ける/選択する", 96, 288, 32, c);
	Font::StrDraw(L"X：アイテムボックスを開く", 160, 336, 32, c);
	Font::StrDraw(L"Back：メッセージ/アイテムボックスを閉じる", 112, 384, 32, c);
	Font::StrDraw(L"タイトルへ：Back", 280, 500, 32, c);
}