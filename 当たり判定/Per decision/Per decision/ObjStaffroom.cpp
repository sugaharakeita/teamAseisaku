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
	//�I
	Hits::SetHitBox(this, 65.0f, 0.0f, 103, 120, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//�I
	Hits::SetHitBox(this, 168.0f, 0.0f, 110, 140, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//��
	Hits::SetHitBox(this, 278.0f, 0.0f, 160, 120, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//�I
	Hits::SetHitBox(this, 438.0f, 0.0f, 50, 140, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//��
	Hits::SetHitBox(this, 488.0f, 0.0f, 244, 120, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//�������Ԗڂ̊�
	Hits::SetHitBox(this, 75.0f, 241.0f, 40, 150, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//�������Ԗڂ̏㑤�̊�
	Hits::SetHitBox(this, 175.0f, 205.0f, 160, 70, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//�������Ԗڂ̉����̊�
	Hits::SetHitBox(this, 175.0f, 383.0f, 160, 70, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//������O�Ԗڂ̏㑤�̊�
	Hits::SetHitBox(this, 440.0f, 205.0f, 245, 70, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//������O�Ԗڂ̉����̊�
	Hits::SetHitBox(this, 440.0f, 383.0f, 245, 70, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//���b�J�[
	Hits::SetHitBox(this, 745.0f, 362.0f, 55, 238, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

	//����@
	Hits::SetHitBox(this, 315.0f, 532.0f, 33, 55, ELEMENT_FIELD, OBJ_STAFFROOM, 9);

}


//�A�N�V����
void CObjStaffroom::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hy < 60.0f && (hx < 70.0f || hx + 64.0f > 750.0f))
	{
		Hits::DeleteHitBox(this);
	}

}

//�h���[
void CObjStaffroom::Draw()
{
	/*
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
	*/

}