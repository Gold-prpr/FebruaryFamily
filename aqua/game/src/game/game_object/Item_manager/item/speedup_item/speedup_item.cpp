#include "speedup_item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//コンストラクタ
CSpeedUpItem::CSpeedUpItem(aqua::IGameObject* parent)
	:IItem(parent,"SpeedUpItem")
{
}

//初期化
void CSpeedUpItem::Initialize() 
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//5秒間
	m_EffectTimer.Setup(5.0f);

	IItem::Initialize("data\\speedup.png");
}

//更新
void CSpeedUpItem::Update()
{
	SpeedUp();
}

//加速
void CSpeedUpItem::SpeedUp()
{
	//使ってない時は通常スピード
	if (m_itemflag == false)
		m_pPlayer->AddSpeed(1.0f);

	//アイテムを使っていたら
	if (m_itemflag == true)
	{
	 	m_EffectTimer.Update();
		m_pPlayer->AddSpeed(1.5f);
	}

	//アイテム効果時間が終わったら
	if (m_EffectTimer.Finished())
		m_itemflag = false;
}
