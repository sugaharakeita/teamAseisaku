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
	bool m_flag_Staffroom;
	bool m_flag_Principaloffice;
	bool m_flag_Infirmary;
	bool m_flag_Corridor2_1;
	bool m_flag_Corridor2_2;
	bool m_flag_Corridor2_3;
	bool m_flag_Classroom;
	bool m_flag_Library;
	bool m_flag_Homeeconomicsroom;
	bool m_flag_Homepreparationroom;
	bool m_flag_Corridor3_1;
	bool m_flag_Corridor3_2;
	bool m_flag_Corridor3_3;
	bool m_flag_Computerroom;
	bool m_flag_Musicroom;
	bool m_flag_Conferenceroom;
	bool m_flag_Rooftop;


	//階層分け
	bool m_Storey1;
	bool m_Storey2;
	bool m_Storey3;
	bool m_Storey4;

	float m_x1;//背景１の位置情報
	float m_x2;//背景２の位置情報


	float m_scroll;//左右スクロール用
};