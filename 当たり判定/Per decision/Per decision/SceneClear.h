#pragma once
//使用するヘッターファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneClear :public CScene
{
public:
	CSceneClear();
	~CSceneClear();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:

};
