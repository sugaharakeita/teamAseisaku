#pragma once
//使用するヘッターファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneCorridor1 :public CScene
{
public:
	CSceneCorridor1();
	~CSceneCorridor1();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:
	int m_time; //出現カウント
	//エリア移動フラグ
	bool m_flag_Corridor1_1;
	bool m_flag_Corridor1_2;
	bool m_flag_Corridor1_3;
	//エリア番号
	int m_Corridor1_co;
	//連続移動防止フラグ
	bool m_flag_go;
};
