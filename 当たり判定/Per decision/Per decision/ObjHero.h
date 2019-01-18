#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト:主人公
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }

private:
	float m_px;  //位置
	float m_py;
	float m_vx;  //移動ベクトル
	float m_vy;
	float m_posture; //姿勢
	int m_go_cox; //廊下移動数x
	int m_go_coy; //部屋移動数y

	bool m_key_flag;//キーフラグ

	int m_ani_time; //アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム
	int m_footsteps_co; //足音秒数カウント
	bool m_footsteps_switching; //足音オン・オフ

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//当たっているblockの種類の確認用
	int m_Obstacle_type;

	//交点
	float px, py; 

};

