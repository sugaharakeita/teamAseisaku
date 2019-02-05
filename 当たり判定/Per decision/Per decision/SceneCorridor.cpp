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
#include "SceneCorridor.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneCorridor::CSceneCorridor()
{

}

//�f�X�g���N�^
CSceneCorridor::~CSceneCorridor()
{

}

//���������]�b�g
void CSceneCorridor::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"��������.wav", BACK_MUSIC); //�ʏ�@�L��1
	Audio::LoadAudio(1, L"���_�̕�.wav", BACK_MUSIC); //Enemy�o��

	
	Audio::LoadAudio(2, L"�w�Z�̘L������� .wav", BACK_MUSIC); //��l������
	Audio::LoadAudio(4, L"�����̔��J�Q .wav", EFFECT); //�����ړ�
	Audio::LoadAudio(5, L"����01�@�K�i .wav", EFFECT); //�K�i�ړ�

	//�{�����[����0.8���炷
	float v = Audio::VolumeMaster(0.8);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);

	//�b���J�E���g������
	m_time = 0;

	//�G���A�ړ��t���O������
	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;
	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;
	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;
	m_flag_Rooftop = false;

	//�G���A�ԍ� 1=1-1,2-1,3-1  2=1-2,2-2,3-2  3=1-3,2-3,3-3
	m_Corridor_co = 2;

	//�K�w����������
	m_Storey = 1;


	//�A���ړ��h�~�t���O������
	m_flag_go = false;

	//Test Corridor�I�u�W�F�N�g����
	CObjCorridor* objb = new CObjCorridor();
	//Test Corridor1�I�u�W�F�N�g����
	CObjCorridor1* objb1 = new CObjCorridor1();


	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();


	Objs::InsertObj(objb1, OBJ_ROOM, 9);
	Objs::InsertObj(objb1_2, OBJ_ROOM, 9);

	Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);
	


	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);


	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);
}


