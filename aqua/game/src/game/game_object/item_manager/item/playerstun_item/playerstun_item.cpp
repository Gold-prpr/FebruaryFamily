#include "playerstun_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"

//�R���X�g���N�^
CPlayerStunItem::CPlayerStunItem(aqua::IGameObject* parent)
	: IItem(parent, "StunItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
{
}

//������
void CPlayerStunItem::Initialize(aqua::controller::DEVICE_ID other_id)
{
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	if (other_id == DEVICE_ID::P1)
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P2);
	else
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P1);
	m_EffectTimer.Setup(2.0f);

	IGameObject::Initialize();
}

//�X�V
void CPlayerStunItem::Update()
{
	if (m_EffectTimer.Finished()&& m_ItemFlag ==true)
		if (m_pPlayer != nullptr)
		{
			m_pPlayer->AddItemSpeed(1.0f);
			m_ItemFlag = false;
		}

	m_EffectTimer.Update();

	IGameObject::Update();
}

//�L�����X�^��
void CPlayerStunItem::PlayerStun()
{
	m_EffectTimer.Reset();

	m_ItemFlag = true;

	//�A�C�e�����g���Ă�����
	if (m_pPlayer != nullptr)
		m_pPlayer->AddItemSpeed(0.0f);
}
