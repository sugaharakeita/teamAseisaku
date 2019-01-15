#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneClassroom :public CScene
{
public:
	CSceneClassroom();
	~CSceneClassroom();
	void InitScene(); //初期化メソッド
	void Scene();     //実行中メソッド
private:
};