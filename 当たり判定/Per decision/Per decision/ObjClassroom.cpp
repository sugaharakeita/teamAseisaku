//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjClassroom.h"
#include "ObjHitBox.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//�C�j�V�����C�Y
void CObjClassroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//���������蔻��
	HitBoxs Hit[26] =
	{
		{ -208,     0,   220,  220,  0, },//��A����
		{ 90,  -477,   620,  620,  1, },//��A�^�񒆂̕�
		{ 788,     0,   479,  479,  2, },//�E��
		{ -167,   220,   190,  190,  3, },//����
		{ -208,   410,   220,  220,  4, },//���A����
		{ 749,   479,   121,  121,  5, },//�E���A�I
		{ 12,   578,   737,  737,  6, },//����
		{ 82,   305,    39,   39,  7, },//����
		{ 162,   198,    48,   48,  8, },//����E����1
		{ 260,   198,    48,   48,  9, },//����E����2
		{ 360,   198,    48,   48, 10, },//����E����3
		{ 460,   198,    48,   48, 11, },//����E����4
		{ 552,   198,    48,   48, 12, },//����E����5
		{ 642,   196,    48,   48, 13, },//����E����6
		{ 163,   314,    48,   48, 14, },//���^�񒆉E����1
		{ 260,   314,    48,   48, 15, },//���^�񒆉E����2
		{ 361,   314,    48,   48, 16, },//���^�񒆉E����3
		{ 460,   314,    48,   48, 17, },//���^�񒆉E����4
		{ 552,   314,    48,   48, 18, },//���^�񒆉E����5
		{ 646,   311,    48,   48, 19, },//���^�񒆉E����6
		{ 164,   431,    48,   48, 20, },//�����E����1
		{ 261,   431,    48,   48, 21, },//�����E����2
		{ 362,   431,    48,   48, 22, },//�����E����3
		{ 460,   428,    48,   48, 23, },//�����E����4
		{ 554,   428,    48,   48, 24, },//�����E����5
		{ 650,   426,    48,   48, 25, },//�����E����6

	};

	for (int i = 0; i <26; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}

	//����
	Hits::SetHitBox(this, 0.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);

	//�E��
	Hits::SetHitBox(this, 780.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);


}

//�A�N�V����
void CObjClassroom::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//���̃h�A�ɍs���ƘL��2-3�ɏo��
	if (hy < 100 && hx < 50)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 50;
		g_hero_y = 440;
	}

	//�E�̃h�A�ɍs���ƘL��2-3�ɏo��
	if (hy < 100 && hx > 650)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 600;
		g_hero_y = 400;
	}
}

//�h���[
void CObjClassroom::Draw()
{
	
	//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 660.0f;
	src.m_bottom = 442.0f;

	//�w�i�P�̈ʒu�̐ݒ�����`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	
}