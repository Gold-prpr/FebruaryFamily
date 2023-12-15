#include "speeddown_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../ui_manager/ui_component/effect_icon/effect_icon.h"
//#include "../../../effect_manager/effect_manager.h"
//#include "../../../effect_manager/effect/speeddown_effect/speeddown_effect.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//コンストラクタ
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
	, m_pEffectIcon(nullptr)
	//, m_pSpeedDownEffect(nullptr)
{
}

//初期化
void CSpeedDownItem::Initialize(aqua::controller::DEVICE_ID other_id)
{
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_pEffectIcon = (CEffectIcon*)aqua::FindGameObject("EffectIcon");

	if(other_id == DEVICE_ID::P1)
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P2);
	else
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P1);

	//m_pSpeedDownEffect = (CSpeedDownEffect*)aqua::FindGameObject("SpeedDownEffect");

	//IItem::Initialize(position, "data\\speeddown.png");
	m_EffectTimer.Setup(5.0f);
	
	IGameObject::Initialize();
}

//更新
void CSpeedDownItem::Update()
{
	/*SpeedDown();*/
	//アイテム効果時間が終わったら

	if (m_EffectTimer.Finished()&& m_ItemFlag ==true)
		if (m_pPlayer != nullptr)
		{
			m_pPlayer->AddEffectItemSpeed(1.0f);
			m_ItemFlag = false;
			if (m_pEffectIcon)
				m_pEffectIcon->DeleteEffect();
		}

	//m_pEffectIcon->m_1PEffectIconSprite.rect.top = m_pEffectIcon->m_1PEffectIconSprite.GetTextureHeight()*(1.0f-)

	m_EffectTimer.Update();
	
	IGameObject::Update();
}

//減速
void CSpeedDownItem::SpeedDown()
{
	m_EffectTimer.Reset();

	m_ItemFlag = true;

	//m_pEffectManager = (CEffectManager*)aqua::FindGameObject("EffectManager");
	//m_pEffectManager->Create(EFFECT_ID::SPEEDDOWN,m_pPlayer->m_Position);

	//アイテムを使っていたら
	if (m_pPlayer != nullptr)
		m_pPlayer->AddEffectItemSpeed(0.6f);
}