#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneHomeeconomicsroom :public CScene
{
public:
	CSceneHomeeconomicsroom();
	~CSceneHomeeconomicsroom();
	void InitScene(); //初期化メソッド
	void Scene();     //実行中メソッド
private:
};