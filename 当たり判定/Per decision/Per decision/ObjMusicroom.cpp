//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMusicroom.h"
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
void CObjMusicroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//�ƒ�Ȏ������蔻��
	HitBoxs Hit[17] =
	{
		{   0,-685,	800,  800, 0, },//���
		{ 153, 175,  65,   65, 1, },//��1(���ォ��)
		{ 261, 175,  65,   65, 2, },//��2
		{ 375, 175,  65,   65, 3, },//��3
		{ 152, 355,  65,   65, 4, },//��4(��������)
		{ 261, 355,  65,   65, 5, },//��5
		{ 377, 356,  65,   65, 6, },//��6
		{ 580, 167, 135,  110, 7, },//�O�����h�s�A�m
		{ 599, 314,  66,  66, 8, },//����(��)
		{ 599, 380,  66,  56, 9, },//����(��)
		{ 133, 545,  150,  150, 10, },//�y����
		{ 335, 515,  55,  70, 11, },//�R���g���o�X
		{ 625, 520, 153,  153, 12, },//����
		//{ 715,   333,   33,   33, 13, },
		//{ 715,   366,   33,   33, 14, },
		//{ 715,   399,   33,   33, 15, },
		//{ 715,   432,   33,   33, 16, },//11�`16�܂ŋ���


	};

	for (int i = 0; i <17; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//�A�N�V����
void CObjMusicroom::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//���ɍs���ƘL��3-1�ɍs��
	if (hy + 64.0f > 600.0f && hx > 480 && hx < 600)
	{
		//Scene::SetScene(new CSceneMain7());
		g_hero_x = 650;
		g_hero_y = 125;
		return;
	}


}

//�h���[
void CObjMusicroom::Draw()
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
	src.m_bottom = 722.0f;

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