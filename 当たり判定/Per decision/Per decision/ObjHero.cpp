
//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_px = 400.0f;  //位置 Principaloffice 600.0f Infirmary 85.0f
	m_py = 300.0f; // Saff60.0f Corr1_1,2,3 240.0f Principaloffice 520.0f Infirmary 520.0f
	m_vx = 0.0f;  //移動ベクトル
	m_vy = 0.0f;
	m_posture = 0;   //右向き0.0f　左向き1.0f 正面2.0f 後ろ3.0f


	m_ani_time = 0;
	m_ani_frame = 1;  //静止フレームを初期にする

	//衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	
	//当たり判定                                プレイヤー
	Hits::SetHitBox(this, m_px+15 , m_py+20 , 32, 32,ELEMENT_PLAYER, OBJ_HERO, 1);
	//					横開始 縦開始 横大きさ 縦大きさ 属性 名前
}

//アクション
void CObjHero::Action()
{
	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//キーの入力方向
	//上
	if (Input::GetVKey('W') == true)
	{
		m_vy = -4.0f;
		m_posture = 3;
		m_ani_time += 1;

	}

	//左
	else if (Input::GetVKey('A') == true)
	{
		m_vx -= 4.0f;
		m_posture = 1;
		m_ani_time += 1;
	}

	//下
	else if (Input::GetVKey('S') == true)
	{

		m_vy = +4.0f;
		m_posture = 2;
		m_ani_time += 1;

	}
	//右
	else if (Input::GetVKey('D') == true)
	{
		m_vx += 4.0f;
		m_posture = 0;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 0; //キー入力が無い場合は静止フレームにする
		m_ani_time = 0;
	}


	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}



	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);
	if (hit->CheckElementHit(ELEMENT_STAFFROOM) == true)
	{
		//右
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			m_vx = m_vx - 4.0f;
		}
		//左
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			m_vx = m_vx + 4.0f;
		}
		//下
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			m_vy = m_vy - 4.0f;
		}
		//上
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			m_vy = m_vy + 4.0f;
		}
	}

	if (hit->CheckElementHit(ELEMENT_PRINCIPALOFFICE) == true)
	{
		//右
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			m_vx = m_vx - 4.0f;
		}
		//左
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			m_vx = m_vx + 4.0f;
		}
		//下
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			m_vy = m_vy - 4.0f;
		}
		//上
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			m_vy = m_vy + 4.0f;
		}
	}

	if (hit->CheckElementHit(ELEMENT_INFIRMARY) == true)
	{
		//右
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			m_vx = m_vx - 4.0f;
		}
		//左
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			m_vx = m_vx + 4.0f;
		}
		//下
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			m_vy = m_vy - 4.0f;
		}
		//上
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			m_vy = m_vy + 4.0f;
		}
	}

	if (hit->CheckElementHit(ELEMENT_CORRIDOR1_1) == true)
	{
		//右
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			/*m_vx = m_vx - 4.0f;*/
		}
		//左
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			/*m_vx = m_vx + 4.0f;*/
		}
		//下
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			/*m_vy = m_vy - 4.0f;*/
		}
		//上
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			/*m_vy = m_vy + 4.0f*/;
		}
	}

	if (hit->CheckElementHit(ELEMENT_CORRIDOR1_2) == true)
	{
		

		////右
		//if (m_posture == 0)
		//{
		//	m_ani_frame = 0;

		//	m_vx = -0.4;
		//}
		////左
		//if (m_posture == 1)
		//{
		//	m_ani_frame = 0;

		//	m_vx = +0.4;
		//}
		////下
		//if (m_posture == 2)
		//{
		//	m_ani_frame = 0;

		//	m_vy = -0.4;
		//}
		////上
		//if (m_posture == 3)
		//{
		//	m_ani_frame = 0;

		//	m_vy = +0.4;
		//}
		////右下
		//if (Input::GetVKey('D') == true && Input::GetVKey('S') == true)
		//{
		//	m_posture == 2;

		//	m_vx = m_vx + 0.1f;

		//	m_vy = m_vy - 0.1f;
		//}
		////右上
		//if (Input::GetVKey('D') == true && Input::GetVKey('W') == true)
		//{
		//	m_posture == 3;

		//	m_vx = m_vx - 0.1f;

		//	m_vy = m_vy + 0.1f;
		//}
		////左下
		//if (Input::GetVKey('A') == true && Input::GetVKey('S') == true)
		//{
		//	m_posture == 2;

		//	m_vx = m_vx + 0.1f;

		//	m_vy = m_vy + 0.1f;
		//}
		////左上
		//if (Input::GetVKey('A') == true && Input::GetVKey('W') == true)
		//{
		//	m_posture == 3;

		//	m_vx = m_vx + 0.1f;

		//	m_vy = m_vy - 0.1f;
		//}

	}

	if (hit->CheckElementHit(ELEMENT_CORRIDOR1_3) == true)
	{
		//右
		if (m_posture == 0)
		{
			m_ani_frame = 0;

			m_vx = m_vx - 4.0f;
		}
		//左
		if (m_posture == 1)
		{
			m_ani_frame = 0;

			m_vx = m_vx + 4.0f;
		}
		//下
		if (m_posture == 2)
		{
			m_ani_frame = 0;

			m_vy = m_vy - 4.0f;
		}
		//上
		if (m_posture == 3)
		{
			m_ani_frame = 0;

			m_vy = m_vy + 4.0f;
		}
	}


	//if (m_px+64.0f > 800.0f)
	//{
	//	m_px = 800.0f -64.0f;
	//}
	//else if (m_py + 64.0f > 600.0f)
	//{
	//	m_py = 600.0f - 64.0f;
	//}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
	else if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}


	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	
	//作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_px + 15, m_py + 20);//入り口から新しい位置（主人公の位置）情報に置き換える

	//敵機オブジェクトと接触したら主人公機削除
	if (hit->CheckObjNameHit(OBJ_ENEMY) !=nullptr)
	{
    	this->SetStatus(false);    //自身に削除命令を出す
		Hits::DeleteHitBox(this);  //主人公機が所有するHitBoxに削除する
    	Scene::SetScene(new CSceneGameOver());
	}
}



//ドロー

void CObjHero::Draw()
{
	int AniData[5] =
	{
		0,1,2,3,0,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置


	//d（右）が入力されたとき
	if (m_posture == 0)
	{
		//切り取り位置の設定
		src.m_top = 128.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 192.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = (64.0f  *   m_posture) + m_px;
		dst.m_right = (64 - 64.0f  *   m_posture) + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//a（左）が入力されたとき
	else if (m_posture == 1)
	{
		//切り取り位置の設定
		src.m_top = 64.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 128.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 64.0f + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//s（下）が入力されたとき
	else if (m_posture == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 64.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 64.0f + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//w（上）が入力されたとき
	else if (m_posture == 3)
	{
		//切り取り位置の設定
		src.m_top = 192.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 256.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 64.0f + m_px;
		dst.m_bottom = 64.0f + m_py;
	}



	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}
