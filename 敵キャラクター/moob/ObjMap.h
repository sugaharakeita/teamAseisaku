#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：背景
class CObjMap :public CObj
{
	public :
		CObjMap() {};
		~CObjMap() {};
		void Init();
		void Action();
		void Draw();
	private :
};