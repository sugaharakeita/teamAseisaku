#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneComputerroom :public CScene
{
public:
	CSceneComputerroom();
	~CSceneComputerroom();
	void InitScene(); //初期化メソッド
	void Scene();     //実行中メソッド
private:
};