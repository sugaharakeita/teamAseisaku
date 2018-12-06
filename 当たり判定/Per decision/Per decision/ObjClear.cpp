#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

#include "ObjClear.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjClear::Init()
{
	//�L�[�t���O������
	m_key_flag = false;
}

//�A�N�V����
void CObjClear::Action()
{
	//Enter�L�[���������Ƃ�
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//�L�[�t���O��true�ɂȂ������A�^�C�g���\��
		//���̌�L�[�t���O������
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjClear::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	Font::StrDraw(L"���ł͂����܂łł�", 270, 200, 30, c);
	Font::StrDraw(L"�����̓��ł�", 320, 280, 30, c);
	Font::StrDraw(L"Enter�L�[�Ń^�C�g����",250,360,30,c);
	
}