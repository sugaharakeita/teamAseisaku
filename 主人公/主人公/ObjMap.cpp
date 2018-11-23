//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjMap.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMap::Init()
{
	m_x1 = 0.0f;
	m_flag = 0;

}

//�A�N�V����
void CObjMap::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�G�̈ʒu���擾
	//CObjEnemy* enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//float ex = enemy->GetX();
	//float ey = enemy->GetY();

	//��l�����E�[700�`800�ɗ���ƃ}�b�v�ړ�
	if (700 < hx && m_flag == 0)
	{
		m_flag = 1;
	}
	//else if (hx < 100 && m_flag == 0)
	//{
	//	m_flag = 3;
	//}


		//�}�b�v�ړ�
		if (m_flag == 1)
		{
			m_x1 -= 5.0f;
			hero->SetX(hx - 5.0);
			//enemy->SetX(ex - 5.0);
			if (m_x1 < -700)
			{
				m_flag = 2;
			}
		}
		/*else if(m_flag == 3)
		{
			m_x1 += 5.0f;
			hero->SetX(hx + 5.0);
			if (m_x1 < 700)
			{
				m_flag = 2;
			}
		}*/
		else
		{
			;
		}

	



	

	

	
}

//�h���[
void CObjMap::Draw()
{
	//�`��J���[��� R G B al(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1779.0f;
	src.m_bottom = 362.0f;

	//�w�i�P�̈ʒu�̐ݒ�����`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 2948.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);




}