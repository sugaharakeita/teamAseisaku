//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHokensitu.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHokensitu::Init()
{
	m_x = 14;
	m_y = 13;
	
	//当たり判定用HitBoxを作成
	//Hits::SetHitBox(this, m_x, m_y, 64, 150, ELEMENT_BLUE, OBJ_HOKENSITU, 1);

}

//アクション
void CObjHokensitu::Action()
{

	////HitBoxの内容を更新
	//CHitBox* hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);


	////青HitBoxと接触したら主人公削除
	//if (hit->CheckObjNameHit(OBJ_HOKENSITU) != nullptr)
	//{
	//	this->SetStatus(false);     //自身に削除命令を出す
	//	Hits::DeleteHitBox(this);   //主人公が所有するHitBoxを削除する
	//}
}

//ドロー
void CObjHokensitu::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	RECT_F src;  //描画元切り取り位置
	RECT_F dst;  //描画先表示位置

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 722.0f;
	src.m_bottom = 375.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 450.0f;
	
	//描画
	Draw::Draw(5, &src, &dst, c, 0.0f);
}