#include "item_frame.h"

//�R���X�g���N�^
CItemFrame::CItemFrame(aqua::IGameObject* parent)
    : IUiComponent(parent, "ItemFrame")
{
}

//������
void CItemFrame::Initialize(const aqua::CVector2& position)
{
    IUiComponent::Initialize(position);
    m_1PItemFrameSprite.Create("data\\frame.png");
    m_2PItemFrameSprite.Create("data\\frame.png");

    m_1PItemFrameSprite.position = m_Position;
    m_2PItemFrameSprite.position = m_Position + aqua::CVector2{ 0.0f, 540.0f };

    IGameObject::Initialize();
}

//�X�V
void CItemFrame::Update(void)
{
    IGameObject::Update();
}

//�`��
void CItemFrame::Draw(void)
{
    m_1PItemFrameSprite.Draw();
    m_2PItemFrameSprite.Draw();
    IGameObject::Draw();
}

//���
void CItemFrame::Finalize(void)
{
    m_1PItemFrameSprite.Delete();
    m_2PItemFrameSprite.Delete();
    IGameObject::Finalize();
}
