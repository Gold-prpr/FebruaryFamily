#pragma once
#include "aqua.h"

class CCamera;
class CUnitManager;
class CItemManager;
class CGimmickAct;
class CPlayer;
class CStage;

class CCameraManager
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CCameraManager(aqua::IGameObject* parent);

	//デストラクタ
	~CCameraManager(void) = default;

	//初期化
	void Initialize(void) override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void) override;

	//解放
	void Finalize(void) override;

	aqua::CVector2 GetScroll(aqua::controller::DEVICE_ID id);

private:

	std::vector<CCamera*> m_CameraClass;

	CUnitManager* m_UnitManager;
	CItemManager* m_ItemManager;
	CGimmickAct* m_Gimmick;
	CPlayer* m_pPlayer;
	CStage* m_pStage;

	aqua::CSurface m_Surface;
};