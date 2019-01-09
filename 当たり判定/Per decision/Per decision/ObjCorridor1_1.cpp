#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "ObjCorridor1_1.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjCorridor1_1::Init()
{

	//���
	Hits::SetHitBox(this, 0.0f, 70.0f, 410, 110, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//���
	Hits::SetHitBox(this, 510.0f, 70.0f, 290, 110, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//����
	Hits::SetHitBox(this, 0.0f, 500.0f,115, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//����
	Hits::SetHitBox(this, 215.0f, 500.0f, 445, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//����
	Hits::SetHitBox(this, 755.0f, 500.0f, 40, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);


	//�G���A�ړ��t���O������
	//m_flag_Corridor1_1 = false;
}

//�A�N�V����
void CObjCorridor1_1::Action()
{

	/*
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (m_flag_Corridor1_1 == true)
	{
		//Corridor1_1�I�u�W�F�N�g����
		CObjCorridor1_1* objb = new CObjCorridor1_1();
		Objs::InsertObj(objb, OBJ_CORRIDOR1_1, 9);

		Draw::LoadImage(L"�L��1-1.png", 9, TEX_SIZE_512);
	}

	//�L��1-1��ʒ[�E�ɍs���ƘL��1-2�ֈړ�
	if (hx + 64.0f > 800.0f && m_flag_Corridor1_1 == true)
	{
		//Corridor1_2�I�u�W�F�N�g����
		CObjCorridor1_2* objb = new CObjCorridor1_2();
		Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

		Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);

		m_flag_Corridor1_1 = false;
	}
	*/

	/*
	//�L��1-1��ʒ[���ɍs���ƐE�����Ɉړ�
	if ((hy + 64.0f > 600.0f && 56.0f < hx < 106.0f) ||
	(hy + 64.0f > 600.0f && 645.0f < hx < 695.0f))
	{
		Scene::SetScene(new CSceneStaffroom());
	}

	//�L��1-1��ʒ[��ɍs���ƍZ�����Ɉړ�
	if (hy < 110.0f && 352.0f < hx < 406.0f)
	{
		Scene::SetScene(new CScenePrincipaloffice());
	}
	*/

}

//�h���[
void CObjCorridor1_1::Draw()
{
	/*
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//�w�i
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1038.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	*/

}