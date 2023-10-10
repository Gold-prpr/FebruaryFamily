#include "speedup_item.h"

//コンストラクタ
CSpeedUpItem::CSpeedUpItem(aqua::IGameObject* parent)
	:IItem(parent,"SpeedUpItem")
{
}

//初期化
void CSpeedUpItem::Initialize(aqua::CVector2 position)
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");
	m_EffectTimer.Setup(5.0f);
	IItem::Initialize(position, "data\\speedup.png");
}

//更新
void CSpeedUpItem::Update()
{
	SpeedUp();
}

//描画
void CSpeedUpItem::Draw()
{
	//IItem::Draw();
}

//解放
void CSpeedUpItem::Finalize()
{
	//IItem::Finalize();
}

//加速
void CSpeedUpItem::SpeedUp()
{
	//using namespace aqua::keyboard;

	//if (Trigger(KEY_ID::S))
	//{
	// 	m_EffectTimer.Update();
	//if (!m_EffectTimer.Finished())
	//	m_pPlayer->AddSpeed(1.5);
	//}


}
