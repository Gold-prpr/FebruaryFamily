#pragma once
#include "aqua.h"

namespace controller = aqua::controller;

class CPlayer;
class CStage;
<<<<<<< HEAD
class CUnitManager;
=======
class CEffectManager;
//class CSpeedDownEffect;
//class CPlayerStunEffect;
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½

class CCamera
	:public aqua::IGameObject
{
public:
	//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	CCamera(IGameObject* parent);

	//ƒfƒXƒgƒ‰ƒNƒ^
	~CCamera() = default;

	//‰Šú‰»
	void Initialize(aqua::CVector2 position, controller::DEVICE_ID id, aqua::CSurface& surface);
	
	//XV
	void Update()override;

	void Draw()override;

	void Finalize()override;

	//OffSet‚Ìæ“¾
	const aqua::CVector2& GetScroll();

private:

	aqua::CVector2 m_Scroll;
	
<<<<<<< HEAD
=======
	CUnitManager*	m_UnitManager;
	CItemManager*	m_ItemManager;
	CGimmickAct*		m_Gimmick;
	CPlayer*		m_pPlayer;
	CStage*			m_pStage;
	//CEffectManager* m_pEffectManager;


>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
	controller::DEVICE_ID m_PlayerID;

	CPlayer* m_pPlayer;
	CStage* m_pStage;
	CUnitManager* m_UnitManager;

	aqua::CSprite  m_SurfaceSprite;
	aqua::CVector2 m_Position;

};