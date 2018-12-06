#pragma once
//�g�p����w�b�^�[�t�@�C��
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjStaffroom :public CObj
{
public:
	CObjStaffroom() {};
	~CObjStaffroom() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[

	//�u���b�N�̓����蔻��
	void StaffroomHit
	(
		float * x, float * y, bool scroll_on,
		bool * up, bool * down, bool * left, bool * right,
		float * vx, float * vy, int * bt
	);

	//��l���ƕǂ̌�������
	bool HeroStaffroomCrossPoint(
		float x, float y, float vx, float vy,
		float * out_px, float * out_py, float * out_len
	);

private:

	float Dot(float ax, float ay, float bx, float by); //����
	float Cross(float ax, float ay, float bx, float by); //�O��

	//���Ɛ��̌�������
	bool CObjStaffroom::LineCrossPoint(
		float a1x, float a1y, float a2x, float a2y,
		float b1x, float b1y, float b2x, float b2y,
		float * out_px, float * out_py
	);


};