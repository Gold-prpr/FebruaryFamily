#pragma once

#include "effect/effect.h"
#include "effect/effect_id.h"

class CEffectManager : public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CEffectManager(aqua::IGameObject* parent);
	
	//�f�X�g���N�^
	~CEffectManager() = default;

	//����
	void Create(EFFECT_ID id, const aqua::CVector2& position);
};