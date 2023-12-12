#include "effect_manager.h"
#include "effect/speeddown_effect/speeddown_effect.h"]
#include "effect/playerstun_effect/playerstun_effect.h"

//コンストラクタ
CEffectManager::CEffectManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "EffectManager")
{
}

void CEffectManager::Initialize()
{
	IGameObject::Initialize();
}

void CEffectManager::Update()
{
	IGameObject::Update();
}

void CEffectManager::Draw()
{
	IGameObject::Draw();
}

void CEffectManager::Finalize()
{
	IGameObject::Finalize();
}

//生成
void CEffectManager::Create(EFFECT_ID id, const aqua::CVector2& position)
{
	IEffect* effect = nullptr;

	switch (id)
	{
	case EFFECT_ID::SPEEDDOWN:		effect = aqua::CreateGameObject<CSpeedDownEffect>(this);
		break;
	case EFFECT_ID::PLAYERSTUN:		effect = aqua::CreateGameObject<CPlayerStunEffect>(this);
		break;
	default:
		break;
	}

	if (effect == nullptr) return;

	effect->Initialize(position);
}
