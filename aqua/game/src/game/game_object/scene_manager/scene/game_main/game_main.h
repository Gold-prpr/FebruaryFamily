#pragma once
#include "../scene.h"

class CUnitManager;
class CPlayer;
class CCameraManager;
class CUiManager;

class CGameMain :
	public IScene
{
public:

	CGameMain(aqua::IGameObject* parent);
	~CGameMain() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:

	CUnitManager*		m_pUnitManager;
	CCameraManager*		m_pCameraManager;
	CPlayer* m_pPlayer;
	CUiManager* m_pUiManager;
};
