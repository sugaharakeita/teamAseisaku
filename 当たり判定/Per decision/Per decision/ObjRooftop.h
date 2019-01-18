#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：マップ
class CObjRooftop :public CObj
{
public:
	CObjRooftop() {};
	~CObjRooftop() {};

	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

private:

	float m_x1;//背景１の位置情報
	float m_x2;//背景２の位置情報

	bool m_key_flag;//キーフラグ

	float m_scroll;  //左右スクロール用

};