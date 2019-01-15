//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjLibrary.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;
//
//extern float g_enemy_x = 150.0f;
//extern float g_enemy_y = 0.0f;
//


//�C�j�V�����C�Y
void CObjLibrary::Init()
{
	m_x1 = 0.0f;

	//���������蔻��
	HitBoxs Hit[31] =
	{
		{   0, 	 -674,   800,  800, 0, },//��A��
		{ 765,    126,   474,  474, 1, },//�E�̖{�I
		{-590,    126,   600,  600, 2, },//���̕�
		{  71,    129,    29,   29, 3, },//���̃J�E���^�[1(�ォ��)
		{  71,    158,    29,   29, 4, },//���̃J�E���^�[2
		{  71,    187,    29,   29, 5, },//���̃J�E���^�[3
		{  71,    216,    29,   29, 6, },//���̃J�E���^�[4
		{  71,    245,    29,   29, 7, },//���̃J�E���^�[5
		{  71,    274,    29,   29, 8, },//���̃J�E���^�[6
		{ 253,    151,    65,   65, 9, },//����̖{�I1(�ォ��)
		{ 253,    216,    65,   65, 10, },//����̖{�I2
		{ 371,    171,    90,   90, 11, },//�����̊�
		{ 521,    171,    90,   90, 12, },//�E���̊�
		{ 371,    350,    45,   45, 13, },//�����̊��̉��̖{�I(����)
		{ 416,    350,    45,   45, 14, },//�E���̊��̉��̖{�I(�E��)
		{ 521,    350,    45,   45, 15, },//�E���̊��̉��̖{�I(����)
		{ 566,    350,    45,   45, 16, },//�E���̊��̉��̖{�I(�E��)
		{ 222,    434,    26,   26, 17, },//�����̖{�I1(�ォ��)
		{ 222,    460,    26,   26, 18, },//�����̖{�I2(�ォ��)
		{ 222,    486,    26,   26, 19, },//�����̖{�I3(�ォ��)
		{ 222,    512,    26,   26, 20, },//�����̖{�I4(�ォ��)
		{ 222,    538,    26,   26, 21, },//�����̖{�I5(�ォ��)
		{ 222,    564,    26,   18, 22, },//�����̖{�I6(�ォ��)
		{ 270,    507,    76,   76, 23, },//���̖{�I(�w�������Ă���)1(������)
		{ 346,    507,    76,   76, 24, },//���̖{�I2
		{ 422,    507,    76,   76, 25, },//���̖{�I3
		{ 498,    507,    76,   76, 26, },//���̖{�I4
		{ 574,    507,    76,   76, 27, },//���̖{�I5
		{ 650,    507,    70,   76, 28, },//���̖{�I6
		{  10,    583,   121,  121, 29, },//�����̕�(�������猩�č���)
		{ 190,    583,   575,  625, 30, },//�E���̕�(�������猩�ĉE��)
		

	};

	for (int i = 0; i <31; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}


}

//�A�N�V����
void CObjLibrary::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	////�G�̈ʒu
	//CObjEnemy*obje = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();


	//��ɍs���ƘL��2-1�ɏo��
	if (hy > 450 == true)
	{
		if (m_key_flag == true)
		{
			//��l��
			g_hero_x = hx;
			g_hero_y = 450;
			//�G
			//g_enemy_x = 110;

			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	


}

//�h���[
void CObjLibrary::Draw()
{
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