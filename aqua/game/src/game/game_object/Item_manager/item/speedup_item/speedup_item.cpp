#include "speedup_item.h"

//コンストラクタ
CSpeedUpItem::CSpeedUpItem(aqua::IGameObject* parent)
	:IItem(parent,"SpeedUpItem")
{
}

//初期化
void CSpeedUpItem::Initialize(aqua::CVector2* position)
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//5秒間
	m_EffectTimer.Setup(5.0f);
	//アイテム使っていない状態
	m_itemflag = false;
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
	using namespace aqua::keyboard;

	//使ってない時は通常スピード
	if (m_itemflag == false)
		m_pPlayer->AddSpeed(1.0f);

	//押したらアイテム使用
	if (Trigger(KEY_ID::S))
		m_itemflag = true;

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
