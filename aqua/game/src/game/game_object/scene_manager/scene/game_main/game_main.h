#pragma once
#include "../scene.h"

class CPlayer;
class CUnitManager;
class CStage;
class CCamera;
class CGimmick;

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

	CCamera* m_pCamera;
	CGimmick* m_pGimmick;

};
