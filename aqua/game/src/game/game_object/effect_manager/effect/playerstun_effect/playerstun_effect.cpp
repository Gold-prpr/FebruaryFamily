#include "playerstun_effect.h"
#include "../../../item_manager/item/playerstun_item/playerstun_item.h"

//�R���X�g���N�^
CPlayerStunEffect::CPlayerStunEffect(aqua::IGameObject* parent)
	:IEffect(parent, "PlayerStunEffect")
{
}

//������
void CPlayerStunEffect::Initialize(const aqua::CVector2& position)
{
	m_PlayerStunEffectSprite.Create("data\\player_1p.png");

	IEffect::Initialize(position);

	m_PlayerStunEffectSprite.anchor.x = m_PlayerStunEffectSprite.GetTextureWidth() / 2.0f;
	m_PlayerStunEffectSprite.anchor.y = m_PlayerStunEffectSprite.GetTextureHeight() / 2.0f;

	//����ʒu
	m_PlayerStunEffectSprite.position = m_Position;

	//������܂ł̎���
	m_PlayerStunEffectTimer.Setup(0.5f);

	//�F
	m_PlayerStunEffectSprite.blend_mode = aqua::ALPHABLEND::ADD;

	m_PlayerStunEffectSprite.color = aqua::CColor::YELLOW;

	IGameObject::Initialize();
}

//�X�V
void CPlayerStunEffect::Update(void)
{
	m_PlayerStunEffectTimer.Update();

	//�����鏈��
	if (m_PlayerStunEffectTimer.Finished())
	{/*
		DeleteObject();*/

		m_PlayerStunEffectTimer.SetTimer(m_PlayerStunEffectTimer.GetLimit());
	}

	//�����x
	m_PlayerStunEffectSprite.color.alpha = 255 - (int)(255.0f * m_PlayerStunEffectTimer.GetTime() / m_PlayerStunEffectTimer.GetLimit());

	if (m_PlayerStunEffectSprite.color.alpha == 0)
	{
		m_PlayerStunEffectTimer.Reset();
		//m_PlayerStunEffectSprite.position = m_Position;
	}

	m_pPlayerStunItem = (CPlayerStunItem*)aqua::FindGameObject("StunItem");

	if (m_pPlayerStunItem->m_ItemFlag == false)
	{
		DeleteObject();
	}

	IGameObject::Update();
}

//�`��
void CPlayerStunEffect::Draw(void)
{
	m_PlayerStunEffectSprite.Draw();

	IGameObject::Draw();
}

//���
void CPlayerStunEffect::Finalize(void)
{
	m_PlayerStunEffectSprite.Delete();

	IGameObject::Finalize();
}
