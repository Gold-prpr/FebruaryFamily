#pragma once
#include "../scene.h"

class CSelect :
	public IScene
{
public:

	CSelect(aqua::IGameObject* parent);
	~CSelect() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:

	aqua::CSprite m_BackGround;

};
