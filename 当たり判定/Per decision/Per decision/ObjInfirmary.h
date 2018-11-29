#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjInfirmary :public CObj
{
public:
	CObjInfirmary() {};
	~CObjInfirmary() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー


	//ブロックの当たり判定
	void InfirmaryHit
	(
		float * x, float * y, bool scroll_on,
		bool * up, bool * down, bool * left, bool * right,
		float * vx, float * vy, int * bt
	);

	//主人公と壁の交差判定
	bool HeroInfirmaryCrossPoint(
		float x, float y, float vx, float vy,
		float * out_px, float * out_py, float * out_len
	);


private:

	float Dot(float ax, float ay, float bx, float by); //内積
	float Cross(float ax, float ay, float bx, float by); //外積

														 //線と線の交差判定
	bool CObjInfirmary::LineCrossPoint(
		float a1x, float a1y, float a2x, float a2y,
		float b1x, float b1y, float b2x, float b2y,
		float * out_px, float * out_py
	);


};
