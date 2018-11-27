#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "SwitchALL.h"
#include "ObjTitle.h"
#include "SceneRouka1.h"

using namespace GameL;

void CObjTitle::Init()
{
	
}

void CObjTitle::Action()
{
	if (Input::GetVKey(VK_SPACE) == true)
	{
		this->SetStatus(false);
		Scene::SetScene(new CSceneHelp());
	}
	if (Input::GetVKey(VK_RETURN) == true)
	{
		this->SetStatus(false);
		Scene::SetScene(new CSceneRouka1());
		Rouka1C = room[0] = Title = 1;
	}
}

void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };

	Font::StrDraw(L"School",260,220,96,c);
	Font::StrDraw(L"スタート：Enter", 280, 400, 32, c);
	Font::StrDraw(L"操作説明：Space", 280, 500, 32, c);
}