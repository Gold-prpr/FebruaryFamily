#include "playerstun_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"

//コンストラクタ
CPlayerStunItem::CPlayerStunItem(aqua::IGameObject* parent)
	: IItem(parent, "StunItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
{
}

//初期化
void CPlayerStunItem::Initialize(aqua::controller::DEVICE_ID other_id)
{
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	m_pPlayer = m_pUnitManager->GetPlayer(other_id);

	m_EffectTimer.Setup(2.0f);

	IGameObject::Initialize();
}

//更新
void CPlayerStunItem::Update()
{
	if (m_EffectTimer.Finished())
		if (m_pPlayer != nullptr)
			m_pPlayer->AddSpeed(1.0f);

	m_EffectTimer.Update();

	IGameObject::Update();
}

//キャラスタン
void CPlayerStunItem::PlayerStun()
{
	//アイテムを使っていたら
	if (m_pPlayer != nullptr)
		m_pPlayer->AddSpeed(0.0f);
}
