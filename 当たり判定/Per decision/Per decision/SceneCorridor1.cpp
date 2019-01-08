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
	Audio::LoadAudio(0, L"��������.wav", BACK_MUSIC); //�ʏ�@�L��
	Audio::LoadAudio(1, L"���_�̕�.wav", BACK_MUSIC); //Enemy�o��

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

	//�G���A�ԍ�
	m_Corridor1_co = 2;

	//�A���ړ��h�~�t���O������
	m_flag_go = false;

	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objbb = new CObjCorridor1_2();
	Objs::InsertObj(objbb, OBJ_CORRIDOR1_2, 9);

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

	Draw::LoadImage(L"��{�����Y����.png", 11, TEX_SIZE_512);
}


//���s�����]�b�g
void CSceneCorridor1::Scene()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//Corridor1_1�I�u�W�F�N�g����
	CObjCorridor1_1* objb1_1 = new CObjCorridor1_1();
	//Corridor1_2�I�u�W�F�N�g����
	CObjCorridor1_2* objb1_2 = new CObjCorridor1_2();
	//Corridor1_3�I�u�W�F�N�g����
	CObjCorridor1_3* objb1_3 = new CObjCorridor1_3();

	/*
	CHitBox* hit1_1 = Hits::GetHitBox(this);
	CHitBox* hit1_2 = Hits::GetHitBox(this);
	CHitBox* hit1_3 = Hits::GetHitBox(this);
	*/

	m_flag_Corridor1_1 = false;
	m_flag_Corridor1_2 = false;
	m_flag_Corridor1_3 = false;

	m_flag_go = false;

	//�L��1-1��ʒ[�E�ɍs���ƘL��1-2�ֈړ�
	if (hx + 64.0f > 800.0f && m_Corridor1_co == 1
		&& m_flag_go == false)
	{
		m_flag_Corridor1_2 = true;
		m_flag_go = true;
		m_Corridor1_co = 2;
	}

	//�L��1-3��ʒ[���ɍs���ƘL��1-2�ֈړ�
	if (hx < 0.0f && m_Corridor1_co == 3 && m_flag_go == false)
	{
		m_flag_Corridor1_2 = true;
		m_flag_go = true;
		m_Corridor1_co = 2;
	}
	
	//�L��1-2��ʒ[���ɍs���ƘL��1-1�ֈړ�
	if (hx < 0.0f && m_Corridor1_co == 2 && m_flag_go == false)
	{
		m_flag_Corridor1_1 = true;
		m_flag_go = true;
		m_Corridor1_co = 1;
	}

	//�L��1-2��ʒ[�E�ɍs���ƘL��1-3�ֈړ�
	if (hx + 64.0f > 800.0f && m_Corridor1_co == 2
		&& m_flag_go == false)
	{
		m_flag_Corridor1_3 = true;
		m_flag_go = true;
		m_Corridor1_co = 3;
	}
		

	if (m_flag_Corridor1_1 == true && m_Corridor1_co == 1)
	{
		Objs::InsertObj(objb1_1, OBJ_CORRIDOR1_1, 9);

		Draw::LoadImage(L"�L��1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_2 == true && m_Corridor1_co == 2)
	{
		Objs::InsertObj(objb1_2, OBJ_CORRIDOR1_2, 9);

		Draw::LoadImage(L"�L��1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_3 == true && m_Corridor1_co == 3)
	{
		Objs::InsertObj(objb1_3, OBJ_CORRIDOR1_3, 9);

		Draw::LoadImage(L"�L��1-3.png", 9, TEX_SIZE_512);
	}
	

	if (m_flag_Corridor1_1 == false)
	{
		//Objs::Delete(objb1_1, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-1.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_2 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_2, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-2.png", 9, TEX_SIZE_512);
	}

	if (m_flag_Corridor1_3 == false)
	{
		Hits::DeleteHitBox(this);
		//Objs::Delete(objb1_3, OBJ_CORRIDOR1_1, 9);

		//Draw::DeleteImage(L"�L��1-3.png", 9, TEX_SIZE_512);
	}

	/*
	m_time++;

	//�G�I�u�W�F�N�g�쐬�E�G�o����BGM�ύX
	if (m_time == 90)
	{
	CObjEnemy* objh = new CObjEnemy(0, 0);
	Objs::InsertObj(objh, OBJ_ENEMY, 11);

	Audio::Stop(0);
	Audio::Start(1);
	}
	*/
	
}
