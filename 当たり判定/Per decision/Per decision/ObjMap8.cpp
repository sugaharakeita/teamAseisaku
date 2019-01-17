//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMap8.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;


//�C�j�V�����C�Y
void CObjMap8::Init()
{
	m_x1 = 0.0f;

	//�L��2-2�����蔻��
	HitBoxs Hit[3] =
	{
		{ -42,    0,  175,  175, 0, },//�h�A���獶���̕�
		{ 335, -290,  465,  465, 1, },//�h�A����E���̕�
		{ 0,  494,  800,  800, 2, },//�ƒ�Ȏ���(��둤)�E���̕�

	};

	for (int i = 0; i < 5; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}

}

//�A�N�V����
void CObjMap8::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();



	//700�`800�ɂ����ƘL��3-3�ɂ���
	if (hx >700 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 110;
			g_hero_y = hy;
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//0�`100�ɂ����ƘL��3-1�ɂ���
	if (hx < 100 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 690;
			g_hero_y = hy;
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}




}

//�h���[
void CObjMap8::Draw()
{
	/*
	//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 384.0f;
	src.m_bottom = 362.0f;

	//�w�i�P�̈ʒu�̐ݒ�����`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	*/


}