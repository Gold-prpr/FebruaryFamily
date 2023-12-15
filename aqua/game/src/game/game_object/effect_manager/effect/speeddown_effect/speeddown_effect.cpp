#include "speeddown_effect.h"

//�R���X�g���N�^
CSpeedDownEffect::CSpeedDownEffect(aqua::IGameObject* parent)
	:IEffect(parent, "SpeedDownEffect")
{
}

//������
void CSpeedDownEffect::Initialize(const aqua::CVector2& position)
{
	m_SpeedDownEffectSprite.Create("data\\player_1.png");

	IEffect::Initialize(position);

	m_SpeedDownEffectSprite.anchor.x = m_SpeedDownEffectSprite.GetTextureWidth() / 2.0f;
	m_SpeedDownEffectSprite.anchor.y = m_SpeedDownEffectSprite.GetTextureHeight() / 2.0f;

	//����ʒu
	m_SpeedDownEffectSprite.position = m_Position - m_SpeedDownEffectSprite.anchor;

	//������܂ł̎���
	m_SpeedDownEffectTimer.Setup(0.5f);

	//�F
	m_SpeedDownEffectSprite.blend_mode = aqua::ALPHABLEND::ADD;
}

//�X�V
void CSpeedDownEffect::Update(void)
{
	m_SpeedDownEffectTimer.Update();

	//�����鏈��
	if (m_SpeedDownEffectTimer.Finished())
	{
		DeleteObject();

		m_SpeedDownEffectTimer.SetTimer(m_SpeedDownEffectTimer.GetLimit());
	}

	//�����x
	m_SpeedDownEffectSprite.color.alpha = 255 - (int)(255.0f * m_SpeedDownEffectTimer.GetTime() / m_SpeedDownEffectTimer.GetLimit());

	//�G�t�F�N�g�ʒu
	//m_SpeedDownEffectSprite.position.x += 1.0f * aqua::GetDeltaTime();
	m_SpeedDownEffectSprite.scale += aqua::CVector2::ONE * aqua::GetDeltaTime();
}

//�`��
void CSpeedDownEffect::Draw(void)
{
	m_SpeedDownEffectSprite.Draw();
}

//���
void CSpeedDownEffect::Finalize(void)
{
	m_SpeedDownEffectSprite.Delete();
}
