#pragma once
//使用するヘッダ-
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：RoomHitBox
class CObjRoomHitBox :public CObj
{
public:
	 CObjRoomHitBox() {};
	 ~CObjRoomHitBox() {};

	 void Init();  //イニシャライズ
	 void Action();//アクション
	 void Draw();  //ドロー

private:
};