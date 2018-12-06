#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjPrincipaloffice.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjPrincipaloffice::Init()
{
	//���
	Hits::SetHitBox(this, 0.0f, 0.0f, 800, 110, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//�ϗt�A��1
	Hits::SetHitBox(this, 0.0f, 110.0f, 80, 30, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//�ϗt�A��2
	Hits::SetHitBox(this, 720.0f, 110.0f, 80, 30, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//�֎q1
	Hits::SetHitBox(this, 350.0f, 170.0f, 65, 50, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//�I1
	Hits::SetHitBox(this, 0.0f, 175.0f, 100, 160, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//��1
	Hits::SetHitBox(this, 300.0f, 230.0f, 165, 60, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//�I2
	Hits::SetHitBox(this, 700.0f, 290.0f, 100, 160, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//�֎q2
	Hits::SetHitBox(this, 155.0f, 350.0f, 88, 90, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//��2
	Hits::SetHitBox(this, 348.0f, 355.0f, 86, 85, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//�֎q3
	Hits::SetHitBox(this, 535.0f, 350.0f, 90, 90, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//�I3
	Hits::SetHitBox(this, 0.0f, 430.0f, 100, 155, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//�~��
	Hits::SetHitBox(this, 203.0f, 460.0f, 422, 75, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//����
	Hits::SetHitBox(this, 0.0f, 586.0f, 580, 20, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//���h�A
	//Hits::SetHitBox(this, 580.0f, 593.0f, 110, 1, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

	//����
	Hits::SetHitBox(this, 690.0f, 586.0f, 110, 20, ELEMENT_PRINCIPALOFFICE, OBJ_PRINCIPALOFFICE, 9);

}

//�A�N�V����
void CObjPrincipaloffice::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hy +64.0f > 600.0f && 580.0f < hx < 690.0f)
	{
		Scene::SetScene(new CSceneCorridor1_1());
	}

}

//���ϊ֐��@
//����1�C2 float ax, ay :A�x�N�g��
//����3�C4 float bx, by :B�x�N�g��
//�߂�l float :�ˉe
//���e A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�
float CObjPrincipaloffice::Dot(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * bx + ay * by;

	return t;
}

//�O�ϊ֐�
//����1�C2 float ax, ay :A�x�N�g��
//����3�C4 float bx, by :B�x�N�g��
//�߂�l float :�ˉe
//���e A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�
float CObjPrincipaloffice::Cross(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * bx - ay * by;

	return t;
}

//���������߂�}�N��
#define SGN(x) 1 - ( x <= 0 ) - ( x < 0 )

//���Ɛ��̌������� 
//���� float 1, 2 a1x , a1y :���x�N�g��A�̎n�_
//���� float 3, 4 a2x , a2y :���x�N�g��A�̏I�_
//���� float 5, 6 b1x , b1y :�x�N�g��B�̎n�_
//���� float 7, 8 b2x , b2y :�x�N�g��B�̏I�_
//���� float 9, 10 out_px , out_py :��������x�N�g���̌�_�ʒu
//�߂�l bool :true=��_�L��  false=��_����
//���e : ������A�EB�x�N�g���̌�_�������Aout_px��out_py�ɕԂ�
bool CObjPrincipaloffice::LineCrossPoint(
	float a1x, float a1y, float a2x, float a2y,
	float b1x, float b1y, float b2x, float b2y,
	float * out_px, float * out_py
)
{
	//�G���[�R�[�h
	*out_px = -99999.0f; *out_py = -99999.0f;

	//A�x�N�g���쐬(a2��a1)
	float ax = a2x - a1x;	float ay = a2y - a1y;

	//B�x�N�g���쐬(b2��b1)
	float bx = b2x - b1x;	float by = b2y - b1y;

	//C�x�N�g���쐬(b1��a1)
	float cx = b1x - a1x;	float cy = b1y - a1y;

	//D�x�N�g���쐬(b2��a1)
	float dx = b2x - a1x;	float dy = b2y - a1y;

	//A�~C�̎ˉe��A�~B�̎ˉe�����߂�
	float t1 = Cross(ax, ay, cx, cy);
	float t2 = Cross(ax, ay, dx, dy);

	//���������������ɂȂ��Ă��邩�ǂ������`�F�b�N
	if (SGN(t1) == SGN(t2))
		return false; //��_����

					  //�ˉe���Βl��
	t1 = abs(t1); t2 = abs(t2);

	//��_�����߂�
	float px = bx * (t1 / (t1 + t2)) + b1x;
	float py = by * (t1 / (t1 + t2)) + b1y;

	//AP�x�N�g��(p��a1)
	float apx = px - a1x; float apy = py - a1y;

	//BP�x�N�g��(p��a2)
	float bpx = px - a2x; float bpy = py - a2y;

	//A�EAP�̎ˉe��A�EBP�̎ˉe�����߂�
	float w1 = Dot(ax, ay, apx, apy);
	float w2 = Dot(ax, ay, bpx, bpy);

	//�����`�F�b�N
	if (SGN(w1) == SGN(w2))
		return false; //��_���O

					  //��_��Ԃ�
	*out_px = px; *out_py = py;

	return true;

}


//��l���ƕǂ̌�������֐�
bool CObjPrincipaloffice::HeroPrincipalofficeCrossPoint(
	float x, float y, float vx, float vy,
	float * out_px, float * out_py, float * out_len
)
{
	bool pb = false; //��_�m�F�p
	float len = 99999.0f; //��_�Ƃ̋���

						  //�u���b�N�̕Ӄx�N�g���@
	float edge[4][4] =
	{
		{ 0, 0, 64, 0 }, //��
		{ 64, 0, 64, 64 }, //��
		{ 64, 64, 0, 64 },//��
		{ 0, 64, 0, 0 }, //��
	};

	//m_map�̑S�v�f�̃A�N�Z�X	
	//�u���b�N��4�ӂ���̌�_��T��
	for (int k = 0; k < 4; k++)
	{
		float px, py;
		bool b;
		float l = 0.0f;
		b = LineCrossPoint(x, y, x + vx, y + vy,
			64 + edge[k][0], 64 + edge[k][1], 64 + edge[k][2], 64 + edge[k][3],
			&px, &py);

		//��_�`�F�b�N
		if (b == true)
		{
			//��_�Ƃ̋��������߂�
			l = sqrt((px - x) * (px - x) + (py - y) * (py - y));

			//��������_�̒��ōł��߂��������Z�����m��T��
			if (len > l)
			{
				len = l;
				*out_px = px;
				*out_py = py;
				pb = true;
			}
		}

	}

	*out_len = len;
	return pb;
}


//Corridor1_1Hit�֐�
void CObjPrincipaloffice::PrincipalofficeHit
(
	float * x, float * y, bool scroll_on,
	bool * up, bool * down, bool * left, bool * right,
	float * vx, float * vy, int * bt
)
{
	//�Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//�v�f�ԍ������W�ɕύX
	float bx = 64.0f;
	float by = 64.0f;


	//��l���ƃu���b�N�̓����蔻��
	if ((*x + 64.0f > bx) && (*x < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
	{

		//vector�̍쐬
		float rvx = *x - bx;
		float rvy = *y - by;

		//���������߂�
		float len = sqrt(rvx*rvx + rvy*rvy);

		//�p�x�����߂�
		float r = atan2(rvy, rvx);
		r = r*180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

	}

}


//�h���[
void CObjPrincipaloffice::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//�w�i
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 470.0f;
	src.m_bottom = 730.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

}