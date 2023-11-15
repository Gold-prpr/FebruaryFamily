#pragma once
#include "../effect.h"

class CSpeedDownEffect : public IEffect
{
	//�R���X�g���N�^
	CSpeedDownEffect(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSpeedDownEffect() = default;

	//������
	void Initialize(const aqua::CVector2& position) override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void) override;

	//���
	void Finalize(void) override;

private:
	aqua::CSprite		m_Sprite;	//������Ă���L�����̈ʒu
	aqua::CTimer        m_Timer;	//������Ă��鎞��
};