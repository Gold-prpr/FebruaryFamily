#include "speedgauge.h"

//�R���X�g���N�^
CSpeedGauge::CSpeedGauge(aqua::IGameObject* parent)
	: IUiComponent(parent, "SpeedGauge")
{
}


void CSpeedGauge::Initialize(const aqua::CVector2& position)
{
	//�v���C���[�̒��g��ǂݍ���
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	m_1PGaugeBaseSprite.Create("data//speedgaugebase.png");
	m_2PGaugeBaseSprite.Create("data//speedgaugebase.png");

	m_1PGaugeBaseSprite.position = m_Position + aqua::CVector2{ 1350.0f,490.0f };
	m_2PGaugeBaseSprite.position = m_Position + aqua::CVector2{ 1350.0f, 1030.0f };

	m_1PGaugeSprite.position = m_Position + aqua::CVector2{ 1350.0f,490.0f };
	m_2PGaugeSprite.position = m_Position + aqua::CVector2{ 1350.0f, 1030.0f };

	IUiComponent::Initialize(position);
	IGameObject::Initialize();
}

//�X�V
void CSpeedGauge::Update(void)
{
	IGameObject::Update();
}

//�`��
void CSpeedGauge::Draw(void)
{
	m_1PGaugeBaseSprite.Draw();
	m_2PGaugeBaseSprite.Draw();

	m_1PGaugeSprite.Draw();
	m_2PGaugeSprite.Draw();
}

//���
void CSpeedGauge::Finalize(void)
{
	m_1PGaugeBaseSprite.Delete();
	m_2PGaugeBaseSprite.Delete();

	m_1PGaugeSprite.Delete();
	m_2PGaugeSprite.Delete();
}

//�Q�[�W
void CSpeedGauge::Gauge(void)
{/*
	m_1PGaugeSprite.rect.right = (m_1PGaugeSprite.GetTextureWidth() * (1.0f - (m_pPlayer->m_Velocity.y / m_pPlayer->)));*/
}
