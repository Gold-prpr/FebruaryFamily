#include "speeddown_item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//コンストラクタ
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
{
}

//初期化
void CSpeedDownItem::Initialize(aqua::CVector2* position)
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//5秒間
	m_EffectTimer.Setup(5.0f);

	IItem::Initialize(position, "data\\speeddown.png");
}

//更新
void CSpeedDownItem::Update()
{
	SpeedDown();
}

//描画
void CSpeedDownItem::Draw()
{
	//IItem::Draw();
}

//解放
void CSpeedDownItem::Finalize()
{
	//IItem::Finalize();
}

//減速
void CSpeedDownItem::SpeedDown()
{

	//アイテムを使っていたら

	m_EffectTimer.Update();
	m_pPlayer->AddSpeed(0.8f);

	//アイテム効果時間が終わったら
	if (m_EffectTimer.Finished())
		m_pPlayer->AddSpeed(1.0f);

}
