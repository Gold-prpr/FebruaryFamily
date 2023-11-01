#pragma once
#include "aqua.h"

class CTileManager;

class CStage : public aqua::IGameObject
{
public:

	CStage(aqua::IGameObject* parent);
	~CStage() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

	bool writing_flag;

private:

	static const float m_mouse_size;

	aqua::CSprite m_ForeGroudoSprite;

	aqua::CSprite m_MouseCorsorSprite;

	aqua::CSprite m_SelectModeSprite;

	aqua::CSprite m_DragSprite;

	CTileManager* m_TileManager;

	char buffer[MAX_PATH];

	bool m_SelectCreateMode;

};