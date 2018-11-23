//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock()
{
	//�}�b�v�f�[�^���R�s�[
	/*memcpy(m_map, map, sizeof(int)*(6 * 11));*/
}
//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;

};




//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	if (hx < 0)
	{
		hero->SetX(0);            //��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX(); //��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�O���X�N���[�����C��
	if (hx > 750)
	{
		hero->SetX(750);		   //��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX(); //��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}


	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = i*64.0f;
				float y = i*64.0f;

				//��l���ƃu���b�N�̓����蔻��
				if ((hx + (-m_scroll) + 64.0f>x) && (hx + (-m_scroll)<x + 64.0f) && (hy + 64.0f>y) && (hy<y + 64.0f))
				{
					//�㉺���E����
					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
					float vy = hy - y;

					//���������߂�
					float len = sqrt(vx*vx + vy*vy);

					//�p�x�����߂�
					float r = atan2(vy, vx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							hero->SetRight(true);   //��l���̍��̕������Փ˂��Ă���
							hero->SetX(x + 64.0f);  //�u���b�N�̈ʒu+��l���̕�
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*�����W��

						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);   //��l���̉��̕������Փ˂��Ă���
							hero->SetY(y - 64.0f); //�u���b�N�̈ʒu-��l���̕�
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);     //��l���̉E�̕������Փ˂��Ă���
							hero->SetX(x - 64.0f);   //�u���b�N�̈ʒu�|��l���̕�
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);
							hero->SetY(y + 64.0f);
							hero->SetVY(0.0f);
						}
					}


				}

			}
		}

	}
}

//�h���[
void CObjBlock::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //�`�挳�؂���ʒu
	RECT_F dst;  //�`���\���ʒu


				 //�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <11; j++)
		{

			if (m_map[i][j] == 5)//�ی����@���\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 192.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 6)//�ی����@�搶���\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 256.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 128.0;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 7)//�ی����@�֎q�\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 384.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 32.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 8)//�ی����@�J�[�e���\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 9)//�ی����@�x�b�h�\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 10)//�ی����@���\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 196.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 11)//�ی����@�\�t�@�\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 12)//�ی����@�̏d�v�\��
			{

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 48.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 13)//�ی����@�g���v�\��
			{

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 352.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 48.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
		}
	}

}
