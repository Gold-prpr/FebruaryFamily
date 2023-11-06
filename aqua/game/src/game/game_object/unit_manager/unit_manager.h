#pragma once
#include "aqua.h"
#include "unit/unit.h"

class CPlayer;
class CSlime;
class CStage;

class CUnitManager :public aqua::IGameObject
{
public:
	//コンストラクタ
	CUnitManager(aqua::IGameObject* parent);

	//デストラクタ
	~CUnitManager()override = default;

	//初期化
	virtual void Initialize()override;

	//更新
	virtual void Update() override;

	//描画
	virtual void Draw()override;

	//解放
	virtual void Finalize()override;

	CPlayer* GetPlayer(aqua::controller::DEVICE_ID player_device);

	//の生成と設置
	IUnit* CreateUnit(UNIT_ID unitid, aqua::CVector2 pos,DEVICE_ID device);

	IUnit* CreateEnemy(UNIT_ID unitid, aqua::CVector2 pos);

private:

	CStage* m_pStage;
};