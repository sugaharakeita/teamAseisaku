//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHitBox.h"


//使用するネームスペース
using namespace GameL;


CObjHitBox::CObjHitBox(HitBoxs h)
{
	Hits::SetHitBox(this, h.pos_x, h.pos_y, h.height, h.width, ELEMENT_FIELD, OBJ_ROOM, 9);
}

