//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"


#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

float g_hero_x = 150.0f;
float g_hero_y = 150.0f;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = g_hero_x; //�ʒu 
	m_py = g_hero_y;
	
	m_vx = 0.0f;  //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 3;   //�E����0.0f�@������1.0f ����2.0f ���3.0f
	m_go_cox = 2; //�L���ړ���x������ 
				  //1=1.2.3-1, 2=1.2.3-2, 3=1.2.3-3
	m_go_coy = 2; //�����ړ���y������ 
				  //1=�㑤�̋��� 2=�L�� 3=�����̋���

	m_ani_time = 0;
	m_ani_frame = 1;  //�Î~�t���[���������ɂ���
	m_footsteps_co = 0; //�����b���J�E���g������
	m_footsteps_switching = false; //�����I�t��

	//�Փˏ�Ԋm�F�p������
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	
	//�����蔻��                                
	Hits::SetHitBox(this, m_px+16 , m_py+50 , 32, 10, ELEMENT_PLAYER, OBJ_HERO, 1);
	//					���J�n �c�J�n ���傫�� �c�傫�� ���� ���O
}

//�A�N�V����
void CObjHero::Action()
{

	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//��l���ƒǔ��Ŋp�x�����
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	int x = obj->GetX() - m_px;
	int y = obj->GetY() - m_py;

	//�L�[�̓��͕���
	//��L�[�������蔻��Ɠ������Ă��Ȃ��ꍇ
	if (Input::GetVKey('W') == true && m_hit_up == false)
	{
		m_vy = -4.0f;
		m_posture = 3;
		m_ani_time += 1;
		m_footsteps_switching = true; //�����I��
	}

	//���L�[�������蔻��Ɠ������Ă��Ȃ��ꍇ
	else if (Input::GetVKey('A') == true && m_hit_right == false)
	{
		m_vx -= 4.0f;
		m_posture = 1;
		m_ani_time += 1;
		m_footsteps_switching = true; //�����I��
	}

	//���L�[�������蔻��Ɠ������Ă��Ȃ��ꍇ
	else if (Input::GetVKey('S') == true && m_hit_down == false)
	{
		m_vy = +4.0f;
		m_posture = 2;
		m_ani_time += 1;
		m_footsteps_switching = true; //�����I��
	}

	//�E�L�[�������蔻��Ɠ������Ă��Ȃ��ꍇ
	else if (Input::GetVKey('D') == true && m_hit_left == false)
	{
		m_vx += 4.0f;
		m_posture = 0;
		m_ani_time += 1;
		m_footsteps_switching = true; //�����I��
	}
	//��L�[�������蔻��Ɠ������Ă���ꍇ
	else if (Input::GetVKey('W') == true && m_hit_up == true)
	{
		m_vy = 0.0f;
		m_posture = 3;
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	//���L�[�������蔻��Ɠ������Ă���ꍇ
	else if (Input::GetVKey('A') == true && m_hit_right == true)
	{
		m_vx = 0.0f;
		m_posture = 1;
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	//���L�[�������蔻��Ɠ������Ă���ꍇ
	else if (Input::GetVKey('S') == true && m_hit_down == true)
	{
		m_vy = 0.0f;
		m_posture = 2;
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	//�E�L�[�������蔻��Ɠ������Ă���ꍇ
	else if (Input::GetVKey('D') == true && m_hit_left == true)
	{
		m_vx = 0.0f;
		m_posture = 0;
		m_ani_frame = 0;
		m_ani_time = 0;
	}


	//�L�[���͂������ꍇ
	else
	{
		m_ani_frame = 0; //�L�[���͂������ꍇ�͐Î~�t���[���ɂ���
		m_ani_time = 0;
		m_footsteps_co = 0;
		m_footsteps_switching = false; //�����I�t��
		m_hit_up = false;
		m_hit_down = false;
		m_hit_left = false;
		m_hit_right = false;
	}
	

	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}


	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//�������I���̎�
	if (m_footsteps_switching == true)
	{
		if (m_footsteps_co == 0)
		{
			float v = Audio::VolumeMaster(2);
			v = Audio::VolumeMaster((1.0 - v));

			Audio::Start(2);
			m_footsteps_co += 1;
		}

		if (m_footsteps_co == 9)
		{
			Audio::Stop(2);
			m_footsteps_co = 0;
		}
	}
	else
	{
		Audio::Stop(2);
	}


	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//��l�����X�e�[�W�̓����蔻��ɓ����������̏����i�S�X�e�[�W�Ή��j
	if (hit->CheckElementHit(ELEMENT_FIELD) == true)
	{

		//�E�L�[���������ꍇ
		if (Input::GetVKey('D') == true)
		{
			m_vx -= 4.0f;
			m_hit_left = true;
			m_hit_up = false;
			m_hit_right = false;
			m_hit_down = false;
		}

		//���L�[���������ꍇ
		if (Input::GetVKey('A') == true)
		{
			m_vx += 4.0f;
			m_hit_right = true;
			m_hit_up = false;
			m_hit_down = false;
			m_hit_left = false;
		}

		//���L�[���������ꍇ
		if (Input::GetVKey('S') == true)
		{
			m_vy -= 4.0f;
			m_hit_down = true;
			m_hit_up = false;
			m_hit_right = false;
			m_hit_left = false;
		}

		//��L�[���������ꍇ
		if (Input::GetVKey('W') == true)
		{
			m_vy += 4.0f;
			m_hit_up = true;
			m_hit_right = false;
			m_hit_down = false;
			m_hit_left = false;
		}

		//��E���L�[���������ꍇ
		if (Input::GetVKey('W') == true &&
			Input::GetVKey('A') == true)
		{
			m_vx = 0.0f;
			m_vy = 0.0f;
			m_hit_up = true;
			m_hit_right = true;
			m_hit_down = false;
			m_hit_left = false;
		}

		//��E�E�L�[���������ꍇ
		if (Input::GetVKey('W') == true &&
			Input::GetVKey('D') == true)
		{
			m_vx = 0.0f;
			m_vy = 0.0f;
			m_hit_up = true;
			m_hit_left = true;
			m_hit_right = false;
			m_hit_down = false;
		}

		//���E���L�[���������ꍇ
		if (Input::GetVKey('S') == true &&
			Input::GetVKey('A') == true)
		{
			m_vx = 0.0f;
			m_vy = 0.0f;
			m_hit_down = true;
			m_hit_right = true;
			m_hit_up = false;
			m_hit_left = false;
		}

		//���E�E�L�[���������ꍇ
		if (Input::GetVKey('S') == true &&
			Input::GetVKey('D') == true)
		{
			m_vx = 0.0f;
			m_vy = 0.0f;
			m_hit_down = true;
			m_hit_left = true;
			m_hit_up = false;
			m_hit_right = false;
		}


		
		//��l���Ə�Q�����ǂ̊p�x�œ������Ă��邩���ׂ�
		HIT_DATA** hit_data;
		hit_data = hit->SearchElementHit(ELEMENT_FIELD);


		float r = hit_data[0]->r;

		//�p�x�ŏ㉺���E�𔻒�
		if (r > 0 && r < 45 || r >= 315)
		{
		//�E
		m_hit_right = true;
		}
		else if (r >= 45 && r < 136)
		{
		//��
		m_hit_up = true;
		}
		else if (r >= 135 && r <= 225)
		{
		//��
		m_hit_left = true;
		}
		else if (r > 225 && r < 316)
		{
		//��
		m_hit_down = true;
		}



		if (m_hit_left == true)//���ɓ����蔻�肪�������ꍇ
		{
		m_vx = m_vx + 5.0f;
		}
		else if (m_hit_right == true)//�E�ɓ����蔻�肪�������ꍇ
		{
		m_vx = m_vx - 5.0f;
		}
		else if (m_hit_down == true)//���ɓ����蔻�肪�������ꍇ
		{
		m_vy = m_vy - 5.0f;
		}
		else if (m_hit_up == true)//��ɓ����蔻�肪�������ꍇ
		{
		m_vy = m_vy + 5.0f;
		}

		

	}

	//��ʈړ�
	//�L���ړ�
	//700�`800�ɂ����ƘL��3-3�ɂ���
	if (hx + 64.0f >800 == true && m_go_cox == 2 && m_go_coy == 2)
	{
		m_px = 110;
		m_py = hy;
		m_key_flag = false;
		m_go_cox = 3;
		m_go_coy = 2;
	}

	//0�`100�ɂ����ƘL��3-1�ɂ���
	if (hx < 0 == true && m_go_cox == 2 && m_go_coy == 2)
	{
		m_px = 690;
		m_py = hy;
		m_key_flag = false;
		m_go_cox = 1;
		m_go_coy = 2;
	}


	//0�`100�ɂ����ƘL��3-2�ɂ���
	if (hx < 0 == true && m_go_cox == 3 && m_go_coy == 2)
	{
		m_px = 690;
		m_py = hy;
		m_key_flag = false;
		m_go_cox = 2;
		m_go_coy = 2;
	}

	//�}�b�v�[�ɂ����ƘL��3-2�ɂ���
	if (hx + 64.0f >800 == true && m_go_cox == 1 && m_go_coy == 2)
	{
		//��l��
		m_px = 110;
		m_py = hy;
		//�G
		//g_enemy_x = 110;
		m_key_flag = false;
		m_go_cox = 2;
		m_go_coy = 2;
	}

	//�����ړ�
	
	//�ی���
	if (hy < 120  && m_go_cox == 3 && m_go_coy == 2)
	{
		m_px = 60;
		m_py = 250;
		m_go_cox = 3;
		m_go_coy = 1;
		return;
	}
	if (hy + 64.0f > 800 && m_go_cox == 3 && m_go_coy == 1)
	{
		m_px = 250;
		m_py = 250;
		m_go_cox = 3;
		m_go_coy = 2;
		return;
	}


	//���ɍs���Ɠ�K�E�ƒ�Ȏ�,�ƒ돀�����ɍs���B
	if (hy > 450 && m_go_cox == 1 && m_go_coy == 2)
	{
		//�ƒ�Ȏ�
		if (hx < 350 == true)
		{
			m_px = 650;
			m_py = 70;
			m_key_flag = false;
			m_go_cox = 1;
			m_go_coy = 3;
			return;
		}
		//�ƒ돀����
		if (hx > 450 == true)
		{
			m_px = 400;
			m_py = 70;
			m_key_flag = false;
			m_go_cox = 1;
			m_go_coy = 3;
			return;
		}
	}


	//�L��2-1�ɍs��(�����̃h�A)
	if (hy < 50 && hx < 100 && m_go_cox == 1 && m_go_coy == 3)
	{
		m_px = 50;
		m_py = 300;
		m_go_cox = 1;
		m_go_coy = 2;
		return;
	}

	//�L��2-1�ɍs��(�E���̃h�A)
	if (hy < 50 && hx > 700 && m_go_cox == 1 && m_go_coy == 3)
	{
		m_px = 500;
		m_py = 300;
		m_go_cox = 1;
		m_go_coy = 2;
		return;
	}

	//�E�ɍs���Ɠ�K�E�ƒ돀����
	if ((hy < 250 && hy > 192) && hx > 800 && m_go_cox == 1 
		&& m_go_coy == 3)
	{
		m_px = 10;
		m_py = 200;
		return;
	}

	//��ɍs���ƘL��2-1�ɍs��
	if (hy < 70 && m_go_cox == 1 && m_go_coy == 3)
	{
		m_px = 700;
		m_px = 300;
		m_go_cox = 1;
		m_go_coy = 2;
		return;
	}

	//���ɍs���Ɠ�K�E�ƒ�Ȏ��ɍs��
	if (hx < 10 && m_go_cox == 1 && m_go_coy == 3)
	{
		g_hero_x = 730;
		g_hero_y = 200;
		m_px = 730;
		m_py = 200;
		return;
	}


	//��ɍs���Ɠ�K�E�}�����ɍs��
	if (hy < 100 == true && m_go_cox == 1 && m_go_coy == 2)
	{
		m_px = 100;
		m_py = 60;
		m_key_flag = false;
		m_go_cox = 1;
		m_go_coy = 1;
	}
	
	//���ɍs���ƘL��2-1�ɏo��
	if (hy > 536 && hx > 0 && m_go_cox == 1 && m_go_coy == 1)
	{
		m_px = 220;
		m_py = 200;
		m_go_cox = 1;
		m_go_coy = 2;
		return;
	}

	//���̃h�A�ɍs���ƘL��2-3�ɏo��
	if (hy < 100 && hx < 50 && m_go_cox == 3 && m_go_coy == 3)
	{
		m_px = 60;
		m_py = 250;
		m_go_cox = 3;
		m_go_coy = 2;
	}

	//�E�̃h�A�ɍs���ƘL��2-3�ɏo��
	if (hy < 100 && hx > 650 && m_go_cox == 3 && m_go_coy == 3)
	{
		m_px = 650;
		m_py = 250;
		m_go_cox = 3;
		m_go_coy = 2;
	}


	//���ɍs����3�K�E��c���ɍs��
	if (hy > 450 == true && m_go_cox == 3 && m_go_coy == 2)
	{
		m_px = 650;
		m_py = 70;
		m_key_flag = false;
		m_go_cox = 3;
		m_go_coy = 3;
	}
		

	//�K�i�ړ�
	if (hy < 0.0f && m_go_cox == 2 
		&& Input::GetVKey(VK_RETURN) == true)
	{
		m_px = 450.0f;
		m_py = 200.0f;
		m_posture = 2;
	}


	//��ʊO�ɏo�Ȃ��悤�ɂ��鏈��
	if (m_px + 64.0f > 800.0f)
	{
		m_px = 800.0f - 64.0f;
	}
	if (m_py + 64.0f > 600.0f)
	{
		m_py = 600.0f - 64.0f;
	}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
	else if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}



	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	
	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_px + 16, m_py + 50);//���������V�����ʒu�i��l���̈ʒu�j���ɒu��������

	//�G�@�I�u�W�F�N�g�ƐڐG�������l���@�폜
	if (hit->CheckObjNameHit(OBJ_ENEMY) !=nullptr)
	{
    	this->SetStatus(false);    //���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);  //��l���@�����L����HitBox�ɍ폜����
    	Scene::SetScene(new CSceneGameOver());
	}
}



//�h���[

void CObjHero::Draw()
{
	int AniData[5] =
	{
		0,1,2,3,0,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu


	//d�i�E�j�����͂��ꂽ�Ƃ�
	if (m_posture == 0)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 128.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 192.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = (64.0f  *   m_posture) + m_px;
		dst.m_right = (64 - 64.0f  *   m_posture) + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//a�i���j�����͂��ꂽ�Ƃ�
	else if (m_posture == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 128.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 64.0f + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//s�i���j�����͂��ꂽ�Ƃ�
	else if (m_posture == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 64.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 64.0f + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	//w�i��j�����͂��ꂽ�Ƃ�
	else if (m_posture == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 192.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 256.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 64.0f + m_px;
		dst.m_bottom = 64.0f + m_py;
	}



	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}
