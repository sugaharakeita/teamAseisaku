#pragma once
//使用するヘッターファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneCorridor1_1 :public CScene
{
public:
	CSceneCorridor1_1();
	~CSceneCorridor1_1();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:

};
