#include "ui_manager.h"
#include "ui_component/item_frame/item_frame.h"
#include "ui_component/item_icon/item_icon.h"
#include "ui_component/rank_icon/rank_icon.h"

const aqua::CVector2	CUiManager::m_ui_item_frame_position = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2	CUiManager::m_ui_item_icon_position = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2	CUiManager::m_ui_rank_icon_position = aqua::CVector2(0.0f, 0.0f);

CUiManager::CUiManager(aqua::IGameObject* parent)
{
}

void CUiManager::Initialize(void)
{
	Create();

	IGameObject::Initialize();
}

void CUiManager::Update(void)
{
	IGameObject::Update();
}

void CUiManager::Draw(void)
{
	IGameObject::Draw();
}

void CUiManager::Finalize(void)
{
	IGameObject::Finalize();
}

void CUiManager::Create(void)
{
	CItemFrame* itemframe = aqua::CreateGameObject<CItemFrame>(this);

	itemframe->Initialize(m_ui_item_frame_position);

	CItemIcon* itemicon = aqua::CreateGameObject<CItemIcon>(this);

	itemicon->Initialize(m_ui_item_icon_position);

	CRankIcon* rankicon = aqua::CreateGameObject<CRankIcon>(this);

	rankicon->Initialize(m_ui_rank_icon_position);
}
