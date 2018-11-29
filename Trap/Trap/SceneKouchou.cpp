#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

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

}

void CSceneKouchou::Scene()
{

}