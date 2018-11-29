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
	OBJ_CLEAR,
	OBJ_TITLE,
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



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjStaffroom.h"
#include "ObjPrincipaloffice.h"
#include "ObjInfirmary.h"
#include "ObjCorridor1_1.h"
#include "ObjCorridor1_2.h"
#include "ObjCorridor1_3.h"
#include "ObjHero.h"
#include "ObjClear.h"
#include "ObjTitle.h"
#include "ObjPerdecision.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneStaffroom.h"
#include "ScenePrincipaloffice.h"
#include "SceneInfirmary.h"
#include "SceneCorridor1_1.h"
#include "SceneCorridor1_2.h"
#include "SceneCorridor1_3.h"
#include "SceneClear.h"
#include "SceneTitle.h"
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
#define SET_GAME_START  CSceneClear
*/
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------