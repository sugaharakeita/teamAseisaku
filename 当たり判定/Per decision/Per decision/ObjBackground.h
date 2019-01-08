#pragma once
//使用するヘッターファイル
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

using namespace GameL;

class CObjBackground :public CObj, private CObjPerdecision
{
public:
	CObjBackground() {};
	~CObjBackground() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー
private:

	float m_x1; //背景1の位置情報
	float m_x2; //背景2の位置情報
};