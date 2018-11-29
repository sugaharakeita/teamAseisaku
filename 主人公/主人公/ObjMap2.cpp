//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMap2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;


//�C�j�V�����C�Y
void CObjMap2::Init()
{
	m_x1 = 0.0f;
	

}

//�A�N�V����
void CObjMap2::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();



	//700�`800�ɂ����ƘL��1-3�ɂ���
	if (hx >700 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 110;
			g_hero_y = hy;
			Scene::SetScene(new CSceneMain3());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//0�`100�ɂ����ƘL��1-1�ɂ���
	if (hx < 100 == true)
	{
		if (m_key_flag == true)
		{
			g_hero_x = 690;
			g_hero_y = hy;
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}




}

//�h���[
void CObjMap2::Draw()
{
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




}