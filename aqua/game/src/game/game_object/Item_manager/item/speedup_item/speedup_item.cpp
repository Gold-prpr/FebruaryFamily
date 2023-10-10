#include "speedup_item.h"

//�R���X�g���N�^
CSpeedUpItem::CSpeedUpItem(aqua::IGameObject* parent)
	:IItem(parent,"SpeedUpItem")
{
}

//������
void CSpeedUpItem::Initialize(aqua::CVector2 position)
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");
	m_EffectTimer.Setup(5.0f);
	IItem::Initialize(position, "data\\speedup.png");
}

//�X�V
void CSpeedUpItem::Update()
{
	SpeedUp();
}

//�`��
void CSpeedUpItem::Draw()
{
	//IItem::Draw();
}

//���
void CSpeedUpItem::Finalize()
{
	//IItem::Finalize();
}

//����
void CSpeedUpItem::SpeedUp()
{
	//using namespace aqua::keyboard;

	//if (Trigger(KEY_ID::S))
	//{
	// 	m_EffectTimer.Update();
	//if (!m_EffectTimer.Finished())
	//	m_pPlayer->AddSpeed(1.5);
	//}


}
