#pragma once
#include "aqua.h"
#include "unit/unit.h"


class CStage;
class CUnitManager :public aqua::IGameObject
{
public:
	//コンストラクタ
	CUnitManager(aqua::IGameObject* parent);

	//デストラクタ
	~CUnitManager()override = default;

	//初期化
	void Initialize()override;

	//更新
	void Update() override;

	//描画
	void Draw()override;

	//解放
	void Finalize()override;

	//Unitの生成と設置
	IUnit* CreateUnit(UNIT_ID unitid, aqua::CVector2 pos);

private:

	CStage* m_pStage;
};