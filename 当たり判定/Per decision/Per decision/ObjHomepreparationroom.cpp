//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjHomepreparationroom.h"
#include "ObjHitBox.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//�C�j�V�����C�Y
void CObjHomepreparationroom::Init()
{
	m_x1 = 0.0f;

	m_scroll = 0.0f;

	//�ƒ돀���������蔻��
	HitBoxs Hit[11] =
	{
		{ 0,   -22,  148,  148, 0, },//��A����
		{ 273,  -401,  527,  527, 1, },//��A�E��
		{ 723,   126,   66,   66, 2, },//������
		{ -56,   126,   75,   75, 3, },//���ǁA�㑤
		{ -305,   277,  323,  323, 4, },//���ǁA����
		{ 18,   493,  620,  620, 5, },//���I
		{ 718,   238,  438,  438, 6, },//�E�I
		{ 221,   280,  120,  116, 7, },
		{ 341,   280,  120,  116, 8, },
		{ 461,   280,  116,  116, 9, },//7�`9�����̊�
		{ 638,   581,   80,   80,10, },
	};

	for (int i = 0; i <11; i++)
	{
		CObjHitBox*obja = new CObjHitBox(Hit[i]);
		Objs::InsertObj(obja, OBJ_HITBOX, 10);
	}

	//����
	Hits::SetHitBox(this, 0.0f, 0.0f, 20, 180, ELEMENT_FIELD, OBJ_ROOM, 9);

	Hits::SetHitBox(this, 0.0f, 280.0f, 20, 320, ELEMENT_FIELD, OBJ_ROOM, 9);

	//�E��
	Hits::SetHitBox(this, 780.0f, 0.0f, 20, 600, ELEMENT_FIELD, OBJ_ROOM, 9);


}

//�A�N�V����
void CObjHomepreparationroom::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//��ɍs���ƘL��2-1�ɍs��
	if (hy < 70 && hx < 800)
	{
		Scene::SetScene(new CSceneCorridor());
		g_hero_x = 700;
		g_hero_y = 520;
		return;
	}

	//���ɍs���Ɠ�K�E�ƒ�Ȏ��ɍs��
	if (hx < 0)
	{
		Scene::SetScene(new CSceneHomeeconomicsroom());
		g_hero_x = 730;
		g_hero_y = 200;
		return;
	}

}

//�h���[
void CObjHomepreparationroom::Draw()
{
	
	//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 404.0f;
	src.m_bottom = 506.0f;

	//�w�i�P�̈ʒu�̐ݒ�����`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

	



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