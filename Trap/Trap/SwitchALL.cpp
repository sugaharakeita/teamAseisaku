#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "SwitchALL.h"
//ヒーロー関係
bool Hero;//主人公が生成されていることを示す。
int HERO = 3;//主人公の向き。0から右、左、下、上
int HeroStop;/*主人公の動きを止める。数字によって止まる向きが変わる。
0～3はHEROと同じ向きに動けない。４なら動けず、５なら止まらない*/
float HeroX;//主人公のＸ座標を取得する
float HeroY;//主人公のＹ座標を取得する
bool HeroL;//主人公は左側に居る
//以下主人公のヒットフラグ。
bool HIT_flag;//敵との接触判定
bool HAKO_flag;//箱との接触判定
bool DOOR_flag;//扉との接触判定
bool ITEM_flag;//アイテムとの接触判定
bool TEXT_flag;//紙など情報の得られる物体との接触判定
//システム関係
int Message;
int Text;
int Menu;
/*切り替え用。Titleはroom内に入らない。
roomは主人公の居る部屋を、Rouka1L以降はどの部屋から移ったかを管理する*/
int Title;
int room[32];
int Rouka1L;//１階廊下左側
int Rouka1CL;//１階廊下中央左側
int Rouka1CR;//１階廊下中央右側
int Rouka1R;//１階廊下右側
int Kouchou;
int Shokuin;
int Hoken;
int Rouka2L;//２階廊下左側
int Rouka2C;//２階廊下中央
int Rouka2R;//２階廊下右側
int Kateika;
int KateikaJunbi;
int Kyoushitu;
int Tosho;