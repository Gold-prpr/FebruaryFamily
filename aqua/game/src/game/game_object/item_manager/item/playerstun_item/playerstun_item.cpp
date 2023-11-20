#include "playerstun_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"

//�R���X�g���N�^
CCharaStunItem::CCharaStunItem(aqua::IGameObject* parent)
	: IItem(parent, "CharaStunItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
{
}

//������
void CCharaStunItem::Initialize(aqua::controller::DEVICE_ID other_id)
{
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	m_pPlayer = m_pUnitManager->GetPlayer(other_id);

	m_EffectTimer.Setup(2.0f);

	IGameObject::Initialize();
}

//�X�V
void CCharaStunItem::Update()
{
	if (m_EffectTimer.Finished())
		if (m_pPlayer != nullptr)
			m_pPlayer->AddSpeed(1.0f);

	m_EffectTimer.Update();

	IGameObject::Update();
}

//�L�����X�^��
void CCharaStunItem::CharaStun()
{
	//�A�C�e�����g���Ă�����
	if (m_pPlayer != nullptr)
		m_pPlayer->AddSpeed(0.0f);
}
