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
	m_1PItemFrameSprite.Create("data\\frame.png");
	m_2PItemFrameSprite.Create("data\\frame.png");

}

//更新
void CItemFrame::Update(void)
{
}

//描画
void CItemFrame::Draw(void)
{
    m_1PItemFrameSprite.position = m_Position;
    m_2PItemFrameSprite.position = m_Position + aqua::CVector2{ 0.0f, 540.0f };

    m_1PItemFrameSprite.Draw();
    m_2PItemFrameSprite.Draw();
}

//解放
void CItemFrame::Finalize(void)
{
    m_1PItemFrameSprite.Delete();
    m_2PItemFrameSprite.Delete();
}
