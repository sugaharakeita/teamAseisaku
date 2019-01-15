#pragma once
//使用するヘッターファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneCorridor1_2 :public CScene
{
public:
	CSceneCorridor1_2();
	~CSceneCorridor1_2();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:
	int m_time; //出現カウント

};

