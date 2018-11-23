#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjHokensitu :public CObj
{

	public:
		CObjHokensitu() {};
		~CObjHokensitu() {};
		void Init();
		void Action();
		void Draw();
	
	private:
		int m_x;
		int m_y;

};
