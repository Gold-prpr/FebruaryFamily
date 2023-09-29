#pragma once
#include "aqua.h"

class CStage : public aqua::IGameObject
{
public:

	CStage(aqua::IGameObject* parent);
	~CStage() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private :
	static const float m_mouse_size;

	aqua::CSprite m_ForeGroudoSprite;

	aqua::CSprite m_MouseCorsorSprite;

};