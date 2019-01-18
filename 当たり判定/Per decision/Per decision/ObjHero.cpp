//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"


#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

float g_hero_x = 150.0f;
float g_hero_y = 150.0f;

//イニシャライズ
void CObjHero::Init()
{
	m_px = g_hero_x; //位置 
	m_py = g_hero_y;
	
	m_vx = 0.0f;  //移動ベクトル
	m_vy = 0.0f;
	m_posture = 3;   //右向き0.0f　左向き1.0f 正面2.0f 後ろ3.0f
	m_go_cox = 2; //廊下移動数x初期化 
				  //1=1.2.3-1, 2=1.2.3-2, 3=1.2.3-3
	m_go_coy = 2; //部屋移動数y初期化 
				  //1=上側の教室 2=廊下 3=下側の教室

	m_ani_time = 0;
	m_ani_frame = 1;  //静止フレームを初期にする
	m_footsteps_co = 0; //足音秒数カウント初期化
	m_footsteps_switching = false; //足音オフ化

	//衝突状態確認用初期化
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	
	//当たり判定                                
	Hits::SetHitBox(this, m_px+16 , m_py+50 , 32, 10, ELEMENT_PLAYER, OBJ_HERO, 1);
	//					横開始 縦開始 横大きさ 縦大きさ 属性 名前
}

