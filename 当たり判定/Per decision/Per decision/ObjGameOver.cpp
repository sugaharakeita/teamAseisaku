//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	m_key_flag = false; //�L�[�t���O������
	m_gameover = false; //�Q�[���I�[�o�[�t���O������
	m_gameover_co = 0; //�Q�[���I�[�o�[�J�E���g������
}

//�A�N�V����
void CObjGameOver::Action()
{
	//Enter�L�[���������Ƃ�
	if (Input::GetVKey(VK_RETURN) == true && m_gameover == false)
	{
		Audio::Start(1);
		m_gameover = true;
		m_key_flag = true;
	}


	//�L�[�t���O��true�ɂȂ������A����Enter�L�[����������^�C�g���\��
	//���̌�L�[�t���O�E�Q�[���I�[�o�[�t���O�E
	//�Q�[���I�[�o�[�J�E���g������
	if (m_key_flag == true)
	{
		m_gameover_co += 1.0f;
		if (m_gameover_co == 20)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
			m_gameover = false;
			m_gameover_co = 0;
		}
	}
}

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"���[�ނ��[�΁[�I�I", 250, 250, 32, c);
	Font::StrDraw(L"(�L�O3 ^`�jm9", 250, 300, 32, c);
	Font::StrDraw(L"�^�C�g����(EnterKey)", 250, 400, 32, c);

}