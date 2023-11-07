#pragma once
#include "../gimmick/gimmick_id.h"

class CStage;
class CPlayer;
class CUnitManager;

class CGimmickAct :
	public aqua::IGameObject
{
public:
	//コンストラクタ
	CGimmickAct(aqua::IGameObject* parent);

	//デストラクタ
	~CGimmickAct()override = default;

	//初期化
	void Initialize()override;

	void DamageAction(CPlayer* player);
	
private:
	static const int alpha_cnt;
	static const int alpha_interval;
	int m_AlphaCurrCnt;
	int m_AlphaTimer;

	CStage* m_pStage;
	CPlayer* m_pPlayer;
	CUnitManager* m_pUnitManager;
};