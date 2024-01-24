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
	static const float m_max_move_speed;
	static const aqua::CVector2 m_loser_position;

	aqua::CSprite m_BackGround;

	CCommonData* m_pCommonData;

	aqua::CLabel m_WinPlayerLabel;

	aqua::CSprite m_WinPlayerSprite;
	aqua::CSprite m_LosePlayerSprite;

	aqua::CSprite* m_ResultBeltSprite;

};
