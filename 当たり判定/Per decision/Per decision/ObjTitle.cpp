#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "ObjTitle.h"
#include "GameHead.h"

using namespace GameL;



//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false; //�L�[�t���O������
	m_start = false; //�X�^�[�g�t���O������
	m_start_co = 0; //�X�^�[�g�J�E���g������
}

//�A�N�V����
void CObjTitle::Action()
{
	//Enter�L�[���������Ƃ�
	if (Input::GetVKey(VK_RETURN) == true && m_start == false)
	{
		Audio::Start(1);
		m_start = true;
		m_key_flag = true;
	}

	//�L�[�t���O��true�ɂȂ������A����Enter�L�[����������L��1-2�\��
	//���̌�L�[�t���O�E�X�^�[�g�t���O�E�X�^�[�g�J�E���g������
	if (m_key_flag == true)
	{
		m_start_co += 1.0f;
		if (m_start_co == 20)
		{
			Scene::SetScene(new CScenePrologue());
			m_key_flag = false;
			m_start = false;
			m_start_co = 0;
		}
	}
}

//�h���[
void CObjTitle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f };

	Font::StrDraw(L"School",280, 200, 80, c);
	Font::StrDraw(L"Enter�L�[�ŃX�^�[�g", 260, 400, 30, c);

}