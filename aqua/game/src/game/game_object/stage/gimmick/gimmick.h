#pragma once
#include "../gimmick/gimmick_id.h"

class CStage;
class CPlayer;
class CUnitManager;

class CGimmickAct :
	public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CGimmickAct(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CGimmickAct()override = default;

	//������
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