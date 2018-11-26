#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero : public CObj
{
	public :
		CObjHero() {};
		~CObjHero() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
		float GetX();
		float GetY();

	private :
		float m_x;
		float m_y;
		float m_px;	//位置
		float m_py;
		float m_vx;	//移動ベクトル
		float m_vy;
		float m_posture;	//姿勢

		int m_ani_time;		//アニメーションフレーム動作問題
		int m_ani_frame;	//描画フレーム

		float m_speed_power; //スピードパワー
		float m_ani_max_time;//アニメーション動作間隔最大値
};