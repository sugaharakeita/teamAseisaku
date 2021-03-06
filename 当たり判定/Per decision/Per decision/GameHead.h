#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_TIME,
	OBJ_ENEMY,
	OBJ_STAFFROOM,
	OBJ_PRINCIPALOFFICE,
	OBJ_INFIRMARY,
	OBJ_CORRIDOR1_1,
	OBJ_CORRIDOR1_2,
	OBJ_CORRIDOR1_3,
	OBJ_CORRIDOR2_1,
	OBJ_CORRIDOR2_2,
	OBJ_CORRIDOR2_3,
	OBJ_ROOM,
	OBJ_CLEAR,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_BACKGROUND,
	OBJ_PROLOGUE,
	OBJ_HITBOX,
	OBJ_MAP,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_FIELD,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ

};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--
struct HitBoxs
{
	int pos_x;			//当たり判定x座標
	int pos_y;			//当たり判定y座標
	int height;			//当たり判定高さ
	int width;			//当たり判定横幅
	int id;	//当たり判定
};



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjStaffroom.h"
#include "ObjPrincipaloffice.h"
#include "ObjHitBox.h"
#include "ObjInfirmary.h"
#include "ObjCorridor1_1.h"
#include "ObjCorridor1_2.h"
#include "ObjCorridor1_3.h"
#include "ObjCorridor2_1.h"
#include "ObjCorridor2_2.h"
#include "ObjCorridor2_3.h"
#include "ObjMap7.h"
#include "ObjMap8.h"
#include "ObjMap9.h"
#include "ObjClassroom.h"
#include "ObjHomeeconomicsroom.h"
#include "ObjHomepreparationroom.h"
#include "ObjComputerroom.h"
#include "ObjMusicroom.h"
#include "ObjConferenceroom.h"
#include "ObjRooftop.h"
#include "ObjHero.h"
#include "ObjClear.h"
#include "ObjTitle.h"
#include "ObjPerdecision.h"
#include "ObjLibrary.h"
#include "ObjEnemy.h"
#include "ObjEnemy2.h"
#include "ObjEnemy3.h"
#include "ObjGameOver.h"
#include "ObjBackground.h"
#include "ObjCorridor.h"
#include "ObjCorridor1.h"
//#include "ObjCorridor2.h"
//#include "ObjCorridor3.h"
//#include "ObjCorridor4.h"
#include "ObjPrologue.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneInfirmary.h"
#include "SceneCorridor1_1.h"
#include "SceneCorridor1_2.h"
#include "SceneCorridor1_3.h"
#include "SceneStaffroom.h"
#include "ScenePrincipaloffice.h"
#include "SceneInfirmary.h"
#include "SceneCorridor2_1.h"
#include "SceneCorridor2_2.h"
#include "SceneCorridor2_3.h"
#include "SceneClassroom.h"
#include "SceneHomeeconomicsroom.h"
#include "SceneHomepreparationroom.h"
#include "SceneLibrary.h"
#include "SceneMain7.h"
#include "SceneMain8.h"
#include "SceneMain9.h"
#include "SceneConferenceroom.h"
#include "SceneComputerroom.h"
#include "SceneMusicroom.h"
#include "SceneClear.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneCorridor.h"
#include "SceneCorridor1.h"
#include "ScenePrologue.h"
#include "SceneRooftop.h"

//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
/*
#define SET_GAME_START  CSceneStaffroom
#define SET_GAME_START  CScenePrincipaloffice
#define SET_GAME_START  CSceneInfirmary
#define SET_GAME_START  CSceneCorridor1_1
#define SET_GAME_START  CSceneCorridor1_2
#define SET_GAME_START  CSceneCorridor1_3
#define SET_GAME_START  CSceneCorridor2_1
#define SET_GAME_START  CSceneCorridor2_2
#define SET_GAME_START  CSceneCorridor2_3
#define SET_GAME_START  CSceneHomeeconomicsroom
#define SET_GAME_START  CSceneClear
#define SET_GAME_START  CSceneTitle
*/

#define SET_GAME_START  CSceneCorridor
//-----------------------------------------------