#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

#include "SceneHelp.h"
#include "GameHead.h"

CSceneHelp::CSceneHelp()
{

}

CSceneHelp::~CSceneHelp()
{

}

void CSceneHelp::InitScene()
{
	//��������I�u�W�F�N�g�̍쐬
	CObjHelp* p = new CObjHelp();
	Objs::InsertObj(p, OBJ_HELP, 0);
}

void CSceneHelp::Scene()
{

}
