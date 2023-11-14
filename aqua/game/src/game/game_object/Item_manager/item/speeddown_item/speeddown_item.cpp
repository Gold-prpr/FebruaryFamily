#include "speeddown_item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//コンストラクタ
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
{
}

//初期化
void CSpeedDownItem::Initialize()
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

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