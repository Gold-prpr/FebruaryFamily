
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
 *  コンストラクト
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
*  初期化
*/
void
CGame::
Initialize(void)

{
    aqua::CreateGameObject<CSceneManager>(this);

    IGameObject::Initialize();
}

/*
 *  更新
 */
void
CGame::
Update(void)
{
    IGameObject::Update();
}

/*
 *  描画
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
 *  解放
 */
void
CGame::
Finalize(void)
{
    IGameObject::Finalize();
}
