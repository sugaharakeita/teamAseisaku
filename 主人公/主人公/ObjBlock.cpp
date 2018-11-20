//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock(int map[10][100])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(10 * 100));
}
//イニシャライズ
void CObjBlock::Init()
{
	m_scroll = 0.0f;

};

	


//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//後方スクロールライン
	if (hx < 0)
	{
		hero->SetX(0);            //主人公はラインを超えないようにする
		m_scroll -= hero->GetVX(); //主人公が本来動くべき分の値をm_scrollに加える
	}

	//前方スクロールライン
	if (hx > 750)
	{
		hero->SetX(750);		   //主人公はラインを超えないようにする
		m_scroll -= hero->GetVX(); //主人公が本来動くべき分の値をm_scrollに加える
	}


	//m_mapの全要素にアクセス
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = i*64.0f;
				float y = i*64.0f;

				//主人公とブロックの当たり判定
				if ((hx+(-m_scroll)+64.0f>x)&&(hx+(-m_scroll)<x+64.0f)&&(hy+64.0f>y)&&(hy<y+64.0f))
				{
					//上下左右判定
					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
					float vy = hy - y;

					//長さを求める
					float len = sqrt(vx*vx + vy*vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							hero->SetRight(true);   //主人公の左の部分が衝突している
							hero->SetX(x + 64.0f);  //ブロックの位置+主人公の幅
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数

						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);   //主人公の下の部分が衝突している
							hero->SetY(y - 64.0f); //ブロックの位置-主人公の幅
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);     //主人公の右の部分が衝突している
							hero->SetX(x - 64.0f);   //ブロックの位置−主人公の幅
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);
							hero->SetY(y + 64.0f);
							hero->SetVY(0.0f);
						}
					}

					
				}

			}
		}

	}
}

//ドロー
void CObjBlock::Draw()
{
	
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //描画元切り取り位置
	RECT_F dst;  //描画先表示位置


	//マップチップによるblock設置
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;

	

	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 100;j++)
		{
			if (m_map[i][j] == 5)//保健室　床表示
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 6)//保健室　先生机表示
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 7)//保健室　椅子表示
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 8)//保健室　カーテン表示
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 9)//保健室　ベッド表示
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(9, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 10)//保健室　机表示
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(10, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 11)//保健室　ソファ表示
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(11, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 12)//保健室　体重計表示
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(12, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 13)//保健室　身長計表示
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
		}
	}
	
}
