#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "SwitchALL.h"
#include "ObjRouka1.h"
#include "GameHead.h"

using namespace GameL;

int CObjRouka1::GetMap(int x, int y)
{
	if (x < MAP_MIN)return MAP_ERROR;
	if (y < MAP_MIN)return MAP_ERROR;
	if (x >= MAP_X_MAX)return MAP_WALL;
	if (y >= MAP_Y_MAX)return MAP_BOTTOM;
	return m_map[y][x];
}

void CObjRouka1::SetMap(int x, int y, int id)
{
	if (x < MAP_MIN)return;
	if (y < MAP_MIN)return;
	if (x >= MAP_X_MAX)return;
	if (y >= MAP_Y_MAX)return;
	m_map[y][x] = id;
	return;
}

void CObjRouka1::Init()
{
	m_time = 0;
	ev_mass = 0;
	ev_time = 0;
}

void CObjRouka1::Action()
{
	m_time++;
	if (room[0] == 1)//１階廊下左側に居る場合
	{
		if (HeroX <= 11.0f)
			HeroX = 11.0f;
		if (HeroX >= 756.0f)
		{
			room[0] = 0;//この部屋からは居なくなる
			Rouka1CL = room[1] = 1;//１階廊下中央左側に移動する
			Scene::SetScene(new CSceneRouka1());//移動後のシーンに合わせる
		}
		if (m_time == 5)//SwitchALLの混同を避けるため
			Rouka1CL = Kouchou = Shokuin = 0;
	}
	else if (room[1] == 1)//１階廊下中央左側に居る場合
	{
		if (HeroX <= -20.0f)
		{
			room[1] = 0;//この部屋からは居なくなる
			Rouka1L = room[0] = 1;//１階廊下左側に移動する
			Scene::SetScene(new CSceneRouka1());//移動後のシーンに合わせる
		}
		if (HeroX >= 756.0f)
		{
			room[1] = 0;//この部屋からは居なくなる
			Rouka1CR = room[2] = 1;//１階廊下中央右側に移動する
			Scene::SetScene(new CSceneRouka1());//移動後のシーンに合わせる
		}
		if (m_time == 5)//SwitchALLの混同を避けるため
			Rouka1L = Rouka1CR = Shokuin = 0;
	}
	else if (room[2] == 1)//１階廊下中央右側に居る場合
	{
		if (HeroX <= -20.0f)
		{
			room[2] = 0;//この部屋からは居なくなる
			Rouka1CL = room[1] = 1;//１階廊下中央左側に移動する
			Scene::SetScene(new CSceneRouka1());//移動後のシーンに合わせる
		}
		if (HeroX >= 756.0f)
		{
			room[2] = 0;//この部屋からは居なくなる
			Rouka1R = room[3] = 1;//１階廊下右側に移動する
			Scene::SetScene(new CSceneRouka1());//移動後のシーンに合わせる
		}
		if (m_time == 5)
			Rouka1CL = Rouka1R = 0;//SwitchALLの混同を避けるため、用済みになると0にする
		
		if (Hammer == 1 && Ham_flag ==false && ev_mass == 0)
		{	
			Message = 8;//8番にセットしたメッセージを表示する
			if (Message == 8 && Input::GetVKey(VK_BACK) == true)
				ev_mass = 1;//バックキーが入力された場合に進める
		}
		if (ev_mass == 1)//イベントメッセージが進められた場合にイベントタイムを加算する
			ev_time++;
		if (ev_time >= 20)//イベントタイムが一定値以上になった時に次のメッセージを表示する
		{	
			ev_time = 20;/*メッセージを進めていなくても次のメッセージに移る、
			またはすぐに次のメッセージに移ってしまうことがないようにする*/
			/*ここに金次郎が突っ込んでくるイベント
			CObjKinjiro* e1 = new CObjKinjiro(800,HeroY);
			Objs::InsertObj(e1, OBJ_KINJIRO, 2);*/

			Message = 9;//9番にセットしたメッセージを表示する
			if (Message == 9 && Input::GetVKey(VK_BACK) == true)
				ev_mass = 2;//バックキーが入力された場合に進める
		}
		if (ev_mass == 2)//イベントメッセージが進められた場合にイベントタイムを加算する
			ev_time++;
		if(ev_time >= 40)//イベントタイムが一定値以上になった時に次のメッセージを表示する
		{
			Message = 10;//9番にセットしたメッセージを表示する
			if (Message == 10 && Input::GetVKey(VK_BACK) == true)
				ev_mass = 3;//バックキーが入力された場合に進める
		}
		if (ev_mass == 3 && HeroY <= -48.0f)
		{
			room[2] = 0;//この部屋からは居なくなる
			Rouka2C = room[8] = 1;//２階廊下中央に移動する
			Scene::SetScene(new CSceneRouka2());
		}
	}
	else if (room[3] == 1)//１階廊下右側に居る場合
	{
		if (HeroX <= -20.0f)
		{
			room[3] = 0;//この部屋からは居なくなる
			Rouka1CR = room[2] = 1;//１階廊下中央右側に移動する
			Scene::SetScene(new CSceneRouka1());//移動後のシーンに合わせる
		}
		if (HeroX >= 736.0f)
			HeroX = 736.0f;
		if (m_time == 5)
			Rouka1CR = Hoken = 0;//SwitchALLの混同を避けるため
	}
}

void CObjRouka1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,0.45f };
	RECT_F src;
	RECT_F dst;

	if (room[0] == 1)//１階廊下左側に居る場合
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 518.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (room[1] == 1)//１階廊下中央左側に居る場合
	{
		src.m_top = 0.0f;
		src.m_left = 518.0f;
		src.m_right = 1035.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (room[2] == 1)//１階廊下中央右側に居る場合
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 384.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	else if (room[3] == 1)//１階廊下右側に居る場合
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 360.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(6, &src, &dst, c, 0.0f);
	}
}