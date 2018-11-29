#pragma once
//使用するヘッターファイル
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

using namespace GameL;

class CObjStaffroom :public CObj, private CObjPerdecision
{
public:
	CObjStaffroom() {};
	~CObjStaffroom() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー

};