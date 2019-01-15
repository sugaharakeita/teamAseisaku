#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//使用するネームスペース
using namespace GameL;

class CObjCorridor1_3 :public CObj, private CObjPerdecision
{
public:
	CObjCorridor1_3() {};
	~CObjCorridor1_3() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
private:
};
