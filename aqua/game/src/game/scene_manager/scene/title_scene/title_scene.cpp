
/*!
 *  @file       title_scene.cpp
 *  @brief      �^�C�g���V�[��
 *  @author     Kazuya Maruyama
 *  @date       2021/05/20
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "title_scene.h"
#include "..\..\scene_manager.h"

 /*
  *  �R���X�g���N�^
  */
CTitleScene::
CTitleScene(aqua::IGameObject* parent)
    : IScene(parent, "TitleScene")
{
}

/*
 *  ������
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
 *  �X�V
 */
void
CTitleScene::
Update(void)
{
    if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT) || aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::NUMPADENTER))
    {
        Change(SCENE_ID::GAMEMAIN);
    }

	// �A���t�@�l�̍X�V
	m_SLAlphaAngle += m_SLAlphaAngle < 360.0f ? 5.0f : -360.0f;
	m_StartLabel.color.alpha = (unsigned char)(abs(cos(aqua::DegToRad(m_SLAlphaAngle))) * 127.0f + 127.0f);
	
}

/*
 *  �`��
 */
void
CTitleScene::
Draw(void)
{
    m_BackgourndSprite.Draw();
	m_StartLabel.Draw();
}

/*
 *  ���
 */
void
CTitleScene::
Finalize(void)
{
    m_BackgourndSprite.Delete();
	m_StartLabel.Delete();
}
