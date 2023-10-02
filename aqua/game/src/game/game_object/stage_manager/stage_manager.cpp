#include "stage_manager.h"
#include "stage/stage.h"

CStageManager::CStageManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "StageManager")
{
}

void CStageManager::Initialize(void)
{
	m_StagePos1P = aqua::CVector2(0,-540);
	m_StagePos2P = aqua::CVector2(0, 0);

	//aqua::CreateGameObject<CStage>(this)->Initialize(m_StagePos2P);
	aqua::CreateGameObject<CStage>(this)->Initialize(m_StagePos1P);
}
