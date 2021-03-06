#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_TITLE,
	OBJ_HELP,
	OBJ_MAIN,
	OBJ_HERO,
	OBJ_EXCLAMATION,
	OBJ_MESSAGE,
	OBJ_MENU,
	OBJ_SWITCH,
	OBJ_TEXTURE,
	OBJ_KEY,
	KOUCHOU_KEY,
	HOKEN_KEY,
	OBJ_WALL,
	OBJ_HAKO,
	KOUCHOU_DOOR,
	OBJ_HAMMER,
	SHOKUIN_DOOR,
	HOKEN_DOOR,
	KATEIKA_KEY,
	TOSHO_KEY,
	KATEIKA_DOOR,
	KATEIKAJUNBI_DOOR,
	KYOUSHITU_DOOR,
	TOSHO_DOOR,
};
//------------------------------------------------

enum SPOT_NAME
{
	SPOT_ROUKA1,
	SPOT_KOUCHOU,
	SPOT_SHOKUIN,
	SPOT_HOKEN,
	SPOT_ROUKA2,
	SPOT_KATEIKA,
	SPOT_KATEIKAJUNBI,
	SPOT_KYOUSHITU,
	SPOT_TOSHO,
};

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
	ELEMENT_SPOT,
	ELEMENT_OBJECT,
	ELEMENT_DOOR,
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
#include "ObjTitle.h"
#include "ObjHelp.h"
#include "SwitchALL.h"
#include "ItemALL.h"
#include "TrapALL.h"
#include "TextALL.h"
#include "Message.h"
#include "Menu.h"
#include "Hero.h"
#include "!.h"
#include "ObjRouka1.h"
#include "KouchouHako.h"
#include "KouchouKey.h"
#include "ObjKouchouDoor.h"
#include "ObjKouchou.h"
#include "Hammer.h"
#include "ObjShokuinDoor.h"
#include "ObjShokuin.h"
#include "ShokuinPaper.h"
#include "HokenKey.h"
#include "ObjHokenDoor.h"
#include "ObjHoken.h"
#include "ObjRouka2.h"
#include "ObjKateikaDoor.h"
#include "ObjKateikaJunbiDoor.h"
#include "ObjKyoushituDoor.h"
#include "ObjToshoDoor.h"
#include "ObjKateika.h"
#include "ObjKateikaJunbi.h"
#include "ObjKyoushitu.h"
#include "ObjTosho.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneTitle.h"
#include "SceneHelp.h"
#include "SceneRouka1.h"
#include "SceneKouchou.h"
#include "SceneShokuin.h"
#include "SceneHoken.h"
#include "SceneRouka2.h"
#include "SceneKateika.h"
#include "SceneKateikaJunbi.h"
#include "SceneKyoushitu.h"
#include "SceneTosho.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------