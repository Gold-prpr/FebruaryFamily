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

    //IUiComponent::Initialize(position);
    //m_1PItemIconSprite.Create("data\\frame.png");
    //m_2PItemIconSprite.Create("data\\frame.png");
    //m_1PItemIconSprite.position = m_Position;
    //m_2PItemIconSprite.position = m_Position + aqua::CVector2{ 0.0f, 540.0f };
    //IGameObject::Initialize();
}

//初期化
void CItemIcon::Update(void)
{
    if (Button(m_pPlayer->m_Device, BUTTON_ID::LEFT_SHOULDER))
    {

        if (m_pItemManager->m_item_rand == 0)
        {
            SpeedUpIcon();
        }
        if (m_pItemManager->m_item_rand == 1)
        {
            SpeedDownIcon();
        }


    }
}

//描画
void CItemIcon::Draw(void)
{
}

//解放
void CItemIcon::Finalize(void)
{
}

//スピードアップアイテム
void CItemIcon::SpeedUpIcon(void)
{
}

//スピードダウンアイテム
void CItemIcon::SpeedDownIcon(void)
{
}
