
/*!
 *  @file       title_scene.cpp
 *  @brief      タイトルシーン
 *  @author     Kazuya Maruyama
 *  @date       2021/05/20
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "title_scene.h"
#include "..\..\scene_manager.h"

 /*
  *  コンストラクタ
  */
CTitleScene::
CTitleScene(aqua::IGameObject* parent)
    : IScene(parent, "TitleScene")
{
}

/*
 *  初期化
 */
void
CTitleScene::
Initialize(void)
{
    m_Chara = (CCharacter*)aqua::FindGameObject("Character");
    m_Stage = (CStage*)aqua::FindGameObject("Map");
    
    m_BackgourndSprite.Create("data\\background.png");
    m_BackgourndSprite.position = aqua::CVector2::ZERO;

	m_StartLabel.Create(40);
	m_StartLabel.position = aqua::CVector2((aqua::GetWindowWidth() / 2.0f) - 500, 880);
	m_StartLabel.text = "PLEASE PUSH ENTER";
	m_SLAlphaAngle = 0.0f;
}

/*
 *  更新
 */
void
CTitleScene::
Update(void)
{
    if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT) || aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::NUMPADENTER))
    {
        Change(SCENE_ID::GAMEMAIN);
    }

	// アルファ値の更新
	m_SLAlphaAngle += m_SLAlphaAngle < 360.0f ? 5.0f : -360.0f;
	m_StartLabel.color.alpha = (unsigned char)(abs(cos(aqua::DegToRad(m_SLAlphaAngle))) * 127.0f + 127.0f);
	
}

/*
 *  描画
 */
void
CTitleScene::
Draw(void)
{
    m_BackgourndSprite.Draw();
	m_StartLabel.Draw();
}

/*
 *  解放
 */
void
CTitleScene::
Finalize(void)
{
    m_BackgourndSprite.Delete();
	m_StartLabel.Delete();
}
