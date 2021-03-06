#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵
class CObjEnemy2 : public CObj
{
	public:
		CObjEnemy2(float x, float y);
		~CObjEnemy2() {};
		void Init();
		void Action();
		void Draw();
		float GetX();
		float GetY();

	private:
		float x;
		float y;
		float m_x;
		float m_y;
		float m_px;			//位置
		float m_py;
		float m_vx;			//移動ベクトル
		float m_vy;
		float m_posture;		//姿勢

		int m_ani_time;		//アニメーションフレーム動作間隔
		int m_ani_frame;		//描画フレーム

		float m_speed_power;	//スピードパワー
		float m_ani_max_time;	//アニメーション動作間隔最大値

		//衝突状態確認用初期化
		bool m_hit_up = false;
		bool m_hit_down = false;
		bool m_hit_left = false;
		bool m_hit_right = false;
};

