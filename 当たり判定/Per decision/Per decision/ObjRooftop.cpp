//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjRooftop.h"
//#include "ObjHitBoxHER.h"//�ƒ�Ȏ�

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;
//
//extern float g_enemy_x = 150.0f;
//extern float g_enemy_y = 0.0f;
//


//�C�j�V�����C�Y
void CObjRooftop::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//�ƒ�Ȏ������蔻��
	HitBoxs Hit[17] =
	{
		{ -58, 	0,	128,  128, 0, },//����
		{ 130,  -413,  541,  541, 1, },//�^�񒆕�
		{ 731,     0,  128,  128, 2, },//�E��
		{ 0,   584,  400,  400, 3, },//��
		{ 400,   584,  400,  400, 4, },//��
		{ -399,   146,  438,  438, 5, },//���I
		{ 170,   190,  140,  140, 6, },//��A���̊�
		{ 370,   190,  120,  120, 7, },//��A�^�񒆂̊�
		{ 550,   190,  120,  120, 8, },//��A�E�̊�
		{ 170,   410,  125,  125, 9, },//���A���̊�
		{ 367,   410,  125,  125, 10, },//���A�^�񒆂̊�
		{ 545,   410,  120,  120, 11, },//���A�E�̊�
		{ 715,   300,   33,   33, 12, },
		{ 715,   333,   33,   33, 13, },
		{ 715,   366,   33,   33, 14, },
		{ 715,   399,   33,   33, 15, },
		{ 715,   432,   33,   33, 16, },//11�`16�܂ŋ���


	};

	for (int i = 0; i <17; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//�A�N�V����
void CObjRooftop::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	////�G�̈ʒu
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();

	/*
	//��ɍs���ƘL��2-1�ɍs��
	if (hy > 50 == true && hy < 100 == true)
	{
	if (m_key_flag == true)
	{
	//��l��
	g_hero_x = hx;
	g_hero_y = 110;
	//�G
	//g_enemy_x = 110;

	m_key_flag = false;
	}
	}
	else
	{
	m_key_flag = true;
	}

	*/



}

//�h���[
void CObjRooftop::Draw()
{
	/*
	//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 852.0f;
	src.m_bottom = 506.0f;

	//�w�i�P�̈ʒu�̐ݒ�����`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	*/



	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		//�w�i�P�̈ʒu�̐ݒ�����`��
	//		dst.m_top = 0.0f;
	//		dst.m_left = 0.0f + m_scroll;
	//		dst.m_right = 1716.0f + m_scroll;
	//		dst.m_bottom = 600.0f;
	//		Draw::Draw(0, &src, &dst, c, 0.0f);

	//	}
	//}

}