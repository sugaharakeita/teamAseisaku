#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

#include "SceneTitle.h"
#include "GameHead.h"

CSceneTitle::CSceneTitle()
{

}

CSceneTitle::~CSceneTitle()
{

}

void CSceneTitle::InitScene()
{
	//�^�C�g���I�u�W�F�N�g���쐬
	CObjTitle* p = new CObjTitle();
	Objs::InsertObj(p, OBJ_TITLE, 0);
}

void CSceneTitle::Scene()
{

}
