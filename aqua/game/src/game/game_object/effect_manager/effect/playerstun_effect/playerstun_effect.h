#pragma once
#include "../effect.h"

class CPlayerStunItem;

class CPlayerStunEffect : public IEffect
{
public:
	//�R���X�g���N�^
	CPlayerStunEffect(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CPlayerStunEffect() = default;

	//������
	void Initialize(const aqua::CVector2& position) override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void) override;

	//���
	void Finalize(void) override;

	aqua::CSprite		m_PlayerStunEffectSprite;	//������Ă���L�����̈ʒu
private:
	aqua::CTimer        m_PlayerStunEffectTimer;	//������Ă��鎞��

	CPlayerStunItem* m_pPlayerStunItem;
};