
/*!
 *  @file       game_main_scene.h
 *  @brief      �Q�[�����C���V�[��
 *  @author     Kazuya Maruyama
 *  @date       2021/05/20
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "..\scene.h"
#include "../../../character/character.h"
#include "../../../map/map.h"
#include "..\..\..\game_object.h"
#include "../../../stage_timer/stage_timer.h"
#include "../../../enemy_manager/enemy_manager.h"
#include "../../../item/item.h"
#include "../../../common_data/common_data.h"

class CCharacter;
class CStage;
class CStageTimer;
class CEnemyManager;
class CItem;

class CGameMainScene
	: public IScene
{
public:
	/*!
	 *  @brief      �R���X�g���N�^
	 *
	 *  @param[in]  parent  �e�̃I�u�W�F�N�g
	 */
	CGameMainScene(aqua::IGameObject* parent);

	/*!
	 *  @brief      �f�X�g���N�^
	 */
	~CGameMainScene(void) = default;

	/*!
	 *  @brief      ������
	 */
	void            Initialize(void) override;

	/*!
	 *  @brief      �X�V
	 */
	void            Update(void) override;

	void			Draw(void) override;

	void			Finalize(void)override;

	enum class		GAME_MAIN_STATE
	{
		PLAY,
		GOAL,
		DEAD,
	};
	
	void			ChangeGameMainSteta(GAME_MAIN_STATE state);

	GAME_MAIN_STATE   m_State;

private:
	
	aqua::CSprite               m_GroundSprite1;
	aqua::CSprite               m_GroundSprite2;

	

	aqua::CTimer m_stage_timer;

	CCharacter* m_Chara;
	CStage* m_Stage;
	CEnemyManager* m_Enemy;
	CStageTimer* m_StageTimer;
	CCommonData* data;
	CItem* item;
};

