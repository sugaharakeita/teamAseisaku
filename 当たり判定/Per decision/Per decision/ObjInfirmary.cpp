#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjInfirmary.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjInfirmary::Init()
{
	//���
	Hits::SetHitBox(this, 0.0f, 0.0f, 800, 15, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//��
	Hits::SetHitBox(this, 15.0f, 15.0f, 60, 205, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//�J�[�e���E�x�b�g�i�R���j
	Hits::SetHitBox(this, 305.0f, 15.0f, 405, 210, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//�֎q1
	Hits::SetHitBox(this, 100.0f, 145.0f, 25, 55, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//�֎q2
	Hits::SetHitBox(this, 105.0f, 255.0f, 20, 50, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//��
	Hits::SetHitBox(this, 340.0f, 335.0f, 50, 200, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//�\�t�@
	Hits::SetHitBox(this, 482.0f, 322.0f, 53, 213, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//�̏d�v
	Hits::SetHitBox(this, 690.0f, 430.0f, 35, 150, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//�g�������
	Hits::SetHitBox(this, 725.0f, 375.0f, 60, 205, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//����
	Hits::SetHitBox(this, 0.0f, 585.0f, 80, 10, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//���h�A
	//Hits::SetHitBox(this, 80.0f, 599.0f, 73, 1, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

	//����
	Hits::SetHitBox(this, 153.0f, 585.0f, 647, 10, ELEMENT_INFIRMARY, OBJ_INFIRMARY, 9);

}

//�A�N�V����
void CObjInfirmary::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hy + 64.0f > 600.0f && 80.0f < hx < 153.0f)
	{
		Scene::SetScene(new CSceneCorridor1_3());
	}

}

//�h���[
void CObjInfirmary::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//�w�i
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 720.0f;
	src.m_bottom = 370.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

}