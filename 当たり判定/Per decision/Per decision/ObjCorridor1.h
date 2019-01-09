#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//使用するネームスペース
using namespace GameL;

class CObjCorridor1 :public CObj, private CObjPerdecision
{
public:
	CObjCorridor1() {};
	~CObjCorridor1() {};
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
	bool m_flag_Corridor3_1;
	bool m_flag_Corridor3_2;
	bool m_flag_Corridor3_3;
	//階層分け
	int m_Storey;
};