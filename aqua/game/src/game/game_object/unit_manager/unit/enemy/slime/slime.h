#pragma once
#include "../../unit.h"

class CSlime :public IUnit
{
public:
	CSlime(aqua::IGameObject* parent);
	~CSlime() = default;

	void Initialize(const aqua::CVector2& position)override;

	void Update()override;

	void Draw()override;

	void Finalize()override;

private:
	aqua::CAnimationSprite m_SlimeSprite;
	aqua::CVector2 m_Velocty;
	static const float m_width;
	static const float m_height;


};