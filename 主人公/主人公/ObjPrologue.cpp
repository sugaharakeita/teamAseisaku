//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjPrologue.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjPrologue::Init()
{

}

//�A�N�V����
void CObjPrologue::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[��Title�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
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