#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:ブロック&背景
class CObjKoutyousitu : public CObj
{
	public :
		CObjKoutyousitu() {};
		~CObjKoutyousitu() {};
		void Init();			//イニシャライズ
		void Action();			//アクション
		void Draw();			//ドロー
	private:
		int m_map[10][10];	//マップ情報（仮）
};