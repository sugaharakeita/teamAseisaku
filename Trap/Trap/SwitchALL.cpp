#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "SwitchALL.h"
//�q�[���[�֌W
bool Hero;//��l������������Ă��邱�Ƃ������B
int HERO = 3;//��l���̌����B0����E�A���A���A��
int HeroStop;/*��l���̓������~�߂�B�����ɂ���Ď~�܂�������ς��B
0�`3��HERO�Ɠ��������ɓ����Ȃ��B�S�Ȃ瓮�����A�T�Ȃ�~�܂�Ȃ�*/
float HeroX;//��l���̂w���W���擾����
float HeroY;//��l���̂x���W���擾����
bool HeroL;//��l���͍����ɋ���
//�ȉ���l���̃q�b�g�t���O�B
bool HIT_flag;//�G�Ƃ̐ڐG����
bool HAKO_flag;//���Ƃ̐ڐG����
bool DOOR_flag;//���Ƃ̐ڐG����
bool ITEM_flag;//�A�C�e���Ƃ̐ڐG����
bool TEXT_flag;//���ȂǏ��̓����镨�̂Ƃ̐ڐG����
//�V�X�e���֌W
int Message;
int Text;
int Menu;
/*�؂�ւ��p�BTitle��room���ɓ���Ȃ��B
room�͎�l���̋��镔�����ARouka1L�ȍ~�͂ǂ̕�������ڂ��������Ǘ�����*/
int Title;
int room[32];
int Rouka1L;//�P�K�L������
int Rouka1CL;//�P�K�L����������
int Rouka1CR;//�P�K�L�������E��
int Rouka1R;//�P�K�L���E��
int Kouchou;
int Shokuin;
int Hoken;
int Rouka2L;//�Q�K�L������
int Rouka2C;//�Q�K�L������
int Rouka2R;//�Q�K�L���E��
int Kateika;
int KateikaJunbi;
int Kyoushitu;
int Tosho;