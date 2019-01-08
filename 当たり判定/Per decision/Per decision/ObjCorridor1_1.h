#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//使用するネームスペース
using namespace GameL;

class CObjCorridor1_1 :public CObj , private CObjPerdecision
{
public:
	CObjCorridor1_1() {};
	~CObjCorridor1_1() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
private:
	int m_x; //当たり判定位置 x
	int m_y; //当たり判定位置 y
	//エリア移動フラグ
	//bool m_flag_Corridor1_1;
};