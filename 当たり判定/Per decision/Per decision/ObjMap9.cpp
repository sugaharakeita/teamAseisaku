//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjMap9.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;


//�C�j�V�����C�Y
void CObjMap9::Init()
{
	m_x1 = 0.0f;


	//�L��2-3�����蔻��
	HitBoxs Hit[3] =
	{
		{ 0, -625,  800, 800, 0, },//��̕�
		{ 778,  175,  465, 465, 1, },//��ԉE�[
		{ 143,  495,  494, 494, 2, },//�ƒ�Ȏ���(��둤)�E���̕�
									 //{ 563, 495, 127, 127, 4, },//�ƒ�Ȏ���(�O��)�E���̕�

	};

	for (int i = 0; i < 5; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}
}

//�A�N�V����
void CObjMap9::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//0�`100�ɂ����ƘL��2-2�ɂ���
	if (hx < 50 == true)
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

	//���ɍs���Ɠ�K�E�����ɍs��
	if (hy > 450 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 650;
			g_hero_y = hy;
			Scene::SetScene(new CSceneClassroom());
			m_key_flag = false;
		}
	}



}

//�h���[
void CObjMap9::Draw()
{
	//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu


				//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 360.0f;
	src.m_bottom = 362.0f;

	//�w�i�P�̈ʒu�̐ݒ�����`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);




}