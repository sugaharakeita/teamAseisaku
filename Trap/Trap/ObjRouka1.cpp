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
	if (room[0] == 1)//�P�K�L�������ɋ���ꍇ
	{
		if (HeroX <= 11.0f)
			HeroX = 11.0f;
		if (HeroX >= 756.0f)
		{
			room[0] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka1CL = room[1] = 1;//�P�K�L�����������Ɉړ�����
			Scene::SetScene(new CSceneRouka1());//�ړ���̃V�[���ɍ��킹��
		}
		if (m_time == 5)//SwitchALL�̍���������邽��
			Rouka1CL = Kouchou = Shokuin = 0;
	}
	else if (room[1] == 1)//�P�K�L�����������ɋ���ꍇ
	{
		if (HeroX <= -20.0f)
		{
			room[1] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka1L = room[0] = 1;//�P�K�L�������Ɉړ�����
			Scene::SetScene(new CSceneRouka1());//�ړ���̃V�[���ɍ��킹��
		}
		if (HeroX >= 756.0f)
		{
			room[1] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka1CR = room[2] = 1;//�P�K�L�������E���Ɉړ�����
			Scene::SetScene(new CSceneRouka1());//�ړ���̃V�[���ɍ��킹��
		}
		if (m_time == 5)//SwitchALL�̍���������邽��
			Rouka1L = Rouka1CR = Shokuin = 0;
	}
	else if (room[2] == 1)//�P�K�L�������E���ɋ���ꍇ
	{
		if (HeroX <= -20.0f)
		{
			room[2] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka1CL = room[1] = 1;//�P�K�L�����������Ɉړ�����
			Scene::SetScene(new CSceneRouka1());//�ړ���̃V�[���ɍ��킹��
		}
		if (HeroX >= 756.0f)
		{
			room[2] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka1R = room[3] = 1;//�P�K�L���E���Ɉړ�����
			Scene::SetScene(new CSceneRouka1());//�ړ���̃V�[���ɍ��킹��
		}
		if (m_time == 5)
			Rouka1CL = Rouka1R = 0;//SwitchALL�̍���������邽�߁A�p�ς݂ɂȂ��0�ɂ���
		
		if (Hammer == 1 && Ham_flag ==false && ev_mass == 0)
		{	
			Message = 8;//8�ԂɃZ�b�g�������b�Z�[�W��\������
			if (Message == 8 && Input::GetVKey(VK_BACK) == true)
				ev_mass = 1;//�o�b�N�L�[�����͂��ꂽ�ꍇ�ɐi�߂�
		}
		if (ev_mass == 1)//�C�x���g���b�Z�[�W���i�߂�ꂽ�ꍇ�ɃC�x���g�^�C�������Z����
			ev_time++;
		if (ev_time >= 20)//�C�x���g�^�C�������l�ȏ�ɂȂ������Ɏ��̃��b�Z�[�W��\������
		{	
			ev_time = 20;/*���b�Z�[�W��i�߂Ă��Ȃ��Ă����̃��b�Z�[�W�Ɉڂ�A
			�܂��͂����Ɏ��̃��b�Z�[�W�Ɉڂ��Ă��܂����Ƃ��Ȃ��悤�ɂ���*/
			/*�����ɋ����Y���˂�����ł���C�x���g
			CObjKinjiro* e1 = new CObjKinjiro(800,HeroY);
			Objs::InsertObj(e1, OBJ_KINJIRO, 2);*/

			Message = 9;//9�ԂɃZ�b�g�������b�Z�[�W��\������
			if (Message == 9 && Input::GetVKey(VK_BACK) == true)
				ev_mass = 2;//�o�b�N�L�[�����͂��ꂽ�ꍇ�ɐi�߂�
		}
		if (ev_mass == 2)//�C�x���g���b�Z�[�W���i�߂�ꂽ�ꍇ�ɃC�x���g�^�C�������Z����
			ev_time++;
		if(ev_time >= 40)//�C�x���g�^�C�������l�ȏ�ɂȂ������Ɏ��̃��b�Z�[�W��\������
		{
			Message = 10;//9�ԂɃZ�b�g�������b�Z�[�W��\������
			if (Message == 10 && Input::GetVKey(VK_BACK) == true)
				ev_mass = 3;//�o�b�N�L�[�����͂��ꂽ�ꍇ�ɐi�߂�
		}
		if (ev_mass == 3 && HeroY <= -48.0f)
		{
			room[2] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka2C = room[8] = 1;//�Q�K�L�������Ɉړ�����
			Scene::SetScene(new CSceneRouka2());
		}
	}
	else if (room[3] == 1)//�P�K�L���E���ɋ���ꍇ
	{
		if (HeroX <= -20.0f)
		{
			room[3] = 0;//���̕�������͋��Ȃ��Ȃ�
			Rouka1CR = room[2] = 1;//�P�K�L�������E���Ɉړ�����
			Scene::SetScene(new CSceneRouka1());//�ړ���̃V�[���ɍ��킹��
		}
		if (HeroX >= 736.0f)
			HeroX = 736.0f;
		if (m_time == 5)
			Rouka1CR = Hoken = 0;//SwitchALL�̍���������邽��
	}
}

void CObjRouka1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,0.45f };
	RECT_F src;
	RECT_F dst;

	if (room[0] == 1)//�P�K�L�������ɋ���ꍇ
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
	else if (room[1] == 1)//�P�K�L�����������ɋ���ꍇ
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
	else if (room[2] == 1)//�P�K�L�������E���ɋ���ꍇ
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
	else if (room[3] == 1)//�P�K�L���E���ɋ���ꍇ
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