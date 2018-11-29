//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMap3.h"

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;


//イニシャライズ
void CObjMap3::Init()
{
	m_x1 = 0.0f;


}

//アクション
void CObjMap3::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//0～100にいくと廊下1-2にいく
	if (hx < 100 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 690;
			g_hero_y = hy;
			Scene::SetScene(new CSceneMain2());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}



}

//ドロー
void CObjMap3::Draw()
{
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

				
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 360.0f;
	src.m_bottom = 362.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);




}