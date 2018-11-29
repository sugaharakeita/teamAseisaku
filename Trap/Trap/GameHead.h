#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_TITLE,
	OBJ_HELP,
	OBJ_MAIN,
	OBJ_HERO,
	OBJ_EXCLAMATION,
	OBJ_MESSAGE,
	OBJ_KEY,
	KOUCHOU_KEY,
	HOKEN_KEY,
	OBJ_WALL,
	OBJ_HAKO,
	KOUCHOU_DOOR,
	SHOKUIN_DOOR,
	HOKEN_DOOR,
};
//------------------------------------------------

enum SPOT_NAME
{
	SPOT_ROUKA1,
	SPOT_KOUCHOU,
	SPOT_SHOKUIN,
	SPOT_HOKEN,
};

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_SPOT,
	ELEMENT_OBJECT,
	ELEMENT_DOOR,
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
#include "ObjTitle.h"
#include "ObjHelp.h"
#include "Hero.h"
#include "!.h"
#include "Message.h"
#include "TrapALL.h"
#include "ItemALL.h"
#include "ObjRouka1.h"
#include "KouchouHako.h"
#include "KouchouKey.h"
#include "ObjKouchouDoor.h"
#include "ObjKouchou.h"
#include "ObjShokuinDoor.h"
#include "ObjShokuin.h"
#include "HokenHako.h"
#include "HokenKey.h"
#include "ObjHokenDoor.h"
#include "ObjHoken.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneTitle.h"
#include "SceneHelp.h"
#include "SceneRouka1.h"
#include "SceneKouchou.h"
#include "SceneShokuin.h"
#include "SceneHoken.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle
//-----------------------------------------------