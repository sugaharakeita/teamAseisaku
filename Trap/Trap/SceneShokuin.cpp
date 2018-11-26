//ƒV[ƒ“‚ª“®‚­‚©‚ÌŒŸØ—p‚Éì‚Á‚½‚¾‚¯
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

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
	CObjShokuin* p = new CObjShokuin();
	Objs::InsertObj(p, SPOT_SHOKUIN, 0);
	CObjHero* h = new CObjHero(72,520);
	Objs::InsertObj(h, OBJ_HERO, 2);
	
}

void CSceneShokuin::Scene()
{

}