//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMap.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMap::Init()
{
	m_x1 = 0.0f;
	m_flag = 0;

}

//アクション
void CObjMap::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//敵の位置を取得
	//CObjEnemy* enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();

	//主人公が右端700～800に来るとマップ移動
	if (700 < hx && m_flag == 0)
	{
		m_flag = 1;
	}
	//else if (hx < 100 && m_flag == 0)
	//{
	//	m_flag = 3;
	//}


		//マップ移動
		if (m_flag == 1)
		{
			m_x1 -= 5.0f;
			hero->SetX(hx - 5.0);
			//enemy->SetX(ex - 5.0);
			if (m_x1 < -700)
			{
				m_flag = 2;
			}
		}
		/*else if(m_flag == 3)
		{
			m_x1 += 5.0f;
			hero->SetX(hx + 5.0);
			if (m_x1 < 700)
			{
				m_flag = 2;
			}
		}*/
		else
		{
			;
		}

	



	

	

	
}

//ドロー
void CObjMap::Draw()
{
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1779.0f;
	src.m_bottom = 362.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 2948.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);




}