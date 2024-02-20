#pragma once
#include "../effect.h"

class CSpeedDownItem;

class CSpeedDownEffect : public IEffect
{
public:
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
	aqua::CSprite		m_SpeedDownEffectSprite;	//������Ă���L�����̈ʒu
private:

	aqua::CTimer        m_SpeedDownEffectTimer;		//������Ă��鎞��

	CSpeedDownItem* m_pSpeedDownItem;
};