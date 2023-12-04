#include "rank_icon.h"

//コンストラクタ
CRankIcon::CRankIcon(aqua::IGameObject* parent)
	: IUiComponent(parent, "RankIcon")
{
}

//初期化
void CRankIcon::Initialize(const aqua::CVector2& position)
{
	IUiComponent::Initialize(position);

	m_1PRankIconSprite.Create("data\\first.png");
	m_2PRankIconSprite.Create("data\\second.png");

	m_1PRankIconSprite.position = m_Position + aqua::CVector2{ 0.0f, 340.0f };
	m_2PRankIconSprite.position = m_Position + aqua::CVector2{ 0.0f, 880.0f };

	IGameObject::Initialize();
}

//更新
void CRankIcon::Update(void)
{
	IGameObject::Update();
}

//描画
void CRankIcon::Draw(void)
{
	m_1PRankIconSprite.Draw();
	m_2PRankIconSprite.Draw();

	IGameObject::Draw();
}

//解放
void CRankIcon::Finalize(void)
{
	m_1PRankIconSprite.Delete();
	m_2PRankIconSprite.Delete();

	IGameObject::Finalize();
}
