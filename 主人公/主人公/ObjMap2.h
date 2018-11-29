#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：マップ
class CObjMap2 :public CObj
{
public:
	CObjMap2() {};
	~CObjMap2() {};

	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

private:

	float m_x1;//背景１の位置情報
	float m_x2;//背景２の位置情報

	bool m_key_flag;//キーフラグ

};
