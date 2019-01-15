//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneCorridor1.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneCorridor1::CSceneCorridor1()
{

}

//�f�X�g���N�^
CSceneCorridor1::~CSceneCorridor1()
{

}

//���������]�b�g
void CSceneCorridor1::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"��������.wav", BACK_MUSIC); //�ʏ�@�L��1
	Audio::LoadAudio(1, L"���_�̕�.wav", BACK_MUSIC); //Enemy�o��
	Audio::LoadAudio(3, L"�d���̊�.wav", BACK_MUSIC); //�ʏ�@�L��2


	Audio::LoadAudio(2, L"�w�Z�̘L������� .wav", BACK_MUSIC); //��l������

	//�{�����[����0.6���炷
	float v = Audio::VolumeMaster(0.6);

	//���y�X�^�[�g
	Audio::Start(0);

	//�b���J�E���g������
	m_time = 0;

	//�G���A�ړ��t���O������
	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;
	m_flag_Staffroom = false;
	m_flag_Principaloffice = false;
	m_flag_Infirmary = false;
	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;

	//�G���A�ԍ� 1=1-1,2-1,3-1  2=1-2,2-2,3-2  3=1-3,2-3,3-3
	//4=�E���� 5=�Z���� 6=�ی���
	m_Corridor_co = 2;

	//�K�w����������
	m_Storey = 1;

	//�A���ړ��h�~�t���O������
	m_flag_go = false;

	//Test Corridor1�I�u�W�F�N�g����
	CObjCorridor* objb = new CObjCorridor();

	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_ROOM, 9);
	//Objs::InsertObj(objb1_2, OBJ_ROOM, 9);

	Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);

	/*
	//Corridor1_1�I�u�W�F�N�g����
	CObjCorridor1_1* objb = new CObjCorridor1_1();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_1, 9);

	Draw::LoadImage(L"�L��1-1.png", 9, TEX_SIZE_512);

	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb = new CObjCorridor1_2();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_2, 9);

	Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);

	//Corridor1_3�I�u�W�F�N�g����
	CObjCorridor1_3* objb = new CObjCorridor1_3();
	Objs::InsertObj(objb, OBJ_CORRIDOR1_3, 9);

	Draw::LoadImage(L"�L��1-3.png", 9, TEX_SIZE_512);
	*/

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);


	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);
}


