#pragma once
#include "../gimmick/gimmick_id.h"

class CStage;
class CPlayer;
class IUnit;

class CGimmickAct :
	public aqua::IGameObject
{
public:
	CGimmickAct(aqua::IGameObject* parent);

	~CGimmickAct()override = default;

	void Initialize()override;

	void DamageAct(CPlayer* player);

	void SlowAct(CPlayer* player);

	void JumpAct(CPlayer* player);

	
	
private:
	static const int alpha_cnt;
	static const int alpha_interval;

	int m_AlphaCurrCnt;
	int m_AlphaTimer;

	CStage* m_pStage;
	CPlayer* m_pPlayer;
	IUnit* m_pUnit;
};