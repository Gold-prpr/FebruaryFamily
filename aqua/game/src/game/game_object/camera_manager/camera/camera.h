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
	//コンストラクタ
	CCamera(IGameObject* parent);

	//デストラクタ
	~CCamera() = default;

	//初期化
	void Initialize(aqua::CVector2 position, controller::DEVICE_ID id, aqua::CSurface& surface);

	//更新
	void Update()override;

	void Draw()override;

	void Finalize()override;

	//OffSetの取得
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