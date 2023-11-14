#include "speeddown_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//コンストラクタ
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
	,m_pUnitManager(nullptr)
{
}

//初期化
void CSpeedDownItem::Initialize(aqua::controller::DEVICE_ID other_id)
{
	m_pUnitManager->GetPlayer(other_id);

	//IItem::Initialize(position, "data\\speeddown.png");
	m_EffectTimer.Setup(5.0f);

	IGameObject::Initialize();
}

//更新
void CSpeedDownItem::Update()
{
	/*SpeedDown();*/
	IGameObject::Update();
}

//減速
void CSpeedDownItem::SpeedDown()
{
	//アイテムを使っていたら
	m_EffectTimer.Update();
	m_pPlayer->AddSpeed(0.6f);

	//アイテム効果時間が終わったら
	if (m_EffectTimer.Finished())
		m_pPlayer->AddSpeed(1.0f);

}