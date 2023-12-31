#pragma once
#include "../scene.h"

class CUnitManager;
class CCameraManager;
class CPlayer;

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
};
