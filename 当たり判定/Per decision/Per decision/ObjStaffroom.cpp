#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjStaffroom.h"
#include "GameHead.h"


using namespace GameL;



//�C�j�V�����C�Y
void CObjStaffroom::Init()
{
	//�h�A1
	//Hits::SetHitBox(this, 0.0f, 0.0f, 60, 120, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//�I
	Hits::SetHitBox(this, 60.0f, 0.0f, 108, 120, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//�I
	Hits::SetHitBox(this, 168.0f, 0.0f, 110, 140, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//��
	Hits::SetHitBox(this, 278.0f, 0.0f, 160, 120, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//�I
	Hits::SetHitBox(this, 438.0f, 0.0f, 50, 140, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//��
	Hits::SetHitBox(this, 488.0f, 0.0f, 244, 120, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//�h�A2
	//Hits::SetHitBox(this, 732.0f, 0.0f, 68, 120, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//�������Ԗڂ̊�
	Hits::SetHitBox(this, 75.0f, 241.0f, 40, 150, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//�������Ԗڂ̏㑤�̊�
	Hits::SetHitBox(this, 175.0f, 205.0f, 160, 70, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//�������Ԗڂ̉����̊�
	Hits::SetHitBox(this, 175.0f, 383.0f, 160, 70, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//������O�Ԗڂ̏㑤�̊�
	Hits::SetHitBox(this, 440.0f, 205.0f, 245, 70, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//������O�Ԗڂ̉����̊�
	Hits::SetHitBox(this, 440.0f, 383.0f, 245, 70, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//���b�J�[
	Hits::SetHitBox(this, 745.0f, 362.0f, 55, 238, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

	//����@
	Hits::SetHitBox(this, 315.0f, 532.0f, 33, 55, ELEMENT_STAFFROOM, OBJ_STAFFROOM, 9);

}


//�A�N�V����
void CObjStaffroom::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hy + 64.0f < 120.0f && 0.0f < hx < 60.0f)
	{
		Scene::SetScene(new CSceneCorridor1_1());

		hx -= 300.0f;
	}

	if (hy + 64.0f < 120.0f && 732.0f < hx < 800.0f)
	{
		Scene::SetScene(new CSceneCorridor1_1());

		hx -= 300.0f;
	}

}

//���ϊ֐��@
//����1�C2 float ax, ay :A�x�N�g��
//����3�C4 float bx, by :B�x�N�g��
//�߂�l float :�ˉe
//���e A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�
float CObjStaffroom::Dot(float ax, float ay, float bx, float by)
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
float CObjStaffroom::Cross(float ax, float ay, float bx, float by)
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
bool CObjStaffroom::LineCrossPoint(
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
//���� 1,2 float x , y :��l���̈ʒu
//���� 3,4 float vx , vy :��l���̈ړ��x�N�g��
//���� 5,6 float * out_px, out_py :Block�Ƃ̌����_
//���� 7 float * out : �ʒu�����_�܂ł̋���
//��l���̈ʒu++�ړ��x�N�g���Ɗe�u���b�N�̕ӂŌ���������s��
//�ł��߂���_�̈ʒu�Ƌ�����Ԃ�
bool CObjStaffroom::HeroStaffroomCrossPoint(
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

//StaffroomHit�֐�
//����1 float  x  :������s��object��x�ʒu
//����2 float  y  :������s��object��y�ʒu
//����3 bool scroll_on ;������s��object�̓X�N���[���̉e���ɗ^����̂��ǂ����itrue=�^���� false=�^���Ȃ��j
//����4 bool * up :�㉺���E����̏㕔���ɓ������Ă���̂��ǂ�����Ԃ� 
//����5 bool * down :�㉺���E����̉������ɓ������Ă���̂��ǂ�����Ԃ�
//����6 bool * left :�㉺���E����̉E�����ɓ������Ă���̂��ǂ�����Ԃ�
//����7 bool * right :�㉺���E����̍������ɓ������Ă���̂��ǂ�����Ԃ�
//����8 float* vx �F���E���莞�̔����ɂ��ړ����@�E�͂̒l��ς��ĕԂ�
//����9 float* vy ;�㉺���莞�̎��R�����^���̈ړ����@�E�͂̒l��ς��ĕԂ�
//����10 int* bt :���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//���̌��ʂ͈����S�`�P�O�ɕԂ�
void CObjStaffroom::StaffroomHit
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
void CObjStaffroom::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//�w�i
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 896.0f;
	src.m_bottom = 640.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

}