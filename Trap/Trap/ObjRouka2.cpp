#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "SwitchALL.h"
#include "ObjRouka2.h"
#include "GameHead.h"

using namespace GameL;

int CObjRouka2::GetMap(int x, int y)
{
	if (x < MAP_MIN)return MAP_ERROR;
	if (y < MAP_MIN)return MAP_ERROR;
	if (x >= MAP_X_MAX)return MAP_WALL;
	if (y >= MAP_Y_MAX)return MAP_BOTTOM;
	return m_map[y][x];
}

void CObjRouka2::SetMap(int x, int y, int id)
{
	if (x < MAP_MIN)return;
	if (y < MAP_MIN)return;
	if (x >= MAP_X_MAX)return;
	if (y >= MAP_Y_MAX)return;
	m_map[y][x] = id;
	return;
}

void CObjRouka2::Init()
{
	m_time = 0;
	ev_mass = 0;
}

void CObjRouka2::Action()
{
	m_time++;
	if (room[7] == 1)//�Q�K�L�������ɋ���ꍇ
	{
		if (HeroX <= 11.0f)
			HeroX = 11.0f;
		if (HeroX >= 756.0f)
		{
			room[7] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka2C = room[8] = 1;//�Q�K�L�������Ɉړ�����
			Scene::SetScene(new CSceneRouka2());//�ړ���̃V�[���ɍ��킹��
		}
		if (HeroY <= 140.0f)
			HeroY = 140.0f;
		if (HeroY >= 440.0f)
			HeroY = 440.0f;
		if (m_time == 5)
			Rouka2C = Tosho = Kateika = 0;//SwitchALL�̍���������邽��
	}
	else if (room[8] == 1)//�Q�K�L�������ɋ���ꍇ
	{
		if (HeroX <= -20.0f)
		{
			room[8] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka2L = room[7] = 1;//�Q�K�L�������Ɉړ�����
			Scene::SetScene(new CSceneRouka2());//�ړ���̃V�[���ɍ��킹��
		}
		if (HeroX >= 756.0f)
		{
			room[8] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka2R = room[9] = 1;//�Q�K�L���E���Ɉړ�����
			Scene::SetScene(new CSceneRouka2());//�ړ���̃V�[���ɍ��킹��
		}
		if (HeroY <= 140.0f)
			HeroY = 140.0f;
		if (HeroY >= 440.0f)
			HeroY = 440.0f;
		if (m_time == 5)
			Rouka1CR = Rouka2L = Rouka2R = KateikaJunbi = 0;//SwitchALL�̍���������邽��
	}
	else if (room[9] == 1)//�Q�K�L���E���ɋ���ꍇ
	{
		if (HeroX <= -20.0f)
		{
			room[9] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka2C = room[8] = 1;//�Q�K�L�������Ɉړ�����
			Scene::SetScene(new CSceneRouka2());//�ړ���̃V�[���ɍ��킹��
		}
		if (HeroX >= 756.0f)
			HeroX = 756.0f;
		if (HeroY <= 140.0f)
			HeroY = 140.0f;
		if (HeroY >= 540.0f)
			HeroY = 540.0f;
		if (m_time == 5)
			Rouka2C = Kyoushitu = 0;//SwitchALL�̍���������邽��
	}
}

void CObjRouka2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,0.45f };
	RECT_F src;
	RECT_F dst;

	if (room[7] == 1)//�Q�K�L�������ɋ���ꍇ
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 650.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	else if (room[8] == 1)//�Q�K�L�������ɋ���ꍇ
	{
		src.m_top = 0.0f;
		src.m_left = 650.0f;
		src.m_right = 1300.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	else if (room[9] == 1)//�Q�K�L���E���ɋ���ꍇ
	{
		src.m_top = 0.0f;
		src.m_left = 1300.0f;
		src.m_right = 1779.0f;
		src.m_bottom = 362.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
}