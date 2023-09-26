
/*!
*  @file       game_main_scene.cpp
*  @brief      ゲームメインシーン
*  @author     Kazuya Maruyama
*  @date       2021/05/20
*  @version    1.0
*
*  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
*/

#include "game_main_scene.h"

/*
 *  コンストラクタ
 */
CGameMainScene::
CGameMainScene(aqua::IGameObject* parent)
	: IScene(parent, "GameMainScene")
{
}

/*
 *  初期化
 */
void
CGameMainScene::
Initialize(void)
{
	aqua::CreateGameObject<CCommonData>(this);
	m_Stage = (CStage*)aqua::CreateGameObject<CStage>(this); //aqua::FindGameObject("Map");
	m_Chara = (CCharacter*)aqua::CreateGameObject<CCharacter>(this); //aqua::FindGameObject("Character");
	item = (CItem*)aqua::CreateGameObject<CItem>(this);
	m_Enemy = (CEnemyManager*)aqua::CreateGameObject<CEnemyManager>(this); //aqua::FindGameObject("EnemyManager");
	m_StageTimer = (CStageTimer * )aqua::CreateGameObject<CStageTimer>(this); //aqua::FindGameObject("StageTimer");
	
	m_State = GAME_MAIN_STATE::PLAY;

	m_Stage->Initialize();

	IGameObject::Initialize();
}

/*
 *  更新
 */
void
CGameMainScene::
Update(void)
{
	if (m_StageTimer->m_stage_timer.Finished())
		m_State = GAME_MAIN_STATE::DEAD;

	switch (m_State)
	{
	case GAME_MAIN_STATE::PLAY:
		m_Enemy->Update();
		m_Chara->Update();
		break;
	case GAME_MAIN_STATE::GOAL:
		m_Stage->UpdateGoal();
		break;
	case GAME_MAIN_STATE::DEAD:
		m_Chara->GameOver();
		break;
	}

	IGameObject::Update();
}

void CGameMainScene::Draw(void)
{
	IGameObject::Draw();
}

void CGameMainScene::Finalize(void)
{
	IGameObject::Finalize();
}

void CGameMainScene::ChangeGameMainSteta(GAME_MAIN_STATE state)
{
	m_State = state;
}
