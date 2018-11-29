#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//使用するネームスペース
using namespace GameL;

class CObjCorridor1_2 :public CObj, private CObjPerdecision
{
public:
	CObjCorridor1_2() {};
	~CObjCorridor1_2() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

};