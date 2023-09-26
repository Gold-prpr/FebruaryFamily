
/*!
 *  @file       title_scene.h
 *  @brief      �^�C�g���V�[��
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
 *  @brief      �^�C�g���V�[���N���X
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
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent  �e�̃I�u�W�F�N�g
     */
    CTitleScene(aqua::IGameObject* parent);

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CTitleScene(void) = default;

    /*!
     *  @brief      ������
     */
    void        Initialize(void) override;

    /*!
     *  @brief      �X�V
     */
    void        Update(void) override;

    /*!
     *  @brief      �`��
     */
    void        Draw(void) override;

    /*!
     *  @brief      ���
     */
    void        Finalize(void) override;

private:
    CCharacter* m_Chara;
    CStage* m_Stage;

    aqua::CSprite       m_BackgourndSprite;

	aqua::CLabel        m_StartLabel;           // "�o�w"�\���p���x��
	float               m_SLAlphaAngle;         // �A���t�@�l�A�j���[�V�����p�p�x�ϐ�
};
