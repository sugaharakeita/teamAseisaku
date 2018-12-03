#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "SwitchALL.h"

using namespace GameL;

#include "SceneKouchou.h"
#include "Hero.h"
#include "GameHead.h"

CSceneKouchou::CSceneKouchou()
{

}

CSceneKouchou::~CSceneKouchou()
{

}

void CSceneKouchou::InitScene()
{
	CObjKouchou* p = new CObjKouchou();
	Objs::InsertObj(p, SPOT_KOUCHOU, 0);
	CObjHero* h = new CObjHero(72, 520);
	Objs::InsertObj(h, OBJ_HERO, 2);
	CObjExcla* x = new CObjExcla(HeroX + 8, HeroY + 8);
	Objs::InsertObj(x, OBJ_EXCLAMATION, 2);
	CObjMessage* m = new CObjMessage(12.0f, 476.0f);
	Objs::InsertObj(m, OBJ_MESSAGE, 3);
	CObjHammer* i = new CObjHammer(188,164);
	Objs::InsertObj(i, OBJ_HAMMER, 1);

}

void CSceneKouchou::Scene()
{

}