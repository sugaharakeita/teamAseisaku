#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_TITLE,
	OBJ_BLOCK,
	OBJ_ENEMY,
	OBJ_GAME_OVER,
	OBJ_MAP,
	OBJ_PROLOGUE,
	OBJ_KOUTYOUSITU,
	OBJ_HOKENSITU,

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
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_STAFFROOM,
	ELEMENT_PRINCIPALOFFICE,
	ELEMENT_INFIRMARY,
	ELEMENT_CORRIDOR1_1,
	ELEMENT_CORRIDOR1_2,
	ELEMENT_CORRIDOR1_3,

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
#include "ObjHero.h"
#include "ObjBlock.h"
#include "ObjTitle.h"
#include "ObjEnemy.h"
#include "ObjGameOver.h"
#include "ObjMap.h"
#include "ObjMap2.h"
#include "ObjMap3.h"
#include "ObjPrologue.h"
#include "ObjKoutyousitu.h"
#include "ObjHokensitu.h"
#include "ObjCorridor1_1.h"
#include "ObjCorridor1_2.h"
#include "ObjCorridor1_3.h"
#include "ObjInfirmary.h"
#include "ObjKoutyousitu.h"
#include "ObjObstacle.h"
#include "ObjPrincipaloffice.h"
#include "ObjStaffroom.h"
#include "RoomHitBox.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneMain2.h"
#include "SceneMain3.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneCorridor1_1.h"
#include "SceneCorridor1_2.h"
#include "SceneCorridor1_3.h"
#include "SceneInfirmary.h"
#include "ScenePrincipaloffice.h"
#include "SceneStaffroom.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------