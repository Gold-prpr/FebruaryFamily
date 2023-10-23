#include "input_manager.h"

bool GameInput::In(GameKey key, aqua::controller::DEVICE_ID player_id)
{
	int num = (int)key + (int)player_id * (int)GameKey::MAX;

	return m_GameKey[num] == !m_GameKeyPrev[num];
}

bool GameInput::Out(GameKey key, aqua::controller::DEVICE_ID player_id)
{
	int num = (int)key + (int)player_id * (int)GameKey::MAX;

	return !m_GameKey[num] == m_GameKeyPrev[num];
}

bool GameInput::Button(GameKey key, aqua::controller::DEVICE_ID player_id)
{
	return m_GameKey[(int)key + (int)player_id * (int)GameKey::MAX];
}

float GameInput::GetHorizotal(aqua::controller::DEVICE_ID player_id)
{
	return m_GameHorizotal[(int)player_id];
}

float GameInput::GetVertical(aqua::controller::DEVICE_ID player_id)
{
	return m_GameVertical[(int)player_id];
}

void GameInput::Updata()
{

	for (int i = 0; i < m_key_max; i++)
	{
		m_GameKeyPrev[i] = m_GameKey[i];
	}


	for (int j = 0; j < (int)aqua::controller::DEVICE_ID::P2; j++)
	{
		aqua::controller::DEVICE_ID id = (aqua::controller::DEVICE_ID)j;

		int key = (int)id * (int)GameKey::MAX;

		m_GameKey[(int)GameKey::A + key] =
			aqua::controller::Button(id, aqua::controller::BUTTON_ID::A);
		
		m_GameKey[(int)GameKey::B + key] =
			aqua::controller::Button(id, aqua::controller::BUTTON_ID::B);

		m_GameKey[(int)GameKey::X + key] =
			aqua::controller::Button(id, aqua::controller::BUTTON_ID::X);

		m_GameKey[(int)GameKey::Y + key] =
			aqua::controller::Button(id, aqua::controller::BUTTON_ID::Y);

		aqua::CVector2 key_stick;

		if (j)
		{
			key_stick.x = 
				aqua::keyboard::Button(aqua::keyboard::KEY_ID::D) -
				aqua::keyboard::Button(aqua::keyboard::KEY_ID::A);

			key_stick.y =
				aqua::keyboard::Button(aqua::keyboard::KEY_ID::S) -
				aqua::keyboard::Button(aqua::keyboard::KEY_ID::W);

			m_GameKey[(int)GameKey::A + key] |= aqua::mouse::Button(aqua::mouse::BUTTON_ID::RIGHT);
			m_GameKey[(int)GameKey::B + key] |= aqua::mouse::Button(aqua::mouse::BUTTON_ID::LEFT);
			m_GameKey[(int)GameKey::X + key] |= aqua::keyboard::Button(aqua::keyboard::KEY_ID::RETURN);
			m_GameKey[(int)GameKey::Y + key] |= aqua::keyboard::Button(aqua::keyboard::KEY_ID::RCONTROL);

		}
		else
		{
			key_stick.x =
				aqua::keyboard::Button(aqua::keyboard::KEY_ID::RIGHT) -
				aqua::keyboard::Button(aqua::keyboard::KEY_ID::LEFT);

			key_stick.y =
				aqua::keyboard::Button(aqua::keyboard::KEY_ID::DOWN) -
				aqua::keyboard::Button(aqua::keyboard::KEY_ID::UP);

			m_GameKey[(int)GameKey::A + key] |= aqua::keyboard::Button(aqua::keyboard::KEY_ID::SPACE);
			m_GameKey[(int)GameKey::B + key] |= aqua::keyboard::Button(aqua::keyboard::KEY_ID::Q);
			m_GameKey[(int)GameKey::X + key] |= aqua::keyboard::Button(aqua::keyboard::KEY_ID::E);
			m_GameKey[(int)GameKey::Y + key] |= aqua::keyboard::Button(aqua::keyboard::KEY_ID::LSHIFT);

		}

		m_GameHorizotal[j] = 
			aqua::controller::GetAnalogStickLeft(id).x ||
			key_stick.x;

		m_GameVertical[j] =
			aqua::controller::GetAnalogStickLeft(id).y ||
			key_stick.y;
	}
}
