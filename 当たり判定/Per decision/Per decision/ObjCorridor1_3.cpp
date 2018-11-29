#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "ObjCorridor1_3.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjCorridor1_3::Init()
{
	//���
	Hits::SetHitBox(this, 0.0f, 0.0f, 150, 175, ELEMENT_FIELD, OBJ_CORRIDOR1_3, 9);

	//���
	Hits::SetHitBox(this, 280.0f, 0.0f, 525, 175, ELEMENT_FIELD, OBJ_CORRIDOR1_3, 9);

	//����
	Hits::SetHitBox(this, 0.0f, 500.0f, 800, 100, ELEMENT_FIELD, OBJ_CORRIDOR1_3, 9);
	
}

//�A�N�V����
void CObjCorridor1_3::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//��ʒ[���ɍs���ƘL��1-2�ֈړ�
	if (hx < 0.0f)
	{
		Scene::SetScene(new CSceneCorridor1_2());
	}

	//��l����y���Wy��175.0f�ȉ��ɂȂ�ƕی����ֈړ�
	if (hy + 64.0f < 175.0f && 150.0f < hx < 280.0f)
	{
		Scene::SetScene(new CSceneInfirmary());
	}

}

//�h���[
void CObjCorridor1_3::Draw()
{
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

}