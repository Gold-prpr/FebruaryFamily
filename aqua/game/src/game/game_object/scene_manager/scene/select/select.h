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
	static const float m_max_scale;
	static const float m_min_scale;


	aqua::CSprite m_BackGround;

};
