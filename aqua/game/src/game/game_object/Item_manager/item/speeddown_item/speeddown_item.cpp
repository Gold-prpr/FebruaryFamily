#include "speeddown_item.h"

//コンストラクタ
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
{
}

//初期化
void CSpeedDownItem::Initialize(aqua::CVector2 position)
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

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
	//using namespace aqua::keyboard;

	//if (Trigger(KEY_ID::S))
	//{
	//	m_pPlayer->AddSpeed(0.8);
	//}
}
