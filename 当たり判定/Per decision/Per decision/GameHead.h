#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_HERO,
	OBJ_TIME,
	OBJ_ENEMY,
	OBJ_STAFFROOM,
	OBJ_PRINCIPALOFFICE,
	OBJ_INFIRMARY,
	OBJ_CORRIDOR1_1,
	OBJ_CORRIDOR1_2,
	OBJ_CORRIDOR1_3,
	OBJ_CLEAR,
	OBJ_TITLE,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_FIELD,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^

};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjStaffroom.h"
#include "ObjPrincipaloffice.h"
#include "ObjInfirmary.h"
#include "ObjCorridor1_1.h"
#include "ObjCorridor1_2.h"
#include "ObjCorridor1_3.h"
#include "ObjHero.h"
#include "ObjClear.h"
#include "ObjTitle.h"
#include "ObjPerdecision.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneStaffroom.h"
#include "ScenePrincipaloffice.h"
#include "SceneInfirmary.h"
#include "SceneCorridor1_1.h"
#include "SceneCorridor1_2.h"
#include "SceneCorridor1_3.h"
#include "SceneClear.h"
#include "SceneTitle.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
/*
#define SET_GAME_START  CSceneStaffroom
#define SET_GAME_START  CScenePrincipaloffice
#define SET_GAME_START  CSceneInfirmary
#define SET_GAME_START  CSceneCorridor1_1
#define SET_GAME_START  CSceneCorridor1_2
#define SET_GAME_START  CSceneCorridor1_3
#define SET_GAME_START  CSceneClear
*/
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------