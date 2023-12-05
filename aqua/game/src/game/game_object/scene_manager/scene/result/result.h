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

	aqua::CSprite m_BackGround;

	CCommonData* m_pCommonData;

	aqua::CLabel m_WinPlayerLabel;

};
