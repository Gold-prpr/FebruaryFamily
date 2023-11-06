#include "item_icon.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//コンストラクタ
CItemIcon::CItemIcon(aqua::IGameObject* parent)
	: IUiComponent(parent, "ItemIcon")
{
}

//初期化
void CItemIcon::Initialize(const aqua::CVector2& position)
{
	//プレイヤーの中身を読み込む
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//アイテムマネージャーの中身を読み込む
	m_pItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");

	IUiComponent::Initialize(position);

	m_1PItemIconSprite.position = m_Position + aqua::CVector2{ 70.0f, 70.0f };
	m_2PItemIconSprite.position = m_Position + aqua::CVector2{ 70.0f, 600.0f };
	IGameObject::Initialize();
}

//初期化
void CItemIcon::Update(void)
{
	//if (Button(m_pPlayer->GetDeviceID(), BUTTON_ID::RIGHT_SHOULDER))
	if (m_pPlayer->m_HitItemFlag == true)
	{

		if (m_pItemManager->m_1p_item_rand == 0)
		{
			SpeedUpIcon();
		}
		if (m_pItemManager->m_1p_item_rand == 1)
		{
			SpeedDownIcon();
		}
	}

	//if (Button(DEVICE_ID::P1, BUTTON_ID::RIGHT_SHOULDER))
	//{
	//    //スピードアップアイテムの場合
	//    if (m_pItemManager->m_1p_item_rand == 0)
	//    {
	//        m_1PItemIconSprite.Create("data\\speedup.png");

	//        /*SpeedUpIcon();*/
	//    }
	//    //スピードダウンアイテムの場合
	//    if (m_pItemManager->m_1p_item_rand == 1)
	//    {
	//        m_1PItemIconSprite.Create("data\\speeddown.png");

	//        /*SpeedDownIcon();*/
	//    }
	//}

	//if (Button(DEVICE_ID::P2, BUTTON_ID::RIGHT_SHOULDER))
	//{

	//    if (m_pItemManager->m_1p_item_rand == 0)
	//    {
	//        m_2PItemIconSprite.Create("data\\speedup.png");

	//        //SpeedUpIcon();
	//    }
	//    if (m_pItemManager->m_1p_item_rand == 1)
	//    {
	//        m_2PItemIconSprite.Create("data\\speeddown.png");

	//        //SpeedDownIcon();
	//    }
	//}
}

//描画
void CItemIcon::Draw(void)
{
	m_1PItemIconSprite.Draw();
	m_2PItemIconSprite.Draw();
}

//解放
void CItemIcon::Finalize(void)
{
	m_1PItemIconSprite.Delete();
	m_2PItemIconSprite.Delete();
}

//スピードアップアイテム
void CItemIcon::SpeedUpIcon(void)
{
	if (m_pPlayer->GetDeviceID() == DEVICE_ID::P1)
		m_1PItemIconSprite.Create("data\\speedup.png");
	else
		m_2PItemIconSprite.Create("data\\speedup.png");
}

//スピードダウンアイテム
void CItemIcon::SpeedDownIcon(void)
{
	if (m_pPlayer->GetDeviceID() == DEVICE_ID::P1)
		m_1PItemIconSprite.Create("data\\speeddown.png");
	else
		m_2PItemIconSprite.Create("data\\speeddown.png");
}
