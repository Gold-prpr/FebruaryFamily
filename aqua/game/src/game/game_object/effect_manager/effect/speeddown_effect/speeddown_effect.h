#pragma once
#include "../effect.h"

class CSpeedDownEffect : public IEffect
{
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

private:
	aqua::CSprite		m_Sprite;	//くらっているキャラの位置
	aqua::CTimer        m_Timer;	//くらっている時間
};