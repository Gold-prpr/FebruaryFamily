#include "speeddown_item.h"

//コンストラクタ
CItemSpeedDown::CItemSpeedDown(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDown")
{
}

//デストラクタ
CItemSpeedDown::~CItemSpeedDown(void)
{
}

//初期化
void CItemSpeedDown::Initialize(void)
{
	m_Speeddown.Create("data\\speeddown.png");

	m_Speeddown.position = m_Position;
}