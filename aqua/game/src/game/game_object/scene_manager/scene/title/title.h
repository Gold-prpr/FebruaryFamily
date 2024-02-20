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

	aqua::CSprite			m_RogoSprite;

};

