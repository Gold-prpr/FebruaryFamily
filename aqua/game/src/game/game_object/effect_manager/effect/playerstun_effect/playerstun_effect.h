#pragma once
#include "../effect.h"

class CPlayerStunItem;

class CPlayerStunEffect : public IEffect
{
public:
	//コンストラクタ
	CPlayerStunEffect(aqua::IGameObject* parent);

	//デストラクタ
	~CPlayerStunEffect() = default;

	//初期化
	void Initialize(const aqua::CVector2& position) override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void) override;

	//解放
	void Finalize(void) override;

	aqua::CSprite		m_PlayerStunEffectSprite;	//くらっているキャラの位置
private:
	aqua::CTimer        m_PlayerStunEffectTimer;	//くらっている時間

	CPlayerStunItem* m_pPlayerStunItem;
};