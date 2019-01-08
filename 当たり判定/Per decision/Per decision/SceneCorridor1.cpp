//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneCorridor1.h"
#include "GameHead.h"

//コンストラクタ
CSceneCorridor1::CSceneCorridor1()
{

}

//デストラクタ
CSceneCorridor1::~CSceneCorridor1()
{

}

//初期化メゾット
void CSceneCorridor1::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(0, L"黒い足音.wav", BACK_MUSIC); //通常　廊下
	Audio::LoadAudio(1, L"死神の斧.wav", BACK_MUSIC); //Enemy出現

	Audio::LoadAudio(2, L"学校の廊下を歩く .wav", BACK_MUSIC); //主人公足音

	//ボリュームを0.6減らす
	float v = Audio::VolumeMaster(0.6);

	//音楽スタート
	Audio::Start(0);

	//秒数カウント初期化
	m_time = 0;

	//エリア移動フラグ初期化
	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;

	//エリア番号
	m_Corridor1_co = 2;

	//連続移動防止フラグ初期化
	m_flag_go = false;

	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objbb = new CObjCorridor1_2();
	Objs::InsertObj(objbb, OBJ_CORRIDOR1_2, 9);

	Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);

	/*
	//Corridor1_1オブジェクト生成
	CObjCorridor1_1* objb = new CObjCorridor1_1();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_1, 9);

	Draw::LoadImage(L"廊下1-1.png", 9, TEX_SIZE_512);

	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objb = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

	Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);

	//Corridor1_3オブジェクト生成
	CObjCorridor1_3* objb = new CObjCorridor1_3();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_3, 9);

	Draw::LoadImage(L"廊下1-3.png", 9, TEX_SIZE_512);
	*/

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);


	//グラフィック読み込み
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"二宮金次郎透過.png", 11, TEX_SIZE_512);
}


//実行中メゾット
void CSceneCorridor1::Scene()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//Corridor1_1オブジェクト生成
	CObjCorridor1_1* objb1_1 = new CObjCorridor1_1();
	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();
	//Corridor1_3オブジェクト生成
	CObjCorridor1_3* objb1_3 = new CObjCorridor1_3();

	/*
	CHitBox* hit1_1 = Hits::GetHitBox(this);
	CHitBox* hit1_2 = Hits::GetHitBox(this);
	CHitBox* hit1_3 = Hits::GetHitBox(this);
	*/

	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;

	m_flag_go = false;

	//廊下1-1画面端右に行くと廊下1-2へ移動
	if (hx + 64.0f > 800.0f && m_Corridor1_co == 1
		&& m_flag_go == false)
	{
		m_flag_Corridor1_2 = true;
		m_flag_go = true;
		m_Corridor1_co = 2;
	}

	//廊下1-3画面端左に行くと廊下1-2へ移動
	if (hx < 0.0f && m_Corridor1_co == 3 && m_flag_go == false)
	{
		m_flag_Corridor1_2 = true;
		m_flag_go = true;
		m_Corridor1_co = 2;
	}
	
	//廊下1-2画面端左に行くと廊下1-1へ移動
	if (hx < 0.0f && m_Corridor1_co == 2 && m_flag_go == false)
	{
		m_flag_Corridor1_1 = true;
		m_flag_go = true;
		m_Corridor1_co = 1;
	}

	//廊下1-2画面端右に行くと廊下1-3へ移動
	if (hx + 64.0f > 800.0f && m_Corridor1_co == 2
		&& m_flag_go == false)
	{
		m_flag_Corridor1_3 = true;
		m_flag_go = true;
		m_Corridor1_co = 3;
	}
		

	if (m_flag_Corridor1_1 == true && m_Corridor1_co == 1)
	{
		Objs::InsertObj(objb1_1, OBJ_CORRIDOR1_1, 9);

		Draw::LoadImage(L"廊下1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_2 == true && m_Corridor1_co == 2)
	{
		Objs::InsertObj(objb1_2, OBJ_CORRIDOR1_2, 9);

		Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_3 == true && m_Corridor1_co == 3)
	{
		Objs::InsertObj(objb1_3, OBJ_CORRIDOR1_3, 9);

		Draw::LoadImage(L"廊下1-3.png", 9, TEX_SIZE_512);
	}
	

	if (m_flag_Corridor1_1 == false)
	{
		//Objs::Delete(objb1_1, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_2 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_2, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_3 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_3, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-3.png", 9, TEX_SIZE_512);
	}

	/*
	m_time++;

	//敵オブジェクト作成・敵出現時BGM変更
	if (m_time == 90)
	{
	CObjEnemy* objh = new CObjEnemy(0, 0);
	Objs::InsertObj(objh, OBJ_ENEMY, 11);

	Audio::Stop(0);
	Audio::Start(1);
	}
	*/
	
}
