#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�����蔻��
class CObjHitBox : public CObj
{
	public:
		CObjHitBox(HitBoxs h);
		~CObjHitBox() {};
		void Init() {};
		void Action() {};	//�A�N�V����
		void Draw() {};	//�h���[

//		HitBoxs Get_HitstateSR(int Hitid);	//�E���������蔻��
//		HitBoxs StaffroomHitBox[8];			//�E���������蔻��
	private:
};