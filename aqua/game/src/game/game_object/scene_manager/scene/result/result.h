#pragma once
#include "../scene.h"

class CCommonData;

class CResult :
	public IScene
{
public:

	CResult(aqua::IGameObject* parent);
	~CResult() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:
	static const int m_max_belt_sprite;
	static const int m_max_rolling;
	static const int m_radian;
	static const float m_max_move_time;
	static const float m_fice_cool_time;
	static const aqua::CVector2 m_loser_position;

	aqua::CSprite m_BackGround;

	CCommonData* m_pCommonData;

	aqua::CLabel m_WinPlayerLabel;

	aqua::CAnimationSprite m_WinPlayerSprite;
	aqua::CAnimationSprite m_LosePlayerSprite;

	aqua::CSprite* m_ResultBeltSprite;

	aqua::CTimer m_MoveTimer;
	aqua::CTimer m_FiceCoolTimer;

	aqua::CVector2 m_SetPoition;

	bool m_EffectFlag;

};
