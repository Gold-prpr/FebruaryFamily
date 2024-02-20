#pragma once
#include "../effect.h"

class CSakuraEffect
	:public IEffect
{
public:
	//コンストラクタ
	CSakuraEffect(aqua::IGameObject* parent);

	//デストラクタ
	~CSakuraEffect() = default;

	//初期化
	void Initialize(const aqua::CVector2& position) override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//解放
	void Finalize() override;

private:

	aqua::CSprite	m_Sakura;	//桜

	int				m_angle;	//揺れ
};