//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"


#include"GameHead.h"
#include"ObjPrologue.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjPrologue::Init()
{
	m_key_flag = false; //�L�[�t���O������
	m_start = false; //�X�^�[�g�t���O������
	m_start_co = 0; //�X�^�[�g�J�E���g������
}

//�A�N�V����
void CObjPrologue::Action()
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
			Scene::SetScene(new CSceneCorridor());
			m_key_flag = false;
			m_start = false;
			m_start_co = 0;
		}
	}

}

//�h���[
void CObjPrologue::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"���炷��", 50, 100, 32, c);
	Font::StrDraw(L"��l���͖Y�ꕨ�����Ɋw�Z�֖K�ꂽ�B", 50, 150, 32, c);
	Font::StrDraw(L"�����ŁA��l���͗l�X�ȉ��قɏo��E�E�E", 50, 200, 32, c);
	Font::StrDraw(L"���ق̖ڂ�~������Ȃ���", 150, 300, 40, c);
	Font::StrDraw(L"�����ڎw���A�E�o���悤��", 150, 350, 40, c);
	Font::StrDraw(L"Enter��Let's go!!", 250, 500, 32, c);


}