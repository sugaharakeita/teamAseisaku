#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjCorridor1_3 :public CObj
{
public:
	CObjCorridor1_3() {};
	~CObjCorridor1_3() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[


	//�u���b�N�̓����蔻��
	void Corridor1_3Hit
	(
		float * x, float * y, bool scroll_on,
		bool * up, bool * down, bool * left, bool * right,
		float * vx, float * vy, int * bt
	);

	//��l���ƕǂ̌�������
	bool HeroCorridor1_3CrossPoint(
		float x, float y, float vx, float vy,
		float * out_px, float * out_py, float * out_len
	);


private:

	float Dot(float ax, float ay, float bx, float by); //����
	float Cross(float ax, float ay, float bx, float by); //�O��

	//���Ɛ��̌�������
	bool CObjCorridor1_3::LineCrossPoint(
		float a1x, float a1y, float a2x, float a2y,
		float b1x, float b1y, float b2x, float b2y,
		float * out_px, float * out_py
	);


};
