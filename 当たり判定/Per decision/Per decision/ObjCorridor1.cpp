#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "ObjCorridor1.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjCorridor1::Init()
{

	//�G���A�ړ��t���O������
	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;

}

//�A�N�V����
void CObjCorridor1::Action()
{
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

		m_flag_Corridor1_2 = false;
		m_flag_Corridor1_3 = false;
	}

	if (m_flag_Corridor1_2 == true)
	{
		//Corridor1_2�I�u�W�F�N�g����
		CObjCorridor1_2* objb = new CObjCorridor1_2();
		Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

		Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);

		m_flag_Corridor1_1 = false;
		m_flag_Corridor1_3 = false;
	}

	if (m_flag_Corridor1_3 == true)
	{
		//Corridor1_3�I�u�W�F�N�g����
		CObjCorridor1_3* objb = new CObjCorridor1_3();
		Objs::InsertObj(objb, OBJ_CORRIDOR1_3, 9);

		Draw::LoadImage(L"�L��1-3.png", 9, TEX_SIZE_512);

		m_flag_Corridor1_1 = false;
		m_flag_Corridor1_2 = false;
	}

	/*
	//�L��1-1��ʒ[�E�ɍs���ƘL��1-2�ֈړ�
	if (hx + 64.0f > 800.0f && m_flag_Corridor1_1 == true)
	{
	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

	Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);

	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = true;
	}

	//�L��1-2��ʒ[���ɍs���ƘL��1-1�ֈړ�
	if (hx < 0.0f && m_flag_Corridor1_2 == true)
	{
	//Corridor1_1�I�u�W�F�N�g����
	CObjCorridor1_1* objb = new CObjCorridor1_1();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_1, 9);

	Draw::LoadImage(L"�L��1-1.png", 9, TEX_SIZE_512);

	m_flag_Corridor1_1 = true;
	m_flag_Corridor1_2 = false;
	}

	//�L��1-2��ʒ[�E�ɍs���ƘL��1-3�ֈړ�
	if (hx + 64.0f > 800.0f && m_flag_Corridor1_2 == true)
	{
	//Corridor1_3�I�u�W�F�N�g����
	CObjCorridor1_3* objb = new CObjCorridor1_3();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_3, 9);

	Draw::LoadImage(L"�L��1-3.png", 9, TEX_SIZE_512);

	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = true;
	}

	//�L��1-3��ʒ[���ɍs���ƘL��1-2�ֈړ�
	if (hx < 0.0f && m_flag_Corridor1_3 == true)
	{
	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

	Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);

	m_flag_Corridor1_3 = false;
	m_flag_Corridor1_2 = true;
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

	//�L��1-2��ʒ[��ɍs���ƘL��2-2�ֈړ�
	if (hy < 0.0f && Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneCorridor2_2());
	}

	//�L��1-3��l����y���Wy��175.0f�ȉ��ɂȂ�ƕی����ֈړ�
	if (hy + 64.0f < 175.0f && 150.0f < hx < 280.0f)
	{
	Scene::SetScene(new CSceneInfirmary());
	}
	*/

}

//�h���[
void CObjCorridor1::Draw()
{


}