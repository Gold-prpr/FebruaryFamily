#include "effect_icon.h"

//コンストラクタ
CEffectIcon::CEffectIcon(aqua::IGameObject* parent)
    : IUiComponent(parent, "EffectIcon")
{
}

//初期化
void CEffectIcon::Initialize(const aqua::CVector2& position)
{
	//プレイヤーの中身を読み込む
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//アイテムマネージャーの中身を読み込む
	m_pItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");

	m_1PEffectIconSprite.position = m_Position + aqua::CVector2{ aqua::GetWindowWidth() - 150.0f, 0.0f };
	m_2PEffectIconSprite.position = m_Position + aqua::CVector2{ aqua::GetWindowWidth() - 150.0f, aqua::GetWindowHeight() / 2.0f };

	IUiComponent::Initialize(position);
	IGameObject::Initialize();
}

//更新
void CEffectIcon::Update(void)
{
	IGameObject::Update();
}

//描画
void CEffectIcon::Draw(void)
{
	m_1PEffectIconSprite.Draw();
	m_2PEffectIconSprite.Draw();

	IGameObject::Draw();
}

//解放
void CEffectIcon::Finalize(void)
{
	IGameObject::Finalize();
}

//プレイヤーがアイテム使ったら
void CEffectIcon::EffectCheck(CPlayer* player)
{
	if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 0)
	{
		if (player->GetDeviceID() == DEVICE_ID::P1)
			m_2PEffectIconSprite.Create("data\\speeddown.png");
		else
			m_1PEffectIconSprite.Create("data\\speeddown.png");
	}
	 
	if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 1)
	{
		if (player->GetDeviceID() == DEVICE_ID::P1)
			m_2PEffectIconSprite.Create("data\\Stan_Item.png");
		else
			m_1PEffectIconSprite.Create("data\\Stan_Item.png");
	}

	if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 2)
	{
		if (player->GetDeviceID() == DEVICE_ID::P1)
			m_2PEffectIconSprite.Create("data\\Black_Item.png");
		else
			m_1PEffectIconSprite.Create("data\\Black_Item.png");
	}

	if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 3)
	{
		if (player->GetDeviceID() == DEVICE_ID::P1)
			m_1PEffectIconSprite.Create("data\\speedup.png");
		else
			m_2PEffectIconSprite.Create("data\\speedup.png");
	}

	if (m_pItemManager->m_ItemRand[(int)player->GetDeviceID()] == 4)
	{
		if (player->GetDeviceID() == DEVICE_ID::P1)
			m_2PEffectIconSprite.Create("data\\reverse.png");
		else
			m_1PEffectIconSprite.Create("data\\reverse.png");
	}
}


void CEffectIcon::DeleteEffect(CPlayer* player)
{
	if (player->GetDeviceID() == DEVICE_ID::P1)
		m_1PEffectIconSprite.Delete();
	else
		m_2PEffectIconSprite.Delete();
}
