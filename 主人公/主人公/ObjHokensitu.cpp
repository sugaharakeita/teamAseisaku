//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHokensitu.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHokensitu::Init()
{
	m_x = 14;
	m_y = 13;
	
	//�����蔻��pHitBox���쐬
	//Hits::SetHitBox(this, m_x, m_y, 64, 150, ELEMENT_BLUE, OBJ_HOKENSITU, 1);

}

//�A�N�V����
void CObjHokensitu::Action()
{

	////HitBox�̓��e���X�V
	//CHitBox* hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);


	////��HitBox�ƐڐG�������l���폜
	//if (hit->CheckObjNameHit(OBJ_HOKENSITU) != nullptr)
	//{
	//	this->SetStatus(false);     //���g�ɍ폜���߂��o��
	//	Hits::DeleteHitBox(this);   //��l�������L����HitBox���폜����
	//}
}

//�h���[
void CObjHokensitu::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	RECT_F src;  //�`�挳�؂���ʒu
	RECT_F dst;  //�`���\���ʒu

	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 722.0f;
	src.m_bottom = 375.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 450.0f;
	
	//�`��
	Draw::Draw(5, &src, &dst, c, 0.0f);
}