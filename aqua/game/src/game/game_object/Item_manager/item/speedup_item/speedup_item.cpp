#include "speedup_item.h"

//�R���X�g���N�^
CItemSpeedUp::CItemSpeedUp(aqua::IGameObject* parent)
	:IItem(parent, "SpeedUp")
{
}

//�f�X�g���N�^
CItemSpeedUp::~CItemSpeedUp(void)
{
}

//������
void CItemSpeedUp::Initialize(void)
{
	m_Speedup.Create("data\\speedup.png");

	m_Speedup.position = m_Position;
}