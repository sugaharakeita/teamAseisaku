#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

#include "SceneHoken.h"
#include "GameHead.h"

CSceneHoken::CSceneHoken()
{

}

CSceneHoken::~CSceneHoken()
{

}

void CSceneHoken::InitScene()
{
	CObjHoken* p = new CObjHoken();
	Objs::InsertObj(p, SPOT_HOKEN, 0);
}

void CSceneHoken::Scene()
{

}