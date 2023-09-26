
/*!
 *  @file       title_scene.h
 *  @brief      タイトルシーン
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

class CCharacter;
class CStage;

/*!
 *  @class      CTitleScene
 *
 *  @brief      タイトルシーンクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/05/20
 *
 *  @version    1.0
 */
class CTitleScene
    : public IScene
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親のオブジェクト
     */
    CTitleScene(aqua::IGameObject* parent);

    /*!
     *  @brief      デストラクタ
     */
    ~CTitleScene(void) = default;

    /*!
     *  @brief      初期化
     */
    void        Initialize(void) override;

    /*!
     *  @brief      更新
     */
    void        Update(void) override;

    /*!
     *  @brief      描画
     */
    void        Draw(void) override;

    /*!
     *  @brief      解放
     */
    void        Finalize(void) override;

private:
    CCharacter* m_Chara;
    CStage* m_Stage;

    aqua::CSprite       m_BackgourndSprite;

	aqua::CLabel        m_StartLabel;           // "出陣"表示用ラベル
	float               m_SLAlphaAngle;         // アルファ値アニメーション用角度変数
};
