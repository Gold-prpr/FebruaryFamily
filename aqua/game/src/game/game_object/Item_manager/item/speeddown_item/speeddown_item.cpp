#include "speeddown_item.h"

//�R���X�g���N�^
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
{
}

//������
void CSpeedDownItem::Initialize(aqua::CVector2 position)
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	IItem::Initialize(position, "data\\speeddown.png");
}

//�X�V
void CSpeedDownItem::Update()
{
	SpeedDown();
}

//�`��
void CSpeedDownItem::Draw()
{
	//IItem::Draw();
}

//���
void CSpeedDownItem::Finalize()
{
	//IItem::Finalize();
}

//����
void CSpeedDownItem::SpeedDown()
{
	//using namespace aqua::keyboard;

	//if (Trigger(KEY_ID::S))
	//{
	//	m_pPlayer->AddSpeed(0.8);
	//}
}
