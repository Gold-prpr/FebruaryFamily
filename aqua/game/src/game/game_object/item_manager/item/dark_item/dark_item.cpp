#include "dark_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../ui_manager/ui_component/effect_icon/effect_icon.h"

//コンストラクタ
CDarkItem::CDarkItem(aqua::IGameObject* parent)
	: IItem(parent, "DarkItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
	, m_pEffectIcon(nullptr)
{
}

//初期化
void CDarkItem::Initialize(aqua::controller::DEVICE_ID other_id)
{
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_pEffectIcon = (CEffectIcon*)aqua::FindGameObject("EffectIcon");

	if (other_id == DEVICE_ID::P1)
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P2);
	else
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P1);

	m_EffectTimer.Setup(5.0f);

	m_1PDark.position = aqua::CVector2::ZERO;
	m_2PDark.position = aqua::CVector2(960.0f, 0.0f);

	m_1PDark.Create("data\\dark.png");


	IGameObject::Initialize();
}

//更新
void CDarkItem::Update()
{
	if (m_EffectTimer.Finished() && m_ItemFlag == true)
		if (m_pPlayer != nullptr)
		{
			m_ItemFlag = false;

			m_1PDark.Delete();
			m_2PDark.Delete();

			if (m_pEffectIcon)
				m_pEffectIcon->DeleteEffect(m_pPlayer);
		}

	m_EffectTimer.Update();

	IGameObject::Update();
}

//暗くする
void CDarkItem::Dark(aqua::controller::DEVICE_ID other_id)
{
	m_EffectTimer.Reset();

	m_ItemFlag = true;

	//アイテムを使っていたら
	if (other_id == DEVICE_ID::P1)
		m_2PDark.Create("data\\dark.png");
	else
		m_1PDark.Create("data\\dark.png");
}
