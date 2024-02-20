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
>>>>>>> origin/我、新世界之王　KAWAGISIN～母親のパンツを添えて～

class CCamera
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CCamera(IGameObject* parent);

	//�f�X�g���N�^
	~CCamera() = default;

	//������
	void Initialize(aqua::CVector2 position, controller::DEVICE_ID id, aqua::CSurface& surface);
	
	//�X�V
	void Update()override;

	void Draw()override;

	void Finalize()override;

	//OffSet�̎擾
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


>>>>>>> origin/我、新世界之王　KAWAGISIN～母親のパンツを添えて～
	controller::DEVICE_ID m_PlayerID;

	CPlayer* m_pPlayer;
	CStage* m_pStage;
	CUnitManager* m_UnitManager;

	aqua::CSprite  m_SurfaceSprite;
	aqua::CVector2 m_Position;

};