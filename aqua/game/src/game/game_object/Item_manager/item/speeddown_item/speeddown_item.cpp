#include "speeddown_item.h"

//�R���X�g���N�^
CItemSpeedDown::CItemSpeedDown(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDown")
{
}

//�f�X�g���N�^
CItemSpeedDown::~CItemSpeedDown(void)
{
}

//������
void CItemSpeedDown::Initialize(void)
{
	m_Speeddown.Create("data\\speeddown.png");

	m_Speeddown.position = m_Position;
}