#include "reverse_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../ui_manager/ui_component/effect_icon/effect_icon.h"

//コンストラクタ
CReverseItem::CReverseItem(aqua::IGameObject* parent)
	:IItem(parent, "ReverseItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
	, m_pEffectIcon(nullptr)
{
}

//初期化
void CReverseItem::Initialize(aqua::controller::DEVICE_ID other_id)
{
	m_ReverseFlag = false;

	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_pEffectIcon = (CEffectIcon*)aqua::FindGameObject("EffectIcon");

	if (other_id == DEVICE_ID::P1)
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P2);
	else
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P1);

	m_EffectTimer.Setup(5.0f);

	IGameObject::Initialize();

}

//更新
void CReverseItem::Update()
{
	if (m_EffectTimer.Finished() && m_ItemFlag == true)
		if (m_pPlayer != nullptr)
		{
			m_ReverseFlag = false;

			m_ItemFlag = false;

			if (m_pEffectIcon)
				m_pEffectIcon->DeleteEffect(m_pPlayer);
		}

	m_EffectTimer.Update();

	IGameObject::Update();
}

//操作逆
void CReverseItem::Reverse()
{
	m_EffectTimer.Reset();

	m_ItemFlag = true;

	m_ReverseFlag = true;
}
