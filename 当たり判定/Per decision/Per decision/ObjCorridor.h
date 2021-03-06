#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//使用するネームスペース
using namespace GameL;

class CObjCorridor :public CObj, private CObjPerdecision
{
public:
	CObjCorridor() {};
	~CObjCorridor() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
private:
	//エリア移動フラグ
	bool m_flag_Corridor1_1;
	bool m_flag_Corridor1_2;
	bool m_flag_Corridor1_3;
	bool m_flag_Corridor2_1;
	bool m_flag_Corridor2_2;
	bool m_flag_Corridor2_3;
	bool m_flag_Corridor3_1;
	bool m_flag_Corridor3_2;
	bool m_flag_Corridor3_3;
	bool m_flag_Rooftop;


	//階層分け
	int m_Storey;

	float m_x1;//背景１の位置情報
	float m_x2;//背景２の位置情報


	float m_scroll;//左右スクロール用
};