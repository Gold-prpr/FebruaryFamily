#include "speedup_item.h"

//コンストラクタ
CItemSpeedUp::CItemSpeedUp(aqua::IGameObject* parent)
	:IItem(parent, "SpeedUp")
{
}

//デストラクタ
CItemSpeedUp::~CItemSpeedUp(void)
{
}

//初期化
void CItemSpeedUp::Initialize(void)
{
	m_Speedup.Create("data\\speedup.png");

	m_Speedup.position = m_Position;
}