#pragma once
//使用するヘッターファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneCorridor :public CScene
{
public:
	CSceneCorridor();
	~CSceneCorridor();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:
	int m_time; //出現カウント
	//エリア移動フラグ
	bool m_flag_Corridor1_1;
	bool m_flag_Corridor1_2;
	bool m_flag_Corridor1_3;
	bool m_flag_Staffroom;
	bool m_flag_Principaloffice;
	bool m_flag_Infirmary;
	bool m_flag_Corridor2_1;
	bool m_flag_Corridor2_2;
	bool m_flag_Corridor2_3;
	bool m_flag_Corridor3_1;
	bool m_flag_Corridor3_2;
	bool m_flag_Corridor3_3;
	//エリア番号
	int m_Corridor_co;
	//連続移動防止フラグ
	bool m_flag_go;
	//階層分け 1=1階 2=2階 3=3階
	int m_Storey;
	
};