//���s�����]�b�g
void CSceneCorridor::Scene()
{

	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�`����
	//Test Corridor�I�u�W�F�N�g����
	CObjCorridor* objb = new CObjCorridor();
	//Test Corridor1�I�u�W�F�N�g����
	CObjCorridor1* objb1 = new CObjCorridor1();


	//1�K
	//Corridor1_1�I�u�W�F�N�g����
	CObjCorridor1_1* objb1_1 = new CObjCorridor1_1();
	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();
	//Corridor1_3�I�u�W�F�N�g����
	CObjCorridor1_3* objb1_3 = new CObjCorridor1_3();

	//2�K
	//Corridor2_1�I�u�W�F�N�g����
	CObjCorridor2_1* objb2_1 = new CObjCorridor2_1();
	//Corridor2_2�I�u�W�F�N�g����
	CObjCorridor2_2* objb2_2 = new CObjCorridor2_2();
	//Corridor2_3�I�u�W�F�N�g����
	CObjCorridor2_3* objb2_3 = new CObjCorridor2_3();
	
	//3�K
	//Corridor3_1�I�u�W�F�N�g����
	CObjMap7* objb3_1 = new CObjMap7();
	//Corridor3_2�I�u�W�F�N�g����
	CObjMap8* objb3_2 = new CObjMap8();
	//Corridor3_3�I�u�W�F�N�g����
	CObjMap9* objb3_3 = new CObjMap9();

	//����
	//Rooftop�I�u�W�F�N�g����
	CObjRooftop* obj_br = new CObjRooftop();

	//�G
	//Enemy����
	CObjEnemy* objh = new CObjEnemy(0, 0);
	//Enemy2����
	CObjEnemy2* objh2 = new CObjEnemy2(0, 0);
	//Enemy3����
	CObjEnemy3* objh3 = new CObjEnemy3(0, 0);


	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;

	m_flag_Corridor2_1 = false;
	m_flag_Corridor2_2 = false;
	m_flag_Corridor2_3 = false;

	m_flag_Corridor3_1 = false;
	m_flag_Corridor3_2 = false;
	m_flag_Corridor3_3 = false;

	m_flag_Rooftop = false;

	m_flag_go = false;

	float v4 = Audio::VolumeMaster(4);
	v4 = Audio::VolumeMaster(0.5);
	float v5 = Audio::VolumeMaster(5);
	v5 = Audio::VolumeMaster(0.5);
	

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

		//�L��1-2��ʒ[�E�ɍs���ƘL��1-3�ֈړ�
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 1)
		{
			m_flag_Corridor1_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
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


		//�L��1-2��ʒ[��ɍs���ƘL��2-2�ֈړ�
		if (hy < 0.0f &&  m_Corridor_co == 2 && m_flag_go == false 
			&& m_Storey == 1 && Input::GetVKey(VK_RETURN) == true)
		{
			m_flag_Corridor2_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 2;
			m_time = 0;
			Audio::Stop(1);
			Audio::Start(5);
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

		//�L��2-2��ʒ[�E�ɍs���ƘL��2-3�ֈړ�
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_flag_go == false && m_Storey == 2)
		{
			m_flag_Corridor2_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
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

		
		//�L��2-2��ʒ[��ɍs���ƘL��3-2�ֈړ�
		if (hy < 0.0f && m_Corridor_co == 2 && m_flag_go == false
			&& m_Storey == 2 && Input::GetVKey(VK_RETURN) == true)
		{
			m_flag_Corridor3_2 = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 3;
			m_time = 0;
			Audio::Stop(1);
			Audio::Start(5);
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

		//�L��3-2��ʒ[�E�ɍs���ƘL��3-3�ֈړ�
		if (hx + 64.0f > 800.0f && m_Corridor_co == 2
			&& m_Storey == 3)
		{
			m_flag_Corridor3_3 = true;
			m_flag_go = true;
			m_Corridor_co = 3;
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

		//�L��3-2��ʒ[��ɍs���Ɖ���ֈړ�
		if (hy < 0.0f && m_Corridor_co == 2 && m_flag_go == false
			&& m_Storey == 3 && Input::GetVKey(VK_RETURN) == true)
		{
			m_flag_Rooftop = true;
			m_flag_go = true;
			m_Corridor_co = 2;
			m_Storey = 4;
			m_time = 0;
			Audio::Stop(1);
			Audio::Start(5);
		}


	//�����ʒ[��ɍs���ƃN���A���
	if (hy < 0.0f && Input::GetVKey(VK_RETURN) == true
		&& m_Storey == 4 && m_Corridor_co == 2)
	{
		Scene::SetScene(new CSceneClear());
	}


		
	//�`�揈��
	//�`�悳���鏈��
	//1�K
	if (m_flag_Corridor1_1 == true)
	{
		Objs::InsertObj(objb1, OBJ_ROOM, 9); //�摜
		Objs::InsertObj(objb1_1, OBJ_ROOM, 9); //�����蔻��

		Draw::LoadImage(L"�L��1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_2 == true)
	{
		Objs::InsertObj(objb1, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_2, OBJ_ROOM, 9);
		
		Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);
	}
	
	if (m_flag_Corridor1_3 == true)
	{
		Objs::InsertObj(objb1, OBJ_ROOM, 9);
		Objs::InsertObj(objb1_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��1-3.png", 9, TEX_SIZE_512);
	}


	//2�K
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


	//3�K
	if (m_flag_Corridor3_1 == true && m_Corridor_co == 1
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_1, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��3-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_2 == true && m_Corridor_co == 2
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_2, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��3-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor3_3 == true && m_Corridor_co == 3
		&& m_Storey == 3)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(objb3_3, OBJ_ROOM, 9);

		Draw::LoadImage(L"�L��3-3.PNG", 9, TEX_SIZE_512);
	}
	

	//����
	if (m_flag_Rooftop == true && m_Corridor_co == 2
		&& m_Storey == 4)
	{
		Objs::InsertObj(objb, OBJ_ROOM, 9);
		Objs::InsertObj(obj_br, OBJ_ROOM, 9);

		Draw::LoadImage(L"����.png", 9, TEX_SIZE_512);
	}

	m_time++;



	/*
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
	
	//�G�I�u�W�F�N�g�쐬(�G��)�E�G�o����BGM�ύX
	if (m_time == 90 && m_Storey == 3)
	{
	Objs::InsertObj(objh3, OBJ_ENEMY, 11);

	Draw::LoadImage(L"�G��.png", 11, TEX_SIZE_512);

	Audio::Stop(0);
	Audio::Start(1);
	}

	*/

}
