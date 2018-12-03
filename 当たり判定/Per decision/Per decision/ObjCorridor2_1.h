#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//使用するネームスペース
using namespace GameL;

class CObjCorridor2_1 :public CObj, private CObjPerdecision
{
public:
	CObjCorridor2_1() {};
	~CObjCorridor2_1() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

};