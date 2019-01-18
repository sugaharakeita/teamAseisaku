//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjComputerroom.h"
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
void CObjComputerroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//�ƒ�Ȏ������蔻��
	HitBoxs Hit[35] =
	{
		{    0, -708, 800, 800, 0, },//���
		{   77,   90,  57,  57, 1, },//����(��)
		{   67,  147,  67,  67, 2, },//����(��)
		{    0,  150,  16, 325, 3, },//�z���C�g�{�[�h
		{  170,  112,  80,  80, 4, },//��1(��)
		{  250,  112,  80,  80, 5, },//��2
		{  330,  112,  80,  80, 6, },//��3
		{  410,  112,  80,  80, 7, },//��4
		{  490,  112,  80,  80, 8, },//��5
		{  570,  112,  80,  80, 9, },//��6
		{  650,  142,  27,  27, 10, },//�����[2����(��)
		{  650,  169,  27,  23, 11, },//�����[2����(��)
		{  170,  258,  80,  80, 12, },//��1(��)
		{  250,  258,  80,  80, 13, },//��2
		{  330,  258,  80,  80, 14, },//��3
		{  410,  258,  80,  80, 15, },//��4
		{  490,  258,  80,  80, 16, },//��5
		{  570,  258,  80,  80, 17, },//��6
		{  650,  287,  27,  27, 18, },//�����[2����(��)
		{  650,  314,  27,  24, 19, },//�����[2����(��)
		{  170,  422,  60,  60, 20, },//��1(��)
		{  230,  422,  60,  60, 21, },//��2
		{  290,  422,  60,  60, 22, },//��3
		{  350,  422,  60,  60, 23, },//��4
		{  410,  422,  60,  60, 24, },//��5
		{  470,  422,  60,  60, 25, },//��6
		{  530,  422,  60,  60, 26, },//��7
		{  590,  422,  60,  60, 27, },//��8
		{  650,  433,  25,  27, 28, },//�����[2����(��)
		{  650,  460,  25,  22, 29, },//�����[2����(��)
		{    0,  587, 725, 800, 30, },//����
		{  790,   92, 600, 600, 31, },//�E�[��
	};

	for (int i = 0; i <35; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//�A�N�V����
void CObjComputerroom::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	////�G�̈ʒu
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();


	//��ɍs���ƘL��2-1�ɍs��
	if (hy > 500 == true && hy < 600 == true)
	{
		if (m_key_flag == true)
		{
			//��l��
			g_hero_x = hx;
			g_hero_y = 550;
			//�G
			//g_enemy_x = 110;

			//Scene::SetScene(new CSceneMain9());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}



}

//�h���[
void CObjComputerroom::Draw()
{
	/*
	//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 788.0f;
	src.m_bottom = 698.0f;

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