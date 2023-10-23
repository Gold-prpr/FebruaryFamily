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
	m_ItemFrameSprite.Create("data\\frame.png");

    IGameObject::Initialize();
}

//�X�V
void CItemFrame::Update(void)
{
    m_ItemFrameSprite.position = m_Position;

    IGameObject::Update();
}

//�`��
void CItemFrame::Draw(void)
{
    m_ItemFrameSprite.Draw();

    IGameObject::Draw();
}

//���
void CItemFrame::Finalize(void)
{
    m_ItemFrameSprite.Delete();

    IGameObject::Finalize();
}
