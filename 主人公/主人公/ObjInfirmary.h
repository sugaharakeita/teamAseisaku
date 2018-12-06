#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjInfirmary :public CObj
{
public:
	CObjInfirmary() {};
	~CObjInfirmary() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[


	//�u���b�N�̓����蔻��
	void InfirmaryHit
	(
		float * x, float * y, bool scroll_on,
		bool * up, bool * down, bool * left, bool * right,
		float * vx, float * vy, int * bt
	);

	//��l���ƕǂ̌�������
	bool HeroInfirmaryCrossPoint(
		float x, float y, float vx, float vy,
		float * out_px, float * out_py, float * out_len
	);


private:

	float Dot(float ax, float ay, float bx, float by); //����
	float Cross(float ax, float ay, float bx, float by); //�O��

														 //���Ɛ��̌�������
	bool CObjInfirmary::LineCrossPoint(
		float a1x, float a1y, float a2x, float a2y,
		float b1x, float b1y, float b2x, float b2y,
		float * out_px, float * out_py
	);


};
