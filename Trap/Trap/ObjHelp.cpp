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

	Font::StrDraw(L"W�F��Ɉړ�", 160, 96, 32, c);
	Font::StrDraw(L"S�F���Ɉړ�", 160, 144, 32, c);
	Font::StrDraw(L"A�F���Ɉړ�", 160, 192, 32, c);
	Font::StrDraw(L"D�F�E�Ɉړ�", 160, 240, 32, c);
	Font::StrDraw(L"Enter�F�h�A���J����/�����J����/�I������", 96, 288, 32, c);
	Font::StrDraw(L"X�F�A�C�e���{�b�N�X���J��", 160, 336, 32, c);
	Font::StrDraw(L"Back�F���b�Z�[�W/�A�C�e���{�b�N�X�����", 112, 384, 32, c);
	Font::StrDraw(L"�^�C�g���ցFBack", 280, 500, 32, c);
}