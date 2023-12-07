#pragma once
#include "aqua.h"

namespace controller = aqua::controller;

class CPlayer;
class CStage;
class CUnitManager;

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
	
	controller::DEVICE_ID m_PlayerID;

	CPlayer* m_pPlayer;
	CStage* m_pStage;
	CUnitManager* m_UnitManager;

	aqua::CSprite  m_SurfaceSprite;
	aqua::CVector2 m_Position;

};