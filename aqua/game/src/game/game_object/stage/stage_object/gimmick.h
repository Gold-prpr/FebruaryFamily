#pragma once
#include "../stage_object/gimmick_id.h"

class CStage;
class CPlayer;

class CGimmick :
	public aqua::IGameObject
{
public:
	//コンストラクタ
	CGimmick(aqua::IGameObject* parent);

	//デストラクタ
	~CGimmick()override = default;

	//初期化
	void Initialize()override;

	void DamageAction(void);
	
private:
	static const int alpha_cnt;
	static const int alpha_interval;
	int m_AlphaCurrCnt;
	int m_AlphaTimer;

	int flame;

	CStage* m_pStage;
	CPlayer* m_pPlayer;
};