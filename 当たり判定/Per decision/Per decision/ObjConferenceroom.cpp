//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjConferenceroom.h"
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
void CObjConferenceroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//�ƒ�Ȏ������蔻��
	HitBoxs Hit[17] =
	{
		{ -41,     0,  114,  114, 0, },//����
		{ 171,  -344,  458,  458, 1, },//�^�񒆕�
		{ 726,     0,  114,  114, 2, },//�E��
		{   0,   190,   57,   57, 3, },//�I1(��)
		{   0,   247,   57,   57, 4, },//�I2
		{   0,   304,   57,   57, 5, },//�I3
		{   0,   361,   57,   57, 6, },//�I4
		{  741,  194,   59,   59, 7, },//�I1(�E) 
		{  741,  253,   59,   59, 8, },//�I2
		{  741,  312,   59,   59, 9, },//�I3
		{  741,  371,   59,   59, 10, },//�I4
		{  120,  220,  260,  240, 11, },//�������Ƃ���(��)
		{  380,  220,  260,  240, 12, },//�������Ƃ���(�E)
		{  225,  505,  327,  327, 13, },//�z���C�g�{�[�h
		//{ 715,   366,   33,   33, 14, },
		//{ 715,   399,   33,   33, 15, },
		//{ 715,   432,   33,   33, 16, },//11�`16�܂ŋ���


	};

	for (int i = 0; i <17; i++)
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
void CObjConferenceroom::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//���ɍs���ƘL��3-1�ɍs��
	if (hy + 64.0f > 600.0f && hx < 500 )
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 400;
		g_hero_y = 100;
		return;
	}

}

//�h���[
void CObjConferenceroom::Draw()
{
	
	//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 788.0f;
	src.m_bottom = 730.0f;

	//�w�i�P�̈ʒu�̐ݒ�����`��
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f + m_x1;
	dst.m_right  = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	
}