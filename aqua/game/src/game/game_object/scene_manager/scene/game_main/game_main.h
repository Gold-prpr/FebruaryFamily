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
	void CharaCameraPos(aqua::CSprite* cp, aqua::CVector2 pos);
	void Draw()override;
	void Finalize()override;

private:

	CPlayer* m_pFirstPlayer;
	CPlayer* m_pSecondPlayer;
	CUnitManager* m_pUnitManager;
	CStage* m_pStage;
	CCamera* m_pP1Camera;
	CCamera* m_pP2Camera;
	CGimmick* m_pGimmick;
	aqua::CSurface m_DivScreen;
	aqua::CSprite m_P1StageSprite;
	aqua::CSprite m_P2StageSprite;

};
