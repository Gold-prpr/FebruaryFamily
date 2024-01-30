#include "speedup_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../ui_manager/ui_component/effect_icon/effect_icon.h"

//コンストラクタ
CSpeedUpItem::CSpeedUpItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedUpItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
	, m_pEffectIcon(nullptr)
{
}

//初期化
void CSpeedUpItem::Initialize(aqua::controller::DEVICE_ID other_id)
{
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_pEffectIcon = (CEffectIcon*)aqua::FindGameObject("EffectIcon");

	if (other_id == DEVICE_ID::P1)
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P1);
	else
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P2);

	//m_pSpeedDownEffect = (CSpeedDownEffect*)aqua::FindGameObject("SpeedDownEffect");

	//IItem::Initialize(position, "data\\speeddown.png");
	m_EffectTimer.Setup(8.0f);

	IGameObject::Initialize();
}

//更新
void CSpeedUpItem::Update()
{
	if (m_EffectTimer.Finished() && m_ItemFlag == true)
		if (m_pPlayer != nullptr)
		{
			m_pPlayer->max_interval = 40.0f;
			m_ItemFlag = false;
			if (m_pEffectIcon)
				m_pEffectIcon->DeleteEffect(m_pPlayer);
		}

	m_EffectTimer.Update();

	IGameObject::Update();
}

//加速
void CSpeedUpItem::SpeedUp()
{
	m_EffectTimer.Reset();

	m_ItemFlag = true;

	//アイテムを使っていたら
	if (m_pPlayer != nullptr)
		m_pPlayer->max_interval = 5.0f;
}
