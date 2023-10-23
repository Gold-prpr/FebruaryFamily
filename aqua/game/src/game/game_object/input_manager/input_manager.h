#pragma once
#include "aqua.h"

namespace GameInput
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

	bool In(GameKey key,aqua::controller::DEVICE_ID player_id);

	bool Out(GameKey key, aqua::controller::DEVICE_ID player_id);

	bool Button(GameKey key, aqua::controller::DEVICE_ID player_id);

	float GetHorizotal(aqua::controller::DEVICE_ID player_id);

	float GetVertical(aqua::controller::DEVICE_ID player_id);

	void Updata();

	static const int m_key_max = (int)GameKey::MAX * (int)aqua::controller::DEVICE_ID::P2;

	static bool m_GameKey[m_key_max];
	static bool m_GameKeyPrev[m_key_max];

	static float m_GameHorizotal[(int)aqua::controller::DEVICE_ID::P2];

	static float m_GameVertical[(int)aqua::controller::DEVICE_ID::P2];
}