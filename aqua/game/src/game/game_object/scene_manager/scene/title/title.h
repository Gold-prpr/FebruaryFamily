#pragma once
#include "../scene.h"

class CGameSound;

class CTitle :
    public IScene
{
public:

	CTitle(aqua::IGameObject* parent);
	~CTitle() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:
	static const int m_effect_max_count;
	static const int m_frame_speed;

	aqua::CSprite			m_RogoSprite;
	aqua::CSprite			m_RogoEffectSprite;

	aqua::CSprite			m_SceneChangeSprite;

	int						m_NowFrame;
	int						m_EffectCount;

};