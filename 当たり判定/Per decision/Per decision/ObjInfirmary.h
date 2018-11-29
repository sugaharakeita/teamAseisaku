#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//使用するネームスペース
using namespace GameL;

class CObjInfirmary :public CObj, private CObjPerdecision
{
public:
	CObjInfirmary() {};
	~CObjInfirmary() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

};
