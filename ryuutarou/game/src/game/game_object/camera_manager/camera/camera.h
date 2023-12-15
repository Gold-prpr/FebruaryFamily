#pragma once
#include "aqua.h"

namespace controller = aqua::controller;

class CUnitManager;
class CItemManager;
class CGimmickAct;
class CPlayer;
class CStage;

class CCamera
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CCamera(IGameObject* parent);

	//�f�X�g���N�^
	~CCamera() = default;

	//������
	void Initialize(aqua::CVector2 position, controller::DEVICE_ID id);

	//�X�V
	void Update()override;

	void Draw()override;

	void Finalize()override;

	//OffSet�̎擾
	const aqua::CVector2& GetScroll();

private:

	aqua::CVector2 m_Scroll;
	
	CUnitManager*	m_UnitManager;
	CItemManager*	m_ItemManager;
	CGimmickAct*		m_Gimmick;
	CPlayer*		m_pPlayer;
	CStage*			m_pStage;

	controller::DEVICE_ID m_PlayerID;

	aqua::CSurface m_Surface;
	aqua::CSprite  m_SurfaceSprite;
	aqua::CVector2 m_Position;

};