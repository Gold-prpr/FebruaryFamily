#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"

class CSpeedGauge
	: public IUiComponent
{
public:
	//コンストラクタ
	CSpeedGauge(aqua::IGameObject* parent);

	//デストラクタ
	~CSpeedGauge() = default;

	//初期化
	void Initialize(const aqua::CVector2 & position)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	//ゲージ
	void Gauge(CPlayer* player);

	aqua::CSprite		m_1PGaugeBaseSprite;	//1Pゲージの下
	aqua::CSprite		m_1PGaugeSprite;		//1Pゲージ
	aqua::CSprite		m_2PGaugeBaseSprite;	//2Pゲージの下
	aqua::CSprite		m_2PGaugeSprite;		//2Pゲージ
private:

	CPlayer* m_pPlayer;
};