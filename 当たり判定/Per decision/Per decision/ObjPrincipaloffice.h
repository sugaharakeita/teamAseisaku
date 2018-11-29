#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjPerdecision.h"

//使用するネームスペース
using namespace GameL;

class CObjPrincipaloffice :public CObj, private CObjPerdecision
{
public:
	CObjPrincipaloffice() {};
	~CObjPrincipaloffice() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

};
