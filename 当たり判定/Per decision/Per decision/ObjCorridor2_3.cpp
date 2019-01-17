#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor2_3.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjCorridor2_3::Init()
{
	//���
	Hits::SetHitBox(this, 0.0f, 0.0f, 800, 175, ELEMENT_FIELD, OBJ_CORRIDOR2_3, 9);

	//����
	Hits::SetHitBox(this, 144.0f, 500.0f, 495, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_3, 9);

	//����
	Hits::SetHitBox(this, 780.0f, 500.0f, 20, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_3, 9);

}

//�A�N�V����
void CObjCorridor2_3::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hx < 10.0f || hy > 510.0f)
	{
		Hits::DeleteHitBox(this);
	}

	/*
	//��ʒ[���ɍs���ƘL��2-2�ֈړ�
	if (hx < 0.0f)
	{
	Scene::SetScene(new CSceneCorridor2_2());
	}
	*/

}

//�h���[
void CObjCorridor2_3::Draw()
{
	/*
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//�w�i
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 360.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	*/

}