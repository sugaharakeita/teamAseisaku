#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：当たり判定
class CObjHitBox : public CObj
{
	public:
		CObjHitBox(HitBoxs h);
		~CObjHitBox() {};
		void Init() {};
		void Action() {};	//アクション
		void Draw() {};	//ドロー

//		HitBoxs Get_HitstateSR(int Hitid);	//職員室当たり判定
//		HitBoxs StaffroomHitBox[8];			//職員室当たり判定
	private:
};