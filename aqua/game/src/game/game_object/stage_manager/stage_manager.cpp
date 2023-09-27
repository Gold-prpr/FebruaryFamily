#include "stage_manager.h"
#include "stage/stage.h"

CStageManager::CStageManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "StageManager")
{
}

void CStageManager::Initialize(const aqua::CVector2& map_1p_pos, const aqua::CVector2& map_2p_pos)
{
	aqua::CreateGameObject<CStage>(this)->Initialize(map_1p_pos);
	aqua::CreateGameObject<CStage>(this)->Initialize(map_2p_pos);
}
