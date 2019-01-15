#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneMain7 :public CScene
{
public:
	CSceneMain7();
	~CSceneMain7();
	void InitScene(); //初期化メソッド
	void Scene();     //実行中メソッド
private:
};