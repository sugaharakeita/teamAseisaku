#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "ObjCorridor1.h"
#include "GameHead.h"

using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;


//�C�j�V�����C�Y
void CObjCorridor1::Init()
{
	//�G���A�ړ��t���O������
	m_flag_Corridor1_1 = false;

	m_flag_Corridor1_2 = false;

	//�A���`��h�~������
	f_co = 0;

	/*
	//���
	Hits::SetHitBox(this, 0.0f, 70.0f, 410, 110, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//���
	Hits::SetHitBox(this, 510.0f, 70.0f, 290, 110, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//����
	Hits::SetHitBox(this, 0.0f, 500.0f, 115, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//����
	Hits::SetHitBox(this, 215.0f, 500.0f, 445, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//����
	Hits::SetHitBox(this, 755.0f, 500.0f, 40, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);
	

	
	//���
	Hits::SetHitBox(this, 0.0f, 0.0f, 140, 180, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//���
	Hits::SetHitBox(this, 140.0f, 0.0f, 1, 180, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//�K�i
	//Hits::SetHitBox(this, 130.0f, 0.0f, 200, 1, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//���
	Hits::SetHitBox(this, 331.0f, 0.0f, 1, 180, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//�_���{�[��
	Hits::SetHitBox(this, 333.0f, 0.0f, 204, 150, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//���
	Hits::SetHitBox(this, 537.0f, 0.0f, 280, 180, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//����
	Hits::SetHitBox(this, 0.0f, 500.0f, 200, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//�o�����1
	Hits::SetHitBox(this, 200.0f, 600.0f, 155, 1, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//����
	Hits::SetHitBox(this, 355.0f, 500.0f, 130, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//�o�����2
	Hits::SetHitBox(this, 485.0f, 600.0f, 125, 1, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);

	//����
	Hits::SetHitBox(this, 610.0f, 500.0f, 200, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_2, 9);
	*/
}

//�A�N�V����
void CObjCorridor1::Action()
{
	//Corridor1_1�I�u�W�F�N�g����
	CObjCorridor1_1* objb1_1 = new CObjCorridor1_1();
	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();

	

	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�\��
	if (m_flag_Corridor1_1 == false)
	{
		Hits::DeleteHitBox(this);
		f_co = 0;
	}

	if (m_flag_Corridor1_2 == false)
	{
		Hits::DeleteHitBox(this);
		f_co = 0;
	}

	if (m_flag_Corridor1_1 == true && f_co == 0)
	{
		Objs::InsertObj(objb1_1, OBJ_ROOM, 9);
		f_co = 1;
	}

	if (m_flag_Corridor1_2 == true && f_co == 0)
	{
		Objs::InsertObj(objb1_2, OBJ_ROOM, 9);
		f_co = 1;
	}


	//�ړ�����
	if (hx >= 750.0f && m_flag_Corridor1_1 == false)
	{
		m_flag_Corridor1_1 = false;
		m_flag_Corridor1_2 = true;

	}

	if (hx <= 100.0f && m_flag_Corridor1_2 == false)
	{
		m_flag_Corridor1_1 = true;
		m_flag_Corridor1_2 = false;
	}


}

//�h���[
void CObjCorridor1::Draw()
{

}