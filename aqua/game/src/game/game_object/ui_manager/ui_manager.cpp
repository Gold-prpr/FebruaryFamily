#include "ui_manager.h"
#include "ui_component/item_frame/item_frame.h"

const aqua::CVector2	CUiManager::m_ui_item_frame_position = aqua::CVector2(0.0f, 0.0f);

CUiManager::CUiManager(aqua::IGameObject* parent)
{
}

void CUiManager::Initialize(void)
{
	CItemFrame* itemframe = aqua::CreateGameObject<CItemFrame>(this);
	
	itemframe->Initialize(m_ui_item_frame_position);
}
