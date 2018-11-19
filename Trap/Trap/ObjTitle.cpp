#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjTitle.h"
#include "SceneRouka1.h"

using namespace GameL;

void CObjTitle::Init()
{
	
}

void CObjTitle::Action()
{
	if (Input::GetVKey('\n') == true)
	{
		
	}
}

void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };

	Font::StrDraw(L"School",20,32,16,c);
}