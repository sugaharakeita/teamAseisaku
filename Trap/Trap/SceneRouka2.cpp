#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneRouka2.h"
#include "Hero.h"
#include "GameHead.h"

CSceneRouka2::CSceneRouka2()
{

}

CSceneRouka2::~CSceneRouka2()
{

}

void CSceneRouka2::InitScene()
{
	//表示する画像の読み取り
	Draw::LoadImage(L"メッセージウィンドウ.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"アイテム全部.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"廊下2全体図.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"家庭科室完成版", 11, TEX_SIZE_512);
	Draw::LoadImage(L"家庭科準備室完成版.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"教室完成版.png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"図書室完成版.png", 14, TEX_SIZE_512);
	//２階廊下オブジェクトの作成
	CObjRouka2* r4 = new CObjRouka2();
	Objs::InsertObj(r4, SPOT_ROUKA2, 0);
	//主人公オブジェクトの作成
	CObjHero* h = new CObjHero(0.0f, 0.0f);
	if (room[7] == 1)//２階廊下左側に居る場合
	{
		if (Rouka2C == 1)//２階廊下中央側から移った場合
			CObjHero* h = new CObjHero(736.0f, 128.0f);
		else if (Kateika == 1)//家庭科室から移った場合
			CObjHero* h = new CObjHero(0.0f, 128.0f);
		else if (Tosho == 1)//図書室から移った場合
			CObjHero* h = new CObjHero(0.0f, 536.0f);
		//家庭科室の扉オブジェクトの作成
		CObjKateikaDoor* d4 = new CObjKateikaDoor(0.0f,0.0f);
		Objs::InsertObj(d4, KATEIKA_DOOR, 0);
		CObjKateikaDoor* d4 = new CObjKateikaDoor(0.0f, 0.0f);
		Objs::InsertObj(d4, KATEIKA_DOOR, 0);
		//図書室の扉オブジェクトの作成
		CObjToshoDoor* d7 = new CObjToshoDoor(0.0f, 0.0f);
		Objs::InsertObj(d7, TOSHO_DOOR, 0);


	}
	else if (room[8] == 1)//２階廊下中央に居る場合
	{
		if (Rouka2L == 1)//２階廊下左側から移った場合
			CObjHero* h = new CObjHero(0.0f, 128.0f);
		else if (Rouka2R == 1)//２階廊下右側から移った場合
			CObjHero* h = new CObjHero(736.0f, 128.0f);
		else if (Kyoushitu == 1)//教室から移った場合
			CObjHero* h = new CObjHero(736.0f, 536.0f);
		if (Rouka1CR == 1)//１階廊下中央右側から移った場合。２階のスタート位置
			CObjHero* h = new CObjHero(736.0f, 128.0f);
		//家庭科準備室の扉オブジェクトの作成
		CObjKateikaJunbiDoor* d5 = new CObjKateikaJunbiDoor(0.0f, 0.0f);
		Objs::InsertObj(d5, KATEIKAJUNBI_DOOR, 0);
		//教室の扉オブジェクトの作成
		CObjKyoushituDoor* d6 = new CObjKyoushituDoor(0.0f, 0.0f);
		Objs::InsertObj(d6, KYOUSHITU_DOOR, 0);


	}
	else if (room[9] == 1)//２階廊下右側に居る場合
	{
		if (Rouka2C == 1)//２階廊下中央側から移った場合
			CObjHero* h = new CObjHero(0.0f, 128.0f);
		else if (Kyoushitu == 1)//教室から移った場合
			CObjHero* h = new CObjHero(736.0f, 536.0f);
		//教室の扉オブジェクトの作成
		CObjKyoushituDoor* d6 = new CObjKyoushituDoor(0.0f, 0.0f);
		Objs::InsertObj(d6, KYOUSHITU_DOOR, 0);


	}
	Objs::InsertObj(h, OBJ_HERO, 2);
	//発見オブジェクトの作成
	CObjExcla* x = new CObjExcla(HeroX + 8, HeroY + 8);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	//テキスト表示用オブジェクトの作成
	CObjTextALL* m = new CObjTextALL(0.0f, 0.0f);
	Objs::InsertObj(m, OBJ_TEXTURE, 3);
	//メッセージ表示用オブジェクトの作成
	CObjMessage* m1 = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m1, OBJ_MESSAGE, 3);
	//メニュー表示用オブジェクトの作成
	CObjMenu* m2 = new CObjMenu(0.0f, 0.0f);
	Objs::InsertObj(m2, OBJ_MENU, 3);
	//所持状況に応じて生成するもの


}

void CSceneRouka2::Scene()
{

}