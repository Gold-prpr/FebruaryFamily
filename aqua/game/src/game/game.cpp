
/*!
 *  @file       game.cpp
 *  @brief      �Q�[���Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/06
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "game.h"
#include "game_object/game_object.h"

const unsigned int  CGame::m_clear_color = 0xff808080;

/*
 *  �R���X�g���N�^
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
*  ������
*/
void
CGame::
Initialize(void)

{
    aqua::CreateGameObject<CSceneManager>(this);

    IGameObject::Initialize();
}

/*
 *  �X�V
 */
void
CGame::
Update(void)
{
    IGameObject::Update();
}

/*
 *  �`��
 */
void
CGame::
Draw(void)
{
    // ��ʂ̃N���A
    aqua::Clear(m_clear_color);

    IGameObject::Draw();
}

/*
 *  ���
 */
void
CGame::
Finalize(void)
{
    IGameObject::Finalize();
}
