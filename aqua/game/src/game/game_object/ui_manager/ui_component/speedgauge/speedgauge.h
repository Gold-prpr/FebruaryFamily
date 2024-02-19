#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"

class CSpeedGauge
	: public IUiComponent
{
public:
	//�R���X�g���N�^
	CSpeedGauge(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSpeedGauge() = default;

	//������
	void Initialize(const aqua::CVector2 & position)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	//�Q�[�W
	void Gauge(CPlayer* player);

	aqua::CSprite		m_1PGaugeBaseSprite;	//1P�Q�[�W�̉�
	aqua::CSprite		m_1PGaugeSprite;		//1P�Q�[�W
	aqua::CSprite		m_2PGaugeBaseSprite;	//2P�Q�[�W�̉�
	aqua::CSprite		m_2PGaugeSprite;		//2P�Q�[�W
private:

	CPlayer* m_pPlayer;
};