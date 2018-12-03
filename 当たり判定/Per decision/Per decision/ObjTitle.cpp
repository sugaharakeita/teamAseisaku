#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

#include "ObjTitle.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false; //�L�[�t���O������
}

//�A�N�V����
void CObjTitle::Action()
{
	//Enter�L�[���������Ƃ�
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//�L�[�t���O��true�ɂȂ������A�L��1-2�\��
		//���̌�L�[�t���O������
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneCorridor1_2());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjTitle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	Font::StrDraw(L"School Horror", 160, 200, 80, c);
	Font::StrDraw(L"Enter�L�[�ŃX�^�[�g", 260, 400, 30, c);

}