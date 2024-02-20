#include "dark_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../ui_manager/ui_component/effect_icon/effect_icon.h"
#include "../../../ui_manager/ui_component/dark/dark.h"

//�R���X�g���N�^
CDarkItem::CDarkItem(aqua::IGameObject* parent)
	: IItem(parent, "DarkItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
	, m_pEffectIcon(nullptr)
	, m_pDark(nullptr)
{
}

//������
void CDarkItem::Initialize(CPlayer* player)
{
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_pEffectIcon = (CEffectIcon*)aqua::FindGameObject("EffectIcon");

	m_pDark = (CDark*)aqua::FindGameObject("Dark");

	if (player->GetDeviceID() == DEVICE_ID::P1)
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P2);
	else
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P1);

	m_EffectTimer.Setup(5.0f);

	IGameObject::Initialize();
}

//�X�V
void CDarkItem::Update()
{
	if (m_EffectTimer.Finished() && m_ItemFlag == true)
		if (m_pPlayer != nullptr)
		{
			if (m_pEffectIcon)
				m_pEffectIcon->DeleteEffect(m_pPlayer);
			m_ItemFlag = false;

			m_pDark->m_1PDark.Delete();
			m_pDark->m_2PDark.Delete();

		}

	m_EffectTimer.Update();

	IGameObject::Update();
}

//�Â�����
void CDarkItem::Dark(CPlayer* player)
{
	m_EffectTimer.Reset();

	m_ItemFlag = true;

	m_pDark->Dark(player);
}