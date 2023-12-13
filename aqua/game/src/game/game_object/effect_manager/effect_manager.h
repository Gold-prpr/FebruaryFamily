#pragma once

#include "effect/effect.h"
#include "effect/effect_id.h"

class CEffectManager : public aqua::IGameObject
{
public:
	//コンストラクタ
	CEffectManager(aqua::IGameObject* parent);
	
	//デストラクタ
	~CEffectManager() = default;

	//生成
	void Create(EFFECT_ID id, const aqua::CVector2& position);
};