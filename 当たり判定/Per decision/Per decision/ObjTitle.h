#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

private:
	bool m_key_flag;//キーフラグ
	bool m_start; //スタートフラグ
	int m_start_co; //スタートカウント

};
