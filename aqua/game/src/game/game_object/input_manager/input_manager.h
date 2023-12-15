#pragma once
#include "aqua.h"

namespace GameInputManager
{
	/*
	*  @fn　　
	*　LやRなどは作品で使用しないため追加してません
	* 
	*  @brief ゲーム内で使用するボタン
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
	*  @brief      トリガー判定
	*
	*  @param[in]  key			キーID
	*  @param[in]  player_id    デバイスID
	*
	*  @return     入力状態
	*  @retval     true    押された瞬間
	*  @retval     false   押されていないか、押され続けている
	*/
	bool GameTrigger(GameKey key,aqua::controller::DEVICE_ID player_id);

	/*!
	*  @brief      リリース判定
	*
	*  @param[in]  key			キーID
	*  @param[in]  player_id    デバイスID
	*
	*  @return     入力状態
	*  @retval     true    離された瞬間
    *  @retval     false   押されていないか、押され続けている
	*/
	bool GameReleased(GameKey key, aqua::controller::DEVICE_ID player_id);
	
	/*!
	*  @brief      ボタン判定
	*
	*  @param[in]  key			キーID
	*  @param[in]  player_id    デバイスID
	*
	*  @return     入力状態
	*  @retval     true    押されている
	*  @retval     false   押されていない
	*/
	bool GameButton(GameKey key, aqua::controller::DEVICE_ID player_id);

	/*!
	*  @brief      水平入力
	*
	*  @param[in]  player_id    デバイスID
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