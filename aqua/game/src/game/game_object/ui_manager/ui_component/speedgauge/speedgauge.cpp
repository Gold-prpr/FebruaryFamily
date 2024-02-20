#include "speedgauge.h"

//コンストラクタ
CSpeedGauge::CSpeedGauge(aqua::IGameObject* parent)
	: IUiComponent(parent, "SpeedGauge")
{
}


void CSpeedGauge::Initialize(const aqua::CVector2& position)
{
	//プレイヤーの中身を読み込む
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	m_1PGaugeBaseSprite.Create("data//speedgaugebase.png");
	m_2PGaugeBaseSprite.Create("data//speedgaugebase.png");

	m_1PGaugeSprite.Create("data//speedgauge.png");
	m_2PGaugeSprite.Create("data//speedgauge.png");

	IUiComponent::Initialize(position);

	m_1PGaugeBaseSprite.position = m_Position + aqua::CVector2{ 1400.0f, 490.0f };
	m_2PGaugeBaseSprite.position = m_Position + aqua::CVector2{ 1400.0f, 1030.0f };

	m_1PGaugeSprite.position = m_Position + aqua::CVector2{ 1400.0f, 490.0f };
	m_2PGaugeSprite.position = m_Position + aqua::CVector2{ 1400.0f, 1030.0f };

	
	IGameObject::Initialize();
}

//更新
void CSpeedGauge::Update(void)
{
	IGameObject::Update();
}

//描画
void CSpeedGauge::Draw(void)
{
	m_1PGaugeBaseSprite.Draw();
	m_2PGaugeBaseSprite.Draw();

	m_1PGaugeSprite.Draw();
	m_2PGaugeSprite.Draw();

	IGameObject::Draw();
}

//解放
void CSpeedGauge::Finalize(void)
{
	m_1PGaugeBaseSprite.Delete();
	m_2PGaugeBaseSprite.Delete();

	m_1PGaugeSprite.Delete();
	m_2PGaugeSprite.Delete();

	IGameObject::Finalize();
}

//ゲージ
void CSpeedGauge::Gauge(CPlayer* player)
{
	if (player->GetDeviceID() == DEVICE_ID::P1)
		m_1PGaugeSprite.rect.right = (m_1PGaugeSprite.GetTextureWidth() * (std::abs(player->m_Velocity.x) / player->GetMaxSpeed()));
	else
		m_2PGaugeSprite.rect.right = (m_2PGaugeSprite.GetTextureWidth() * (std::abs(player->m_Velocity.x) / player->GetMaxSpeed()));

}
