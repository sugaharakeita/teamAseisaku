//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMap.h"

//使用するネームスペース
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

extern float g_objenemy_x = 150.0f;
extern float g_objenemy_y = 0.0f;



//イニシャライズ
void CObjMap::Init()
{
	m_x1 = 0.0f;
	

}

//アクション
void CObjMap::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	////敵の位置
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();

	
	//マップ端にいくと廊下1-2にいく
	if (hx >700 == true)
	{
		if (m_key_flag == true)
		{
			//主人公
			g_hero_x = 110;
			g_hero_y = hy;
			//敵
			g_objenemy_x = 110;
			
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
void CObjMap::Draw()
{
	//描画カラー情報 R G B al(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1035.0f;
	src.m_bottom = 362.0f;

	//背景１の位置の設定をし描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 1716.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);




}