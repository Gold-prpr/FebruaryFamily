#include "item_frame.h"

//コンストラクタ
CItemFrame::CItemFrame(aqua::IGameObject* parent)
    : IUiComponent(parent, "ItemFrame")
{
}

//初期化
void CItemFrame::Initialize(const aqua::CVector2& position)
{
    IUiComponent::Initialize(position);
	m_ItemFrameSprite.Create("data\\frame.png");

    IGameObject::Initialize();
}

//更新
void CItemFrame::Update(void)
{
    m_ItemFrameSprite.position = m_Position;

    IGameObject::Update();
}

//描画
void CItemFrame::Draw(void)
{
    m_ItemFrameSprite.Draw();

    IGameObject::Draw();
}

//解放
void CItemFrame::Finalize(void)
{
    m_ItemFrameSprite.Delete();

    IGameObject::Finalize();
}
