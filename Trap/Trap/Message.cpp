#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "Message.h"
#include "SwitchALL.h"

CObjMessage::CObjMessage(float x, float y)
{
	m_x = x;
	m_y = y;
}

CObjMessage::~CObjMessage()
{

}

void CObjMessage::Init()
{

}

void CObjMessage::Action()
{
	if (Message != 0 && Input::GetVKey(VK_BACK) == true)
		Message = 0;//バックキーが入力された場合に表示を消す。
}

void CObjMessage::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c2[4] = { 1.0f,0.2f,0.2f,1.0f };
	float c3[4] = { 0,0,0,1 };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 600.0f;
	src.m_bottom = 160.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 784.0f + m_x;
	dst.m_bottom = 128.0f + m_y;

	if (Text != 0 || Menu != 0)
		;//テキストもしくはメニューが開かれているなら部屋名を表示しない
	else//テキストもメニューも開かれていないなら、数字に応じて部屋名を表示する
	{
		if (room[0] == 1 || room[1] == 1 || room[2] == 1 || room[3] == 1)
			Font::StrDraw(L"１階廊下", 10, 16, 32, c2);
		else if (room[4] == 1)
			Font::StrDraw(L"校長室", 10, 16, 32, c2);
		else if (room[5] == 1)
			Font::StrDraw(L"職員室", 10, 16, 32, c2);
		else if (room[6] == 1)
			Font::StrDraw(L"保健室", 10, 16, 32, c2);
		else if(room[7] == 1 || room[8] == 1 || room[9] == 1)
			Font::StrDraw(L"２階廊下", 10, 16, 32, c2);
		else if (room[10] == 1)
			Font::StrDraw(L"家庭科室", 10, 16, 32, c2);
	}
	if (Message == 0)
		;//0なら何も表示しない。
	else//0でないなら数字に応じてメッセージを表示する
	{
		Draw::Draw(0, &src, &dst, c, 0.0f);//メッセージボックスを先に出す
		if (Message == 1)
		{
			Font::StrDraw(L"カギがかかっている…", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 2)
		{
			Font::StrDraw(L"校長室のカギを手に入れた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 3)
		{
			Font::StrDraw(L"箱は空っぽだ…", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 4)
		{
			Font::StrDraw(L"校長室のカギを開けた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 5)
		{
			Font::StrDraw(L"保健室のカギを手に入れた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 6)
		{
			Font::StrDraw(L"保健室のカギを開けた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 7)
		{
			Font::StrDraw(L"ハンマーを手に入れた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 8)
		{
			Font::StrDraw(L"不穏な気配がする！", m_x + 16, m_y + 16, 64, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 9)
		{
			Font::StrDraw(L"二宮金次郎の像は崩れ去った。", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 10)
		{
			Font::StrDraw(L"上の階に行けるようになったようだ…", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 11)
		{
			Font::StrDraw(L"図書室のカギを手に入れた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 12)
		{
			Font::StrDraw(L"図書室のカギを開けた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 13)
		{
			Font::StrDraw(L"家庭科室のカギを手に入れた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 14)
		{
			Font::StrDraw(L"家庭科室のカギを開けた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}
		else if (Message == 15)
		{
			Font::StrDraw(L"家庭科準備室のカギを開けた", m_x + 16, m_y + 16, 32, c3);
			Font::StrDraw(L"▼", 760, 560, 16, c3);
		}

	}
}