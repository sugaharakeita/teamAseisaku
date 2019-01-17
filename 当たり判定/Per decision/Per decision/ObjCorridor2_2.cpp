#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor2_2.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjCorridor2_2::Init()
{
	//���
	Hits::SetHitBox(this, 0.0f, 0.0f, 140, 180, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//���
	Hits::SetHitBox(this, 140.0f, 0.0f, 1, 180, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//�K�i1

	//���
	Hits::SetHitBox(this, 331.0f, 0.0f, 16, 180, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//�K�i2
	Hits::SetHitBox(this, 347.0f, 50.0f, 200, 1, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//���
	Hits::SetHitBox(this, 536.0f, 0.0f, 264, 180, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//����
	Hits::SetHitBox(this, 0.0f, 500.0f,800, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

	//����
	Hits::SetHitBox(this, 0.0f, 500.0f, 800, 100, ELEMENT_FIELD, OBJ_CORRIDOR2_2, 9);

}

//�A�N�V����
void CObjCorridor2_2::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	if (hx < 50.0f || hx + 64.0f > 770.0f || hy < 5.0f)
	{
		Hits::DeleteHitBox(this);
	}

	/*
	//��ʒ[���ɍs���ƘL��2-1�ֈړ�
	if (hx < 0.0f)
	{
	Scene::SetScene(new CSceneCorridor2_1());
	}

	//��ʒ[�E�ɍs���ƘL��2-3�ֈړ�
	if (hx + 64.0f > 800.0f)
	{
	Scene::SetScene(new CSceneCorridor2_3());
	}

	//��ʒ[��ɍs���ƃN���A���
	if (hy < 0.0f && Input::GetVKey(VK_RETURN) == true)
	{
	Scene::SetScene(new CSceneClear());
	}
	*/
}

//�h���[
void CObjCorridor2_2::Draw()
{
	/*
		//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//�w�i
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 380.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

	*/

}