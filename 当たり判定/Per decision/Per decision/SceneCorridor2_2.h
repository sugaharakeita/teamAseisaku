#pragma once
//使用するヘッターファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneCorridor2_2 :public CScene
{
public:
	CSceneCorridor2_2();
	~CSceneCorridor2_2();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:

};

