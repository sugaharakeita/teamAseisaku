#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト:主人公
class CObjHero :public CObj
{
public :
	CObjHero() {};
	~CObjHero() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }


	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	



private:

	float m_px;  //位置
	float m_py;
	float m_vx;  //移動ベクトル
	float m_vy;
	float m_posture; //姿勢
	


	int m_ani_time; //アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	
};


