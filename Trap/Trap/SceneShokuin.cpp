#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneShokuin.h"
#include "Hero.h"
#include "GameHead.h"

CSceneShokuin::CSceneShokuin()
{

}

CSceneShokuin::~CSceneShokuin()
{

}

void CSceneShokuin::InitScene()
{
	//表示する画像の読み取り
	Draw::LoadImage(L"メッセージウィンドウ.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"001.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"!.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"アイテム全部.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"廊下1-1.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"職員室.png", 8, TEX_SIZE_512);
	//職員室オブジェクトの作成
	CObjShokuin* r2 = new CObjShokuin();
	Objs::InsertObj(r2, SPOT_SHOKUIN, 0);
	//主人公オブジェクトの作成
	CObjHero* h = new CObjHero(0.0f, 0.0f);
	if(Rouka1L==1)//１階廊下左側から移った場合
		CObjHero* h = new CObjHero(0.0f, 128.0f);
	else if (Rouka1CL == 1)//１階廊下中央左側から移った場合
		CObjHero* h = new CObjHero(736.0f, 128.0f);
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
	//職員室の扉オブジェクトの作成
	CObjShokuinDoor* d1 = new CObjShokuinDoor(0.0f, 0.0f);
	Objs::InsertObj(d1, SHOKUIN_DOOR, 1);
	CObjShokuinDoor* d2 = new CObjShokuinDoor(732.0f, 0.0f);
	Objs::InsertObj(d2, SHOKUIN_DOOR, 1);
	//職員室にある貼り紙オブジェクトの作成
	CObjShokuinPaper* t1 = new CObjShokuinPaper(78.0f, 34.0f);
	Objs::InsertObj(t1, OBJ_TEXTURE, 1);
	//所持状況に応じて生成するもの
	if (KouchouKey == 1 && Kou_flag == false)
	{
		//校長室のカギオブジェクトの所持
		CObjKouchouKey* k = new CObjKouchouKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k, KOUCHOU_KEY, 1);
	}
	if (HokenKey == 0)
	{
		//保健室のカギオブジェクトの設置
		CObjHokenKey* k2 = new CObjHokenKey(177.0f, 72.0f);
		Objs::InsertObj(k2, HOKEN_KEY, 1);
	}
	else if (HokenKey == 1 && Hok_flag == false)
	{
		//保健室のカギオブジェクトの所持
		CObjHokenKey* k2 = new CObjHokenKey(HeroX + 8, HeroY + 8);
		Objs::InsertObj(k2, HOKEN_KEY, 1);
	}
	if (Hammer == 1 && Ham_flag == false)
	{
		//ハンマーオブジェクトの所持
		CObjHammer* i = new CObjHammer(HeroX + 8, HeroY + 8);
		Objs::InsertObj(i, OBJ_HAMMER, 1);
	}

}

void CSceneShokuin::Scene()
{

}