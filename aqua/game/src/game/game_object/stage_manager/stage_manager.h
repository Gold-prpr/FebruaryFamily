#pragma once
#include "aqua.h"

class CStage;

class CStageManager
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CStageManager(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CStageManager() = default;

	//������
	void Initialize(void);

private:
	aqua::CVector2 m_StagePos1P;
	aqua::CVector2 m_StagePos2P;

	CStage* m_pStage;
};