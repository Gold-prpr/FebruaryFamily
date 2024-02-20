#include "playerstun_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../effect_manager/effect_manager.h"
#include "../../../ui_manager/ui_component/effect_icon/effect_icon.h"
//#include "../../../effect_manager/effect/playerstun_effect/playerstun_effect.h"

//コンストラクタ
CPlayerStunItem::CPlayerStunItem(aqua::IGameObject* parent)
	: IItem(parent, "StunItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
	, m_pEffectIcon(nullptr)
	//, m_pPlayerStunEffect(nullptr)
{
}

//初期化
void CPlayerStunItem::Initialize(CPlayer* player)
{
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_pEffectIcon = (CEffectIcon*)aqua::FindGameObject("EffectIcon");

	//m_pPlayerStunEffect = (CPlayerStunEffect*)aqua::FindGameObject("PlayerStunEffect");

	if (player->GetDeviceID() == DEVICE_ID::P1)
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P2);
	else
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P1);

	m_EffectTimer.Setup(2.0f);

	IGameObject::Initialize();
}

//更新
void CPlayerStunItem::Update()
{
	if (m_EffectTimer.Finished() && m_ItemFlag == true)
		if (m_pPlayer != nullptr)
		{
			if (m_pEffectIcon)
				//m_pEffectIcon->DeleteEffect();
				m_pEffectIcon->DeleteEffect(m_pPlayer);
			m_pPlayer->AddEffectItemSpeed(1.0f);
			m_ItemFlag = false;
		}

	m_EffectTimer.Update();

	IGameObject::Update();
}

//キャラスタン
void CPlayerStunItem::PlayerStun()
{
	m_EffectTimer.Reset();

	m_ItemFlag = true;

	//m_pEffectManager = (CEffectManager*)aqua::FindGameObject("EffectManager");
	//m_pEffectManager->Create(EFFECT_ID::PLAYERSTUN, m_pPlayer->m_Position);

	//アイテムを使っていたら
	if (m_pPlayer != nullptr)
		m_pPlayer->AddEffectItemSpeed(0.0f);
}
