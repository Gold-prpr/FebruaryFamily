#include "ui_manager.h"
#include "ui_component/item_frame/item_frame.h"
#include "ui_component/item_icon/item_icon.h"
#include "ui_component/rank_icon/rank_icon.h"
#include "ui_component/effect_icon/effect_icon.h"
#include "ui_component/stage_pos_bar/stage_pos_bar.h"
#include "ui_component/key_icon/key_icon.h"
#include "ui_component/dark/dark.h"
#include "ui_component/speedgauge/speedgauge.h"

const aqua::CVector2	CUiManager::m_ui_item_frame_position = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2	CUiManager::m_ui_item_icon_position = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2	CUiManager::m_ui_effect_icon_position = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2	CUiManager::m_ui_stage_bar_position = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2	CUiManager::m_ui_key_icon_position = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2	CUiManager::m_ui_rank_icon_position = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2	CUiManager::m_dark_position = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2	CUiManager::m_speedgauge_position = aqua::CVector2(0.0f, 0.0f);

CUiManager::CUiManager(aqua::IGameObject* parent)
	: aqua::IGameObject(parent, "UiManager")
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
	CDark* dark = aqua::CreateGameObject<CDark>(this);

	dark->Initialize(m_dark_position);

	CItemFrame* itemframe = aqua::CreateGameObject<CItemFrame>(this);

	itemframe->Initialize(m_ui_item_frame_position);

	CItemIcon* itemicon = aqua::CreateGameObject<CItemIcon>(this);

	itemicon->Initialize(m_ui_item_icon_position);

	CEffectIcon* effecticon = aqua::CreateGameObject<CEffectIcon>(this);

	effecticon->Initialize(m_ui_effect_icon_position);

	CStagePosBar* barpos = aqua::CreateGameObject<CStagePosBar>(this);

	barpos->Initialize(m_ui_stage_bar_position);

	CKeyIcon* keyicon = aqua::CreateGameObject<CKeyIcon>(this);

	keyicon->Initialize(m_ui_key_icon_position);

	CRankIcon* rankicon = aqua::CreateGameObject<CRankIcon>(this);

	rankicon->Initialize(m_ui_rank_icon_position);

	CSpeedGauge* speedgauge = aqua::CreateGameObject<CSpeedGauge>(this);

	speedgauge->Initialize(m_speedgauge_position);
}