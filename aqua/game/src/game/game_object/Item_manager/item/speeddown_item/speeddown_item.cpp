#include "speeddown_item.h"

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

	//アイテム使っていない状態
	m_itemflag = false;

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
		m_pPlayer->AddSpeed(0.8f);
	}

	//アイテム効果時間が終わったら
	if (m_EffectTimer.Finished())
		m_itemflag = false;

}
