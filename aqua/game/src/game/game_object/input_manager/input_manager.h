#pragma once
#include "aqua.h"

namespace GameInputManager
{
	/*
	*  @fn�@�@
	*�@L��R�Ȃǂ͍�i�Ŏg�p���Ȃ����ߒǉ����Ă܂���
	* 
	*  @brief �Q�[�����Ŏg�p����{�^��
	*/
	enum class GameKey
	{
		A,
		B, 
		X, 
		Y, 
		MAX
	};

	/*!
	*  @brief      �g���K�[����
	*
	*  @param[in]  key			�L�[ID
	*  @param[in]  player_id    �f�o�C�XID
	*
	*  @return     ���͏��
	*  @retval     true    �����ꂽ�u��
	*  @retval     false   ������Ă��Ȃ����A�����ꑱ���Ă���
	*/
	bool GameTrigger(GameKey key,aqua::controller::DEVICE_ID player_id);

	/*!
	*  @brief      �����[�X����
	*
	*  @param[in]  key			�L�[ID
	*  @param[in]  player_id    �f�o�C�XID
	*
	*  @return     ���͏��
	*  @retval     true    �����ꂽ�u��
    *  @retval     false   ������Ă��Ȃ����A�����ꑱ���Ă���
	*/
	bool GameReleased(GameKey key, aqua::controller::DEVICE_ID player_id);
	
	/*!
	*  @brief      �{�^������
	*
	*  @param[in]  key			�L�[ID
	*  @param[in]  player_id    �f�o�C�XID
	*
	*  @return     ���͏��
	*  @retval     true    ������Ă���
	*  @retval     false   ������Ă��Ȃ�
	*/
	bool GameButton(GameKey key, aqua::controller::DEVICE_ID player_id);

	/*!
	*  @brief      ��������
	*
	*  @param[in]  player_id    �f�o�C�XID
	*/

	float GetHorizotal(aqua::controller::DEVICE_ID player_id);

	float GetVertical(aqua::controller::DEVICE_ID player_id);

	void Updata();

	static const int m_key_max = (int)GameKey::MAX * (int)aqua::controller::DEVICE_ID::P3;

	static bool m_GameKey[m_key_max];
	static bool m_GameKeyPrev[m_key_max];

	static float m_GameHorizotal[(int)aqua::controller::DEVICE_ID::P3];

	static float m_GameVertical[(int)aqua::controller::DEVICE_ID::P3];
}