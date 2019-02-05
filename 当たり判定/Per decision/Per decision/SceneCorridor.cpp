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
#include "SceneCorridor.h"
#include "GameHead.h"

//コンストラクタ
CSceneCorridor::CSceneCorridor()
{

}

//デストラクタ
CSceneCorridor::~CSceneCorridor()
{

}

//初期化メゾット
void CSceneCorridor::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(0, L"黒い足音.wav", BACK_MUSIC); //通常　廊下1
	Audio::LoadAudio(1, L"死神の斧.wav", BACK_MUSIC); //Enemy出現

	
	Audio::LoadAudio(2, L"学校の廊下を歩く .wav", BACK_MUSIC); //主人公足音
	Audio::LoadAudio(4, L"教室の扉開閉２ .wav", EFFECT); //教室移動
	Audio::LoadAudio(5, L"足音01　階段 .wav", EFFECT); //階段移動

	//ボリュームを0.8減らす
	float v = Audio::VolumeMaster(0.8);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);

	//秒数カウント初期化
	m_time = 0;

	//エリア移動フラグ初期化
	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;
	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;
	m_flag_Rooftop = false;

	//エリア番号 1=1-1,2-1,3-1  2=1-2,2-2,3-2  3=1-3,2-3,3-3
	m_Corridor_co = 2;

	//階層分け初期化
	m_Storey = 1;


	//連続移動防止フラグ初期化
	m_flag_go = false;

	//Test Corridorオブジェクト生成
	CObjCorridor* objb = new CObjCorridor();
	//Test Corridor1オブジェクト生成
	CObjCorridor1* objb1 = new CObjCorridor1();


	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();


	Objs::InsertObj(objb1, OBJ_ROOM, 9);
	Objs::InsertObj(objb1_2, OBJ_ROOM, 9);

	Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);
	


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);


	//グラフィック読み込み
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);
}


//実行中メゾット
void CSceneCorridor::Scene()
{

	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//描画情報
	//Test Corridorオブジェクト生成
	CObjCorridor* objb = new CObjCorridor();
	//Test Corridor1オブジェクト生成
	CObjCorridor1* objb1 = new CObjCorridor1();


	//1階
	//Corridor1_1オブジェクト生成
	CObjCorridor1_1* objb1_1 = new CObjCorridor1_1();
	//Corridor1_2オブジェクト生成
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();
	//Corridor1_3オブジェクト生成
	CObjCorridor1_3* objb1_3 = new CObjCorridor1_3();

	//2階
	//Corridor2_1オブジェクト生成
	CObjCorridor2_1* objb2_1 = new CObjCorridor2_1();
	//Corridor2_2オブジェクト生成
	CObjCorridor2_2* objb2_2 = new CObjCorridor2_2();
	//Corridor2_3オブジェクト生成
	CObjCorridor2_3* objb2_3 = new CObjCorridor2_3();
	
	//3階
	//Corridor3_1オブジェクト生成
	CObjMap7* objb3_1 = new CObjMap7();
	//Corridor3_2オブジェクト生成
	CObjMap8* objb3_2 = new CObjMap8();
	//Corridor3_3オブジェクト生成
	CObjMap9* objb3_3 = new CObjMap9();

	//屋上
	//Rooftopオブジェクト生成
	CObjRooftop* obj_br = new CObjRooftop();

	//敵
	//Enemy生成
	CObjEnemy* objh = new CObjEnemy(0, 0);
	//Enemy2生成
	CObjEnemy2* objh2 = new CObjEnemy2(0, 0);
	//Enemy3生成
	CObjEnemy3* objh3 = new CObjEnemy3(0, 0);


	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;

	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;

	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;

	m_flag_Rooftop = false;

	m_flag_go = false;

	float v4 = Audio::VolumeMaster(4);
	v4 = Audio::VolumeMaster(0.5);
	float v5 = Audio::VolumeMaster(5);
	v5 = Audio::VolumeMaster(0.5);
	

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

		//廊下1-2画面端右に行くと廊下1-3へ移動
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 1)
		{
			m_flag_Corridor1_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
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


		//廊下1-2画面端上に行くと廊下2-2へ移動
		if (hy < 0.0f &&  m_Corridor_co == 2 && m_flag_go == false 
			&& m_Storey == 1 && Input::GetVKey(VK_RETURN) == true)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 2;
			m_time = 0;
			Audio::Stop(1);
			Audio::Start(5);
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

		//廊下2-2画面端右に行くと廊下2-3へ移動
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 2)
		{
			m_flag_Corridor2_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
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

		
		//廊下2-2画面端上に行くと廊下3-2へ移動
		if (hy < 0.0f && m_Corridor_co == 2 && m_flag_go == false
			&& m_Storey == 2 && Input::GetVKey(VK_RETURN) == true)
		{
			m_flag_Corridor3_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 3;
			m_time = 0;
			Audio::Stop(1);
			Audio::Start(5);
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

		//廊下3-2画面端右に行くと廊下3-3へ移動
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_Storey == 3)
		{
			m_flag_Corridor3_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
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

		//廊下3-2画面端上に行くと屋上へ移動
		if (hy < 0.0f && m_Corridor_co == 2 && m_flag_go == false
			&& m_Storey == 3 && Input::GetVKey(VK_RETURN) == true)
		{
			m_flag_Rooftop = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 4;
			m_time = 0;
			Audio::Stop(1);
			Audio::Start(5);
		}


	//屋上画面端上に行くとクリア画面
	if (hy < 0.0f && Input::GetVKey(VK_RETURN) == true
		&& m_Storey == 4 && m_Corridor_co == 2)
	{
		Scene::SetScene(new CSceneClear());
	}


		
	//描画処理
	//描画させる処理
	//1階
	if (m_flag_Corridor1_1 == true)
	{
		Objs::InsertObj(objb1, OBJ_ROOM, 9); //画像
		Objs::InsertObj(objb1_1, OBJ_ROOM, 9); //当たり判定

		Draw::LoadImage(L"廊下1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_2 == true)
	{
		Objs::InsertObj(objb1, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_2, OBJ_ROOM, 9);
		
		Draw::LoadImage(L"廊下1-2.png", 9, TEX_SIZE_512);
	}
	
	if (m_flag_Corridor1_3 == true)
	{
		Objs::InsertObj(objb1, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下1-3.png", 9, TEX_SIZE_512);
	}


	//2階
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


	//3階
	if (m_flag_Corridor3_1 == true && m_Corridor_co == 1
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_1, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下3-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_2 == true && m_Corridor_co == 2
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_2, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下3-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_3 == true && m_Corridor_co == 3
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"廊下3-3.PNG", 9, TEX_SIZE_512);
	}
	

	//屋上
	if (m_flag_Rooftop == true && m_Corridor_co == 2
		&& m_Storey == 4)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(obj_br, OBJ_ROOM, 9);

		Draw::LoadImage(L"屋上.png", 9, TEX_SIZE_512);
	}

	m_time++;



	/*
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
	
	//敵オブジェクト作成(絵画)・敵出現時BGM変更
	if (m_time == 90 && m_Storey == 3)
	{
	Objs::InsertObj(objh3, OBJ_ENEMY, 11);

	Draw::LoadImage(L"絵画.png", 11, TEX_SIZE_512);

	Audio::Stop(0);
	Audio::Start(1);
	}

	*/

}
