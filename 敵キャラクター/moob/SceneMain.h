#pragma once
//使用するヘッダー
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneMain :public CScene
{
	public :
		CSceneMain();
		~CSceneMain();
		void InitScene();
		void Scene();
	private:
};