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
	Audio::LoadAudio(0, L"黒い足音.wav", BACK_MUSIC); //通常　廊下1
	Audio::LoadAudio(1, L"死神の斧.wav", BACK_MUSIC); //Enemy出現
	Audio::LoadAudio(3, L"謀略の間.wav", BACK_MUSIC); //通常　廊下2


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
	m_flag_Staffroom = false;
	m_flag_Principaloffice = false;
	m_flag_Infirmary = false;
	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;

	//エリア番号 1=1-1,2-1,3-1  2=1-2,2-2,3-2  3=1-3,2-3,3-3
	//4=職員室 5=校長室 6=保健室
	m_Corridor_co = 2;

	//階層分け初期化
	m_Storey = 1;

	//連続移動防止フラグ初期化
	m_flag_go = false;

	//Test Corridor1オブジェクト生成
	CObjCorridor* objb = new CObjCorridor();

	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_ROOM, 9);
	//Objs::InsertObj(objb1_2, OBJ_ROOM, 9);

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
}


//実行中メゾット
void CSceneCorridor1::Scene()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//Test Corridorオブジェクト生成
	CObjCorridor* objb = new CObjCorridor();
	//Test Corridor1オブジェクト生成
	CObjCorridor1* objb1 = new CObjCorridor1();


	//Corridor1_1オブジェクト生成
	CObjCorridor1_1* objb1_1 = new CObjCorridor1_1();
	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();
	//Corridor1_3オブジェクト生成
	CObjCorridor1_3* objb1_3 = new CObjCorridor1_3();
	//Staffroomオブジェクト生成
	CObjStaffroom* objbs = new CObjStaffroom();
	//Principalofficeオブジェクト生成
	CObjPrincipaloffice* objbp = new CObjPrincipaloffice();
	//Infirmaryオブジェクト生成
	CObjInfirmary* objbi = new CObjInfirmary();
	//Corridor2_1オブジェクト生成
	CObjCorridor2_1* objb2_1 = new CObjCorridor2_1();
	//Corridor2_2オブジェクト生成
	CObjCorridor2_2* objb2_2 = new CObjCorridor2_2();
	//Corridor2_3オブジェクト生成
	CObjCorridor2_3* objb2_3 = new CObjCorridor2_3();
	//Corridor2_1オブジェクト生成
	CObjMap7* objb3_1 = new CObjMap7();
	//Corridor2_2オブジェクト生成
	CObjMap8* objb3_2 = new CObjMap8();
	//Corridor2_3オブジェクト生成
	CObjMap9* objb3_3 = new CObjMap9();
	//Enemy生成
	CObjEnemy* objh = new CObjEnemy(0, 0);
	//Enemy2生成
	CObjEnemy2* objh2 = new CObjEnemy2(0, 0);

	CHitBox* hit = Hits::GetHitBox(this);

	/*
	CHitBox* hit1_1 = Hits::GetHitBox(this);
	CHitBox* hit1_2 = Hits::GetHitBox(this);
	CHitBox* hit1_3 = Hits::GetHitBox(this);
	*/

	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;
	m_flag_Staffroom = false;
	m_flag_Principaloffice = false;
	m_flag_Infirmary = false;
	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;

	m_flag_go = false;

	//1階
		//廊下1-1画面端右に行くと廊下1-2へ移動
		if (hx + 64.0f > 800.0f && m_Corridor_co == 1
			&& m_flag_go == false && m_Storey == 1)
		{
			m_flag_Corridor1_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 1;
		}

		//廊下1-3画面端左に行くと廊下1-2へ移動
		if (hx < 0.0f && m_Corridor_co == 3 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 1;
		}
	
		//廊下1-2画面端左に行くと廊下1-1へ移動
		if (hx < 0.0f && m_Corridor_co == 2 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 1;
		}

		//廊下1-2画面端右に行くと廊下1-3へ移動
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 1)
		{
			m_flag_Corridor1_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
			m_Storey = 1;
		}

		//廊下1-2画面端上に行くと廊下2-2へ移動
		if (hy < 0.0f && Input::GetVKey(VK_RETURN) == true
			&& m_Corridor_co == 2 && m_flag_go == false 
			&& m_Storey == 1)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 2;
			m_time = 0;
		}

		//廊下1-1画面下に行くと職員室へ移動
		if (hy > 450.0f && m_Corridor_co == 1 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Staffroom = true;
			m_flag_go = true;
			m_Corridor_co = 4;
			m_Storey = 1;
		}

		//職員室画面上に行くと廊下1-1へ移動
		if (hy < 70.0f && m_Corridor_co == 4 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 1;
		}

		//廊下1-1画面上に行くと校長室へ移動
		if (hy < 120.0f && m_Corridor_co == 1 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Principaloffice = true;
			m_flag_go = true;
			m_Corridor_co = 5;
			m_Storey = 1;
		}

		//校長室画面下に行くと廊下1-1へ移動
		if (hy + 64.0f > 600.0f&&m_Corridor_co == 5 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 1;
		}

		//廊下1-3画面上に行くと保健室へ移動
		if (hy < 120.0f && m_Corridor_co == 3 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Infirmary = true;
			m_flag_go = true;
			m_Corridor_co = 6;
			m_Storey = 1;
		}

		//保健室画面下に行くと廊下1-3へ移動
		if (hy + 64.0f > 600.0f&&m_Corridor_co == 6 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
			m_Storey = 1;
		}


	//2階
		//廊下2-1画面端右に行くと廊下2-2へ移動
		if (hx + 64.0f > 800.0f && m_Corridor_co == 1
			&& m_flag_go == false && m_Storey == 2)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 2;
		}

		//廊下2-3画面端左に行くと廊下2-2へ移動
		if (hx < 0.0f && m_Corridor_co == 3 && m_flag_go == false
			&& m_Storey == 2)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 2;
		}

		//廊下2-2画面端左に行くと廊下2-1へ移動
		if (hx < 0.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 2)
		{
			m_flag_Corridor2_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 2;
		}

		//廊下2-2画面端右に行くと廊下2-3へ移動
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 2)
		{
			m_flag_Corridor2_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
			m_Storey = 2;
		}
		
		//廊下2-2画面端上に行くと廊下3-2へ移動
		if (hy < 0.0f && Input::GetVKey(VK_SPACE) == true
			&& m_Corridor_co == 2 && m_flag_go == false
			&& m_Storey == 2)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 3;
			m_time = 0;
		}


	//3階
	//廊下3-1画面端右に行くと廊下3-2へ移動
		if (hx + 64.0f > 800.0f && m_Corridor_co == 1
			&& m_flag_go == false && m_Storey == 3)
		{
			m_flag_Corridor3_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 3;
		}

		//廊下3-3画面端左に行くと廊下3-2へ移動
		if (hx < 0.0f && m_Corridor_co == 3 && m_flag_go == false
			&& m_Storey == 3)
		{
			m_flag_Corridor3_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 3;
		}

		//廊下3-2画面端左に行くと廊下3-1へ移動
		if (hx < 0.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 3)
		{
			m_flag_Corridor3_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 3;
		}

		//廊下3-2画面端右に行くと廊下3-3へ移動
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			 && m_Storey == 3)
		{
			m_flag_Corridor3_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
			m_Storey = 3;
		}


	//画面端上に行くとクリア画面
	if (hy < 0.0f && Input::GetVKey(VK_SHIFT) == true)
	{
		Scene::SetScene(new CSceneClear());
	}


		
	//描画処理
	//描画させる処理
	if (m_flag_Corridor1_1 == true && m_Corridor_co == 1
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		//Objs::InsertObj(objb1, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_1, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_2 == true && m_Corridor_co == 2
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		//Objs::InsertObj(objb1, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_2, OBJ_ROOM, 9);
		
		Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);
	}
	
	if (m_flag_Corridor1_3 == true && m_Corridor_co == 3
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下1-3.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Staffroom == true && m_Corridor_co == 4
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objbs, OBJ_ROOM, 9);

		Draw::LoadImage(L"職員室.PNG", 9, TEX_SIZE_512);
	}

	if (m_flag_Principaloffice == true && m_Corridor_co == 5
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objbp, OBJ_ROOM, 9);

		Draw::LoadImage(L"校長室.PNG", 9, TEX_SIZE_512);
	}

	if(m_flag_Infirmary == true && m_Corridor_co == 6
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objbi, OBJ_ROOM, 9);

		Draw::LoadImage(L"保健室.PNG", 9, TEX_SIZE_512);
	}


	if (m_flag_Corridor2_1 == true && m_Corridor_co == 1
		&& m_Storey == 2)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb2_1, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下2-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_2 == true && m_Corridor_co == 2
		&& m_Storey == 2)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb2_2, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下2-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_3 == true && m_Corridor_co == 3
		&& m_Storey == 2)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb2_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下2-3.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_1 == true && m_Corridor_co == 1
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_1, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下3-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_2 == true && m_Corridor_co == 1
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_2, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下3-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_3 == true && m_Corridor_co == 1
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下3-3.png", 9, TEX_SIZE_512);
	}


	//描画をなくす処理
	if (hx>=100.0f && m_flag_Corridor1_1 == false)
	{
		//Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_1, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-1.png", 9, TEX_SIZE_512);

	}

	if (hx >= 750.0f &&m_flag_Corridor1_2 == false)
	{
		//Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_2, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_3 == false)
	{
		//Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_3, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-3.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_1 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_1, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_2 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_2, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_3 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_3, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-3.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_1 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_1, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_2 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_2, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_3 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_3, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"廊下1-3.png", 9, TEX_SIZE_512);
	}


	/*
	m_time++;

	//敵オブジェクト作成(二宮金次郎)・敵出現時BGM変更
	if (m_time == 90 && m_Storey == 1)
	{
	Objs::InsertObj(objh, OBJ_ENEMY, 11);

	Draw::LoadImage(L"二宮金次郎透過.png", 11, TEX_SIZE_512);

	Audio::Stop(0);
	Audio::Start(1);
	}

	//敵オブジェクト作成(ぬいぐるみ)・敵出現時BGM変更
	if (m_time == 90 && m_Storey == 2)
	{
	Objs::InsertObj(objh2, OBJ_ENEMY, 11);

	Draw::LoadImage(L"ぬいぐるみ透過.png", 11, TEX_SIZE_512);

	Audio::Stop(0);
	Audio::Start(1);
	}

	if (m_time == 90 && m_Storey == 3)
	{
	Objs::InsertObj(objh2, OBJ_ENEMY, 11);

	Draw::LoadImage(L"絵画.png", 11, TEX_SIZE_512);

	Audio::Stop(0);
	Audio::Start(1);
	}

	*/

}
