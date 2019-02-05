//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjHomeeconomicsroom.h"
#include "ObjHitBox.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//�C�j�V�����C�Y
void CObjHomeeconomicsroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//�ƒ�Ȏ������蔻��
	HitBoxs Hit[20] =
	{
		{ -58, 	0,	128,  128,  0, },//����
		{ 130,  -413,  541,  541,  1, },//�^�񒆕�
		{ 731,     0,  128,  128,  2, },//�E��
		{ 0,   584,  400,  400,  3, },//��
		{ 400,   584,  400,  400,  4, },//��
		{ -399,   146,  438,  438,  5, },//���I
		{ 170,   190,  110,  110,  6, },//��A���̊�1
		{ 200,   190,  110,  110,  7, },//��A���̊�2
		{ 363,   190,  130,  120,  8, },//��A�^�񒆂̊�
		{ 550,   190,  125,  120,  9, },//��A�E�̊�
		{ 167,   410,  128,  125, 10, },//���A���̊�
		{ 367,   410,  125,  125, 11, },//���A�^�񒆂̊�
		{ 545,   410,  120,  120, 12, },//���A�E�̊�
		{ 715,   295,   33,   35, 13, },
		{ 715,   330,   33,   35, 14, },
		{ 715,   365,   33,   35, 15, },
		{ 715,   400,   33,   35, 16, },//11�`15�܂ŋ���
		{ 790,   129,   70,   70 ,17, },


	};

	for (int i = 0; i <20; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}

	//����
	Hits::SetHitBox(this, 0.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);

	//�E��
	Hits::SetHitBox(this, 780.0f, 0.0f, 20, 200, ELEMENT_FIELD, OBJ_ROOM, 9);

	Hits::SetHitBox(this, 780.0f, 280.0f, 20, 400, ELEMENT_FIELD, OBJ_ROOM, 9);

}

//�A�N�V����
void CObjHomeeconomicsroom::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�L��2-1�ɍs��(�����̃h�A)
	if (hy < 100 && hx < 100)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 50;
		g_hero_y = 500;
		return;
	}

	//�L��2-1�ɍs��(�E���̃h�A)
	if (hy < 100 && hx > 200)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 500;
		g_hero_y = 500;
		return;
	}

	//�E�ɍs���Ɠ�K�E�ƒ돀����
	if (hx +64.0f > 800.0f)
	{
		Scene::SetScene(new CSceneHomepreparationroom);
		g_hero_x = 10;
		g_hero_y = 200;
		return;
	}

}

//�h���[
void CObjHomeeconomicsroom::Draw()
{
	
	//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 852.0f;
	src.m_bottom = 506.0f;

	//�w�i�P�̈ʒu�̐ݒ�����`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);



}