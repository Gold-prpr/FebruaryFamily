#include "game_main.h"
#include "../../../stage/stage.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../unit_manager/unit/enemy/slime/slime.h"
#include "../../../Item_manager/item_manager.h"
#include "../../../camera_manager/camera_manager.h"
#include "../../../stage/gimmick/gimmick.h"
#include "../../../ui_manager/ui_manager.h"
#include "../../../effect_manager/effect_manager.h"

CGameMain::CGameMain(aqua::IGameObject* parent)
	:IScene(parent, "GameMain", SCENE_ID::RESULT, CHANGE_SCENE_ID::FADE)
	, m_pUnitManager(nullptr)
{
}

void CGameMain::Initialize()
{
	IScene::Initialize();
	m_GameSoundClass->Play(SOUND_ID::GAME);

	aqua::CreateGameObject<CStage>(this);

	aqua::CreateGameObject<CItemManager>(this);
	m_pUnitManager = aqua::CreateGameObject<CUnitManager>(this);


	m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO, DEVICE_ID::P1);
	m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO, DEVICE_ID::P2);
	m_pUnitManager->CreateUnit(UNIT_ID::SLIME, aqua::CVector2::ZERO,DEVICE_ID::MAX);

	aqua::CreateGameObject<CGimmickAct>(this);

	m_pCameraManager = aqua::CreateGameObject<CCameraManager>(this);

	aqua::CreateGameObject<CUiManager>(this);
	
	//aqua::CreateGameObject<CEffectManager>(this);


	//m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	IScene::Initialize();
}

void CGameMain::Update()
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::L))
		m_ChangeSceneFlag = true;

	m_pPlayer = m_pUnitManager->GetPlayer(aqua::controller::DEVICE_ID::P1);
	if (m_pPlayer->m_GoalFlag == true)
		m_ChangeSceneFlag = true;
	m_pPlayer = m_pUnitManager->GetPlayer(aqua::controller::DEVICE_ID::P2);
	if (m_pPlayer->m_GoalFlag == true)
		m_ChangeSceneFlag = true;


	IScene::Update();
}

void CGameMain::Draw()
{
	m_pCameraManager->Draw();
	IScene::Draw();
}

void CGameMain::Finalize()
{
	m_GameSoundClass->Stop(SOUND_ID::GAME);
	IScene::Finalize();
}
