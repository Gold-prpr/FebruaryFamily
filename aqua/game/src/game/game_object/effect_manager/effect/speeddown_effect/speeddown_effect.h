#pragma once
#include "../effect.h"

class CSpeedDownItem;

class CSpeedDownEffect : public IEffect
{
public:
	//コンストラクタ
	CSpeedDownEffect(aqua::IGameObject* parent);

	//デストラクタ
	~CSpeedDownEffect() = default;

	//初期化
	void Initialize(const aqua::CVector2& position) override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void) override;

	//解放
	void Finalize(void) override;
	aqua::CSprite		m_SpeedDownEffectSprite;	//くらっているキャラの位置
private:

	aqua::CTimer        m_SpeedDownEffectTimer;		//くらっている時間

	CSpeedDownItem* m_pSpeedDownItem;
};