//アクション
void CObjHero::Action()
{

	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//主人公と追尾で角度を取る
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	int x = obj->GetX() - m_px;
	int y = obj->GetY() - m_py;

	//キーの入力方向
	//上キーかつ当たり判定と当たっていない場合
	if (Input::GetVKey('W') == true && m_hit_up == false)
	{
		m_vy = -4.0f;
		m_posture = 3;
		m_ani_time += 1;
		m_footsteps_switching = true; //足音オン
	}

	//左キーかつ当たり判定と当たっていない場合
	else if (Input::GetVKey('A') == true && m_hit_right == false)
	{
		m_vx -= 4.0f;
		m_posture = 1;
		m_ani_time += 1;
		m_footsteps_switching = true; //足音オン
	}

	//下キーかつ当たり判定と当たっていない場合
	else if (Input::GetVKey('S') == true && m_hit_down == false)
	{
		m_vy = +4.0f;
		m_posture = 2;
		m_ani_time += 1;
		m_footsteps_switching = true; //足音オン
	}

	//右キーかつ当たり判定と当たっていない場合
	else if (Input::GetVKey('D') == true && m_hit_left == false)
	{
		m_vx += 4.0f;
		m_posture = 0;
		m_ani_time += 1;
		m_footsteps_switching = true; //足音オン
	}
	//上キーかつ当たり判定と当たっている場合
	else if (Input::GetVKey('W') == true && m_hit_up == true)
	{
		m_vy = 0.0f;
		m_posture = 3;
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	//左キーかつ当たり判定と当たっている場合
	else if (Input::GetVKey('A') == true && m_hit_right == true)
	{
		m_vx = 0.0f;
		m_posture = 1;
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	//下キーかつ当たり判定と当たっている場合
	else if (Input::GetVKey('S') == true && m_hit_down == true)
	{
		m_vy = 0.0f;
		m_posture = 2;
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	//右キーかつ当たり判定と当たっている場合
	else if (Input::GetVKey('D') == true && m_hit_left == true)
	{
		m_vx = 0.0f;
		m_posture = 0;
		m_ani_frame = 0;
		m_ani_time = 0;
	}


	//キー入力が無い場合
	else
	{
		m_ani_frame = 0; //キー入力が無い場合は静止フレームにする
		m_ani_time = 0;
		m_footsteps_co = 0;
		m_footsteps_switching = false; //足音オフ化
		m_hit_up = false;
		m_hit_down = false;
		m_hit_left = false;
		m_hit_right = false;
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

	//足音がオンの時
	if (m_footsteps_switching == true)
	{
		if (m_footsteps_co == 0)
		{
			float v = Audio::VolumeMaster(2);
			v = Audio::VolumeMaster((1.0 - v));

			Audio::Start(2);
			m_footsteps_co += 1;
		}

		if (m_footsteps_co == 9)
		{
			Audio::Stop(2);
			m_footsteps_co = 0;
		}
	}
	else
	{
		Audio::Stop(2);
	}


	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//主人公がステージの当たり判定に当たった時の処理（全ステージ対応）
	if (hit->CheckElementHit(ELEMENT_FIELD) == true)
	{

		//右キーを押した場合
		if (Input::GetVKey('D') == true)
		{
			m_vx -= 4.0f;
			m_hit_left = true;
			m_hit_up = false;
			m_hit_right = false;
			m_hit_down = false;
		}

		//左キーを押した場合
		if (Input::GetVKey('A') == true)
		{
			m_vx += 4.0f;
			m_hit_right = true;
			m_hit_up = false;
			m_hit_down = false;
			m_hit_left = false;
		}

		//下キーを押した場合
		if (Input::GetVKey('S') == true)
		{
			m_vy -= 4.0f;
			m_hit_down = true;
			m_hit_up = false;
			m_hit_right = false;
			m_hit_left = false;
		}

		//上キーを押した場合
		if (Input::GetVKey('W') == true)
		{
			m_vy += 4.0f;
			m_hit_up = true;
			m_hit_right = false;
			m_hit_down = false;
			m_hit_left = false;
		}

		//上・左キーを押した場合
		if (Input::GetVKey('W') == true &&
			Input::GetVKey('A') == true)
		{
			m_vx = 0.0f;
			m_vy = 0.0f;
			m_hit_up = true;
			m_hit_right = true;
			m_hit_down = false;
			m_hit_left = false;
		}

		//上・右キーを押した場合
		if (Input::GetVKey('W') == true &&
			Input::GetVKey('D') == true)
		{
			m_vx = 0.0f;
			m_vy = 0.0f;
			m_hit_up = true;
			m_hit_left = true;
			m_hit_right = false;
			m_hit_down = false;
		}

		//下・左キーを押した場合
		if (Input::GetVKey('S') == true &&
			Input::GetVKey('A') == true)
		{
			m_vx = 0.0f;
			m_vy = 0.0f;
			m_hit_down = true;
			m_hit_right = true;
			m_hit_up = false;
			m_hit_left = false;
		}

		//下・右キーを押した場合
		if (Input::GetVKey('S') == true &&
			Input::GetVKey('D') == true)
		{
			m_vx = 0.0f;
			m_vy = 0.0f;
			m_hit_down = true;
			m_hit_left = true;
			m_hit_up = false;
			m_hit_right = false;
		}


		
		//主人公と障害物がどの角度で当たっているか調べる
		HIT_DATA** hit_data;
		hit_data = hit->SearchElementHit(ELEMENT_FIELD);


		float r = hit_data[0]->r;

		//角度で上下左右を判定
		if (r > 0 && r < 45 || r >= 315)
		{
		//右
		m_hit_right = true;
		}
		else if (r >= 45 && r < 136)
		{
		//上
		m_hit_up = true;
		}
		else if (r >= 135 && r <= 225)
		{
		//左
		m_hit_left = true;
		}
		else if (r > 225 && r < 316)
		{
		//下
		m_hit_down = true;
		}



		if (m_hit_left == true)//左に当たり判定があった場合
		{
		m_vx = m_vx + 5.0f;
		}
		else if (m_hit_right == true)//右に当たり判定があった場合
		{
		m_vx = m_vx - 5.0f;
		}
		else if (m_hit_down == true)//下に当たり判定があった場合
		{
		m_vy = m_vy - 5.0f;
		}
		else if (m_hit_up == true)//上に当たり判定があった場合
		{
		m_vy = m_vy + 5.0f;
		}

		

	}

	//画面移動
	//廊下移動
	//700～800にいくと廊下3-3にいく
	if (hx + 64.0f >800 == true && m_go_cox == 2 && m_go_coy == 2)
	{
		m_px = 110;
		m_py = hy;
		m_key_flag = false;
		m_go_cox = 3;
		m_go_coy = 2;
	}

	//0～100にいくと廊下3-1にいく
	if (hx < 0 == true && m_go_cox == 2 && m_go_coy == 2)
	{
		m_px = 690;
		m_py = hy;
		m_key_flag = false;
		m_go_cox = 1;
		m_go_coy = 2;
	}


	//0～100にいくと廊下3-2にいく
	if (hx < 0 == true && m_go_cox == 3 && m_go_coy == 2)
	{
		m_px = 690;
		m_py = hy;
		m_key_flag = false;
		m_go_cox = 2;
		m_go_coy = 2;
	}

	//マップ端にいくと廊下3-2にいく
	if (hx + 64.0f >800 == true && m_go_cox == 1 && m_go_coy == 2)
	{
		//主人公
		m_px = 110;
		m_py = hy;
		//敵
		//g_enemy_x = 110;
		m_key_flag = false;
		m_go_cox = 2;
		m_go_coy = 2;
	}

	//教室移動
	
	//保健室
	if (hy < 120  && m_go_cox == 3 && m_go_coy == 2)
	{
		m_px = 60;
		m_py = 250;
		m_go_cox = 3;
		m_go_coy = 1;
		return;
	}
	if (hy + 64.0f > 800 && m_go_cox == 3 && m_go_coy == 1)
	{
		m_px = 250;
		m_py = 250;
		m_go_cox = 3;
		m_go_coy = 2;
		return;
	}


	//下に行くと二階・家庭科室,家庭準備室に行く。
	if (hy > 450 && m_go_cox == 1 && m_go_coy == 2)
	{
		//家庭科室
		if (hx < 350 == true)
		{
			m_px = 650;
			m_py = 70;
			m_key_flag = false;
			m_go_cox = 1;
			m_go_coy = 3;
			return;
		}
		//家庭準備室
		if (hx > 450 == true)
		{
			m_px = 400;
			m_py = 70;
			m_key_flag = false;
			m_go_cox = 1;
			m_go_coy = 3;
			return;
		}
	}


	//廊下2-1に行く(左側のドア)
	if (hy < 50 && hx < 100 && m_go_cox == 1 && m_go_coy == 3)
	{
		m_px = 50;
		m_py = 300;
		m_go_cox = 1;
		m_go_coy = 2;
		return;
	}

	//廊下2-1に行く(右側のドア)
	if (hy < 50 && hx > 700 && m_go_cox == 1 && m_go_coy == 3)
	{
		m_px = 500;
		m_py = 300;
		m_go_cox = 1;
		m_go_coy = 2;
		return;
	}

	//右に行くと二階・家庭準備室
	if ((hy < 250 && hy > 192) && hx > 800 && m_go_cox == 1 
		&& m_go_coy == 3)
	{
		m_px = 10;
		m_py = 200;
		return;
	}

	//上に行くと廊下2-1に行く
	if (hy < 70 && m_go_cox == 1 && m_go_coy == 3)
	{
		m_px = 700;
		m_px = 300;
		m_go_cox = 1;
		m_go_coy = 2;
		return;
	}

	//左に行くと二階・家庭科室に行く
	if (hx < 10 && m_go_cox == 1 && m_go_coy == 3)
	{
		g_hero_x = 730;
		g_hero_y = 200;
		m_px = 730;
		m_py = 200;
		return;
	}


	//上に行くと二階・図書室に行く
	if (hy < 100 == true && m_go_cox == 1 && m_go_coy == 2)
	{
		m_px = 100;
		m_py = 60;
		m_key_flag = false;
		m_go_cox = 1;
		m_go_coy = 1;
	}
	
	//下に行くと廊下2-1に出る
	if (hy > 536 && hx > 0 && m_go_cox == 1 && m_go_coy == 1)
	{
		m_px = 220;
		m_py = 200;
		m_go_cox = 1;
		m_go_coy = 2;
		return;
	}

	//左のドアに行くと廊下2-3に出る
	if (hy < 100 && hx < 50 && m_go_cox == 3 && m_go_coy == 3)
	{
		m_px = 60;
		m_py = 250;
		m_go_cox = 3;
		m_go_coy = 2;
	}

	//右のドアに行くと廊下2-3に出る
	if (hy < 100 && hx > 650 && m_go_cox == 3 && m_go_coy == 3)
	{
		m_px = 650;
		m_py = 250;
		m_go_cox = 3;
		m_go_coy = 2;
	}


	//下に行くと3階・会議室に行く
	if (hy > 450 == true && m_go_cox == 3 && m_go_coy == 2)
	{
		m_px = 650;
		m_py = 70;
		m_key_flag = false;
		m_go_cox = 3;
		m_go_coy = 3;
	}
		

	//階段移動
	if (hy < 0.0f && m_go_cox == 2 
		&& Input::GetVKey(VK_RETURN) == true)
	{
		m_px = 450.0f;
		m_py = 200.0f;
		m_posture = 2;
	}


	//画面外に出ないようにする処理
	if (m_px + 64.0f > 800.0f)
	{
		m_px = 800.0f - 64.0f;
	}
	if (m_py + 64.0f > 600.0f)
	{
		m_py = 600.0f - 64.0f;
	}
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
	hit->SetPos(m_px + 16, m_py + 50);//入り口から新しい位置（主人公の位置）情報に置き換える

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
