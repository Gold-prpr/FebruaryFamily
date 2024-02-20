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

	m_1PItemIconSprite.position = m_Position + aqua::CVector2{ 20.0f, 40.0f };
	m_2PItemIconSprite.position = m_Position + aqua::CVector2{ 20.0f, 580.0f };

	IUiComponent::Initialize(position);
	IGameObject::Initialize();
}

//初期化
void CItemIcon::Update(void)
{
	IGameObject::Update();
}

//描画
void CItemIcon::Draw(void)
{
	m_1PItemIconSprite.Draw();
	m_2PItemIconSprite.Draw();

	IGameObject::Draw();
}

//解放
void CItemIcon::Finalize(void)
{
	IGameObject::Finalize();
}

//プレイヤーがアイテムボックスに触れたら
void CItemIcon::Check(CPlayer* player)
{
	if (player->m_HitItemFlag == true)
	{
		if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 0)
		{
			if (player->GetDeviceID() == DEVICE_ID::P1)
				m_1PItemIconSprite.Create("data\\speeddown.png");
			else
				m_2PItemIconSprite.Create("data\\speeddown.png");
		}
		if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 1)
		{
			if (player->GetDeviceID() == DEVICE_ID::P1)
				m_1PItemIconSprite.Create("data\\Stan_Item.png");
			else
				m_2PItemIconSprite.Create("data\\Stan_Item.png");
		}
		if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 2)
		{
			if (player->GetDeviceID() == DEVICE_ID::P1)
				m_1PItemIconSprite.Create("data\\Black_Item.png");
			else
				m_2PItemIconSprite.Create("data\\Black_Item.png");
		}

		if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 3)
		{
			if (player->GetDeviceID() == DEVICE_ID::P1)
				m_1PItemIconSprite.Create("data\\speedup.png");
			else
				m_2PItemIconSprite.Create("data\\speedup.png");
		}	
		
		if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 4)
		{
			if (player->GetDeviceID() == DEVICE_ID::P1)
				m_1PItemIconSprite.Create("data\\reverse.png");
			else
				m_2PItemIconSprite.Create("data\\reverse.png");
		}

		player->AddItemSpeed(2.0f);
	}
	else
	{
		player->AddItemSpeed(0.0f);
	}
	
}

//プレイヤーがアイテム使ったら
void CItemIcon::DeleteItem(CPlayer* player)
{
	if (player->GetDeviceID() == DEVICE_ID::P1)
		m_1PItemIconSprite.Delete();
	else
		m_2PItemIconSprite.Delete();
}
