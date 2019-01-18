//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMap7.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;
//
//extern float g_enemy_x = 150.0f;
//extern float g_enemy_y = 0.0f;
//


//�C�j�V�����C�Y
void CObjMap7::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;


	//�L��2-1�����蔻��
	HitBoxs Hit[5] =
	{
		{ 0,  -54,  229,  229, 0, },//�h�A���獶���̕�
		{ 335, -290,  465,  465, 1, },//�h�A����E���̕�
		{ -449,  175,  465,  465, 2, },//��ԍ��[
		{ 123,  495,  335,  335, 3, },//�ƒ�Ȏ���(��둤)�E���̕�
		{ 563,  495,  127,  127, 4, },//�ƒ�Ȏ���(�O��)�E���̕�

	};

	for (int i = 0; i < 5; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//�A�N�V����
void CObjMap7::Action()
{
	
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
	


	////�G�̈ʒu
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();

	
	if (hx + 64.0f > 787.0f || hy > 440.0f || hy < 110.0f)
	{
		Hits::DeleteHitBox(this);
		Hits::DeleteHitBox(this);
	}
	

	//�}�b�v�[�ɂ����ƘL��3-2�ɂ���
	if (hx >700 == true)
	{
		if (m_key_flag == true)
		{
			//��l��
			g_hero_x = 110;
			g_hero_y = hy;
			//�G
			//g_enemy_x = 110;
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//���ɍs���Ɠ�K�E�ƒ�Ȏ��ɍs���B
	if (hy > 450 == true)
	{
		if (hx < 350 == true)
		{
			if (m_key_flag == true)
			{
				g_hero_x = 650;
				g_hero_y = hy;
				m_key_flag = false;
			}
		}
	}
	else
	{
		m_key_flag = true;
	}

	//���ɍs���Ɠ�K�E�ƒ돀�����ɍs���B
	if (hy > 450 == true)
	{
		if (hx > 450 == true)
		{
			if (m_key_flag == true)
			{
				g_hero_x = 650;
				g_hero_y = hy;
				m_key_flag = false;
			}
		}
	}
	else
	{
		m_key_flag = true;
	}


	//��ɍs���Ɠ�K�E�}�����ɍs��
	if (hy < 100 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 650;
			g_hero_y = hy;
			//Scene::SetScene(new CSceneLibrary());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}




}

//�h���[
void CObjMap7::Draw()
{
	/*
		//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 1035.0f;
	src.m_bottom = 362.0f;

	////�w�i�P�̈ʒu�̐ݒ�����`��
	//dst.m_top = 0.0f;
	//dst.m_left = 0.0f + m_x1;
	//dst.m_right = 1716.0f + m_x1;
	//dst.m_bottom = 600.0f;
	//Draw::Draw(0, &src, &dst, c, 0.0f);



	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//�w�i�P�̈ʒu�̐ݒ�����`��
			dst.m_top = 0.0f;
			dst.m_left = 0.0f + m_scroll;
			dst.m_right = 1716.0f + m_scroll;
			dst.m_bottom = 600.0f;
			Draw::Draw(0, &src, &dst, c, 0.0f);

		}
	}

	*/

}