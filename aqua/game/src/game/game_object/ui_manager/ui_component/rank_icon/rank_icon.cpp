#include "rank_icon.h"

//�R���X�g���N�^
CRankIcon::CRankIcon(aqua::IGameObject* parent)
	: IUiComponent(parent, "RankIcon")
{
}

//������
void CRankIcon::Initialize(const aqua::CVector2& position)
{
	IUiComponent::Initialize(position);

	m_1PRankIconSprite.Create("data\\first.png");
	m_2PRankIconSprite.Create("data\\second.png");

	m_1PRankIconSprite.position = m_Position + aqua::CVector2{ 0.0f, 340.0f };
	m_2PRankIconSprite.position = m_Position + aqua::CVector2{ 0.0f, 880.0f };

	IGameObject::Initialize();
}

//�X�V
void CRankIcon::Update(void)
{
	IGameObject::Update();
}

//�`��
void CRankIcon::Draw(void)
{
	m_1PRankIconSprite.Draw();
	m_2PRankIconSprite.Draw();

	IGameObject::Draw();
}

//���
void CRankIcon::Finalize(void)
{
	m_1PRankIconSprite.Delete();
	m_2PRankIconSprite.Delete();

	IGameObject::Finalize();
}
