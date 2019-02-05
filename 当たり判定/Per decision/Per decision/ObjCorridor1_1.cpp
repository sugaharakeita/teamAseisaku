#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "ObjCorridor1_1.h"
#include "GameHead.h"

using namespace GameL;

extern float g_hero_x;
extern float g_hero_y;

//�C�j�V�����C�Y
void CObjCorridor1_1::Init()
{
	//���
	Hits::SetHitBox(this, 0.0f, 70.0f, 410, 110, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//���
	Hits::SetHitBox(this, 510.0f, 70.0f, 290, 110, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//����
	Hits::SetHitBox(this, 0.0f, 500.0f, 115, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//����
	Hits::SetHitBox(this, 215.0f, 500.0f, 445, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);

	//����
	Hits::SetHitBox(this, 755.0f, 500.0f, 40, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_1, 9);


}

//�A�N�V����
void CObjCorridor1_1::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	if (hx + 64.0f > 787.0f)
	{
		Hits::DeleteHitBox(this);
		Hits::DeleteHitBox(this);
	}

	//��ʍ����ɍs���ƐE�����Ɉړ�1
	if (hy > 450.0f && hx < 250.0f)
	{
		Scene::SetScene(new CSceneStaffroom());
		g_hero_x = 20;
		g_hero_y = 70;
	}

	//��ʉE���ɍs���ƐE�����Ɉړ�2
	if (hy > 450.0f && hx > 550.0f)
	{
		Scene::SetScene(new CSceneStaffroom());
		g_hero_x = 730;
		g_hero_y = 70;
	}

	//��ʏ�ɍs���ƍZ�����Ɉړ�
	if (hy < 120.0f)
	{
		Scene::SetScene(new CScenePrincipaloffice());
		g_hero_x = 600;
		g_hero_y = 520;
	}


}

//�h���[
void CObjCorridor1_1::Draw()
{
	/*
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//�w�i
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1038.0f;
	src.m_bottom = 360.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);
	*/

}