#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "SwitchALL.h"
//�q�[���[�֌W
bool Hero;
int HERO = 3;//��l���̌���
int HeroStop;//��l���̓������~�߂�B�����ɂ���Ď~�܂�������ς��B�S�Ȃ瓮�����A�T�Ȃ�~�܂�Ȃ�
float HeroX;//��l���̂w���W���擾����
float HeroY;
bool HeroL;//��l���͍����ɋ���
bool HeroR;
//�ȉ���l���̃q�b�g�t���O
bool HIT_flag;
bool HAKO_flag;
bool DOOR_flag;
bool ITEM_flag;
bool TEXT_flag;
//�V�X�e���֌W
int Message;
int Text;
int Menu;
//�����֌W�BLCR�͂��ꂼ�ꍶ���A�������A�E���������B
int Title;
int room[32];//�؂�ւ��p
//�؂�ւ��p�Broom�Ƃ͕ʂɓ���
int Rouka1L;
int Rouka1CL;
int Rouka1CR;
int Rouka1R;
int Kouchou;
int Shokuin;
int Hoken;
int Rouka2L;
int Rouka2C;
int Rouka2R;
int Kateika;
int KateikaJunbi;
int Kyoushitu;
int Tosho;

void CObjSwitchALL::Init()
{
	m_x = 0.0f;
	m_y = 476.0f;
}

void CObjSwitchALL::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,0.25f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 768.0f;
	src.m_bottom = 614.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 800.0f + m_x;
	dst.m_bottom = 600.0f + m_y;
}