//���s�����]�b�g
void CSceneCorridor1::Scene()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//Test Corridor�I�u�W�F�N�g����
	CObjCorridor* objb = new CObjCorridor();
	//Test Corridor1�I�u�W�F�N�g����
	CObjCorridor1* objb1 = new CObjCorridor1();


	//Corridor1_1�I�u�W�F�N�g����
	CObjCorridor1_1* objb1_1 = new CObjCorridor1_1();
	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();
	//Corridor1_3�I�u�W�F�N�g����
	CObjCorridor1_3* objb1_3 = new CObjCorridor1_3();
	//Staffroom�I�u�W�F�N�g����
	CObjStaffroom* objbs = new CObjStaffroom();
	//Principaloffice�I�u�W�F�N�g����
	CObjPrincipaloffice* objbp = new CObjPrincipaloffice();
	//Infirmary�I�u�W�F�N�g����
	CObjInfirmary* objbi = new CObjInfirmary();
	//Corridor2_1�I�u�W�F�N�g����
	CObjCorridor2_1* objb2_1 = new CObjCorridor2_1();
	//Corridor2_2�I�u�W�F�N�g����
	CObjCorridor2_2* objb2_2 = new CObjCorridor2_2();
	//Corridor2_3�I�u�W�F�N�g����
	CObjCorridor2_3* objb2_3 = new CObjCorridor2_3();
	//Corridor2_1�I�u�W�F�N�g����
	CObjMap7* objb3_1 = new CObjMap7();
	//Corridor2_2�I�u�W�F�N�g����
	CObjMap8* objb3_2 = new CObjMap8();
	//Corridor2_3�I�u�W�F�N�g����
	CObjMap9* objb3_3 = new CObjMap9();
	//Enemy����
	CObjEnemy* objh = new CObjEnemy(0, 0);
	//Enemy2����
	CObjEnemy2* objh2 = new CObjEnemy2(0, 0);

	CHitBox* hit = Hits::GetHitBox(this);

	/*
	CHitBox* hit1_1 = Hits::GetHitBox(this);
	CHitBox* hit1_2 = Hits::GetHitBox(this);
	CHitBox* hit1_3 = Hits::GetHitBox(this);
	*/

	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;
	m_flag_Staffroom = false;
	m_flag_Principaloffice = false;
	m_flag_Infirmary = false;
	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;

	m_flag_go = false;

	//1�K
		//�L��1-1��ʒ[�E�ɍs���ƘL��1-2�ֈړ�
		if (hx + 64.0f > 800.0f && m_Corridor_co == 1
			&& m_flag_go == false && m_Storey == 1)
		{
			m_flag_Corridor1_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 1;
		}

		//�L��1-3��ʒ[���ɍs���ƘL��1-2�ֈړ�
		if (hx < 0.0f && m_Corridor_co == 3 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 1;
		}
	
		//�L��1-2��ʒ[���ɍs���ƘL��1-1�ֈړ�
		if (hx < 0.0f && m_Corridor_co == 2 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 1;
		}

		//�L��1-2��ʒ[�E�ɍs���ƘL��1-3�ֈړ�
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 1)
		{
			m_flag_Corridor1_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
			m_Storey = 1;
		}

		//�L��1-2��ʒ[��ɍs���ƘL��2-2�ֈړ�
		if (hy < 0.0f && Input::GetVKey(VK_RETURN) == true
			&& m_Corridor_co == 2 && m_flag_go == false 
			&& m_Storey == 1)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 2;
			m_time = 0;
		}

		//�L��1-1��ʉ��ɍs���ƐE�����ֈړ�
		if (hy > 450.0f && m_Corridor_co == 1 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Staffroom = true;
			m_flag_go = true;
			m_Corridor_co = 4;
			m_Storey = 1;
		}

		//�E������ʏ�ɍs���ƘL��1-1�ֈړ�
		if (hy < 70.0f && m_Corridor_co == 4 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 1;
		}

		//�L��1-1��ʏ�ɍs���ƍZ�����ֈړ�
		if (hy < 120.0f && m_Corridor_co == 1 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Principaloffice = true;
			m_flag_go = true;
			m_Corridor_co = 5;
			m_Storey = 1;
		}

		//�Z������ʉ��ɍs���ƘL��1-1�ֈړ�
		if (hy + 64.0f > 600.0f&&m_Corridor_co == 5 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 1;
		}

		//�L��1-3��ʏ�ɍs���ƕی����ֈړ�
		if (hy < 120.0f && m_Corridor_co == 3 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Infirmary = true;
			m_flag_go = true;
			m_Corridor_co = 6;
			m_Storey = 1;
		}

		//�ی�����ʉ��ɍs���ƘL��1-3�ֈړ�
		if (hy + 64.0f > 600.0f&&m_Corridor_co == 6 && m_flag_go == false
			&& m_Storey == 1)
		{
			m_flag_Corridor1_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
			m_Storey = 1;
		}


	//2�K
		//�L��2-1��ʒ[�E�ɍs���ƘL��2-2�ֈړ�
		if (hx + 64.0f > 800.0f && m_Corridor_co == 1
			&& m_flag_go == false && m_Storey == 2)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 2;
		}

		//�L��2-3��ʒ[���ɍs���ƘL��2-2�ֈړ�
		if (hx < 0.0f && m_Corridor_co == 3 && m_flag_go == false
			&& m_Storey == 2)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 2;
		}

		//�L��2-2��ʒ[���ɍs���ƘL��2-1�ֈړ�
		if (hx < 0.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 2)
		{
			m_flag_Corridor2_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 2;
		}

		//�L��2-2��ʒ[�E�ɍs���ƘL��2-3�ֈړ�
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 2)
		{
			m_flag_Corridor2_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
			m_Storey = 2;
		}
		
		//�L��2-2��ʒ[��ɍs���ƘL��3-2�ֈړ�
		if (hy < 0.0f && Input::GetVKey(VK_SPACE) == true
			&& m_Corridor_co == 2 && m_flag_go == false
			&& m_Storey == 2)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 3;
			m_time = 0;
		}


	//3�K
	//�L��3-1��ʒ[�E�ɍs���ƘL��3-2�ֈړ�
		if (hx + 64.0f > 800.0f && m_Corridor_co == 1
			&& m_flag_go == false && m_Storey == 3)
		{
			m_flag_Corridor3_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 3;
		}

		//�L��3-3��ʒ[���ɍs���ƘL��3-2�ֈړ�
		if (hx < 0.0f && m_Corridor_co == 3 && m_flag_go == false
			&& m_Storey == 3)
		{
			m_flag_Corridor3_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 3;
		}

		//�L��3-2��ʒ[���ɍs���ƘL��3-1�ֈړ�
		if (hx < 0.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 3)
		{
			m_flag_Corridor3_1 = true;
			m_flag_go = true;
			m_Corridor_co = 1;
			m_Storey = 3;
		}

		//�L��3-2��ʒ[�E�ɍs���ƘL��3-3�ֈړ�
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			 && m_Storey == 3)
		{
			m_flag_Corridor3_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
			m_Storey = 3;
		}


	//��ʒ[��ɍs���ƃN���A���
	if (hy < 0.0f && Input::GetVKey(VK_SHIFT) == true)
	{
		Scene::SetScene(new CSceneClear());
	}


		
	//�`�揈��
	//�`�悳���鏈��
	if (m_flag_Corridor1_1 == true && m_Corridor_co == 1
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		//Objs::InsertObj(objb1, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_1, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_2 == true && m_Corridor_co == 2
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		//Objs::InsertObj(objb1, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_2, OBJ_ROOM, 9);
		
		Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);
	}
	
	if (m_flag_Corridor1_3 == true && m_Corridor_co == 3
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��1-3.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Staffroom == true && m_Corridor_co == 4
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objbs, OBJ_ROOM, 9);

		Draw::LoadImage(L"�E����.PNG", 9, TEX_SIZE_512);
	}

	if (m_flag_Principaloffice == true && m_Corridor_co == 5
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objbp, OBJ_ROOM, 9);

		Draw::LoadImage(L"�Z����.PNG", 9, TEX_SIZE_512);
	}

	if(m_flag_Infirmary == true && m_Corridor_co == 6
		&& m_Storey == 1)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objbi, OBJ_ROOM, 9);

		Draw::LoadImage(L"�ی���.PNG", 9, TEX_SIZE_512);
	}


	if (m_flag_Corridor2_1 == true && m_Corridor_co == 1
		&& m_Storey == 2)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb2_1, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��2-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_2 == true && m_Corridor_co == 2
		&& m_Storey == 2)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb2_2, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��2-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_3 == true && m_Corridor_co == 3
		&& m_Storey == 2)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb2_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��2-3.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_1 == true && m_Corridor_co == 1
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_1, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��3-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_2 == true && m_Corridor_co == 1
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_2, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��3-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_3 == true && m_Corridor_co == 1
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��3-3.png", 9, TEX_SIZE_512);
	}


	//�`����Ȃ�������
	if (hx>=100.0f && m_flag_Corridor1_1 == false)
	{
		//Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_1, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-1.png", 9, TEX_SIZE_512);

	}

	if (hx >= 750.0f &&m_flag_Corridor1_2 == false)
	{
		//Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_2, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_3 == false)
	{
		//Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_3, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-3.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_1 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_1, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_2 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_2, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor2_3 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_3, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-3.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_1 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_1, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_2 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_2, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_3 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_3, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-3.png", 9, TEX_SIZE_512);
	}


	/*
	m_time++;

	//�G�I�u�W�F�N�g�쐬(��{�����Y)�E�G�o����BGM�ύX
	if (m_time == 90 && m_Storey == 1)
	{
	Objs::InsertObj(objh, OBJ_ENEMY, 11);

	Draw::LoadImage(L"��{�����Y����.png", 11, TEX_SIZE_512);

	Audio::Stop(0);
	Audio::Start(1);
	}

	//�G�I�u�W�F�N�g�쐬(�ʂ������)�E�G�o����BGM�ύX
	if (m_time == 90 && m_Storey == 2)
	{
	Objs::InsertObj(objh2, OBJ_ENEMY, 11);

	Draw::LoadImage(L"�ʂ�����ݓ���.png", 11, TEX_SIZE_512);

	Audio::Stop(0);
	Audio::Start(1);
	}

	if (m_time == 90 && m_Storey == 3)
	{
	Objs::InsertObj(objh2, OBJ_ENEMY, 11);

	Draw::LoadImage(L"�G��.png", 11, TEX_SIZE_512);

	Audio::Stop(0);
	Audio::Start(1);
	}

	*/

}
