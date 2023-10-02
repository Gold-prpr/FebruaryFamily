#pragma once
#include "aqua.h"

class CStage;

class CStageManager
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CStageManager(aqua::IGameObject* parent);
	//デストラクタ
	~CStageManager() = default;

	//初期化
	void Initialize(void);

private:
	aqua::CVector2 m_StagePos1P;
	aqua::CVector2 m_StagePos2P;

	CStage* m_pStage;
};