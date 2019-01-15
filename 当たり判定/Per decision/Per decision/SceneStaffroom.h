#pragma once
//使用するヘッターファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneStaffroom :public CScene
{
public:
	CSceneStaffroom();
	~CSceneStaffroom();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:
	int m_time; //出現カウント

};

