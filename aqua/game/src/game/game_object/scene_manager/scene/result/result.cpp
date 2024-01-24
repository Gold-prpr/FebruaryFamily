#include "result.h"
#include "../../../common_data/common_data.h"
#include "../../../effect_manager/effect_manager.h"

using namespace aqua::controller;

const int CResult::m_max_belt_sprite = 4;
const float CResult::m_max_move_speed = 7.5f;
const aqua::CVector2 CResult::m_loser_position{ 450.0f,300.0f };

CResult::CResult(aqua::IGameObject* parent)
	:IScene(parent, "Result", SCENE_ID::TITLE, CHANGE_SCENE_ID::SLIDE_CLOSE)
{
}

void CResult::Initialize()
{
	m_ResultBeltSprite = AQUA_NEW aqua::CSprite[m_max_belt_sprite];

	IScene::Initialize();
	m_GameSoundClass->Play(SOUND_ID::RESULT);

	m_pCommonData = (CCommonData*)aqua::FindGameObject("CommonData");

	int player = (int)(m_pCommonData->GetCommonDate().m_device_id) + 1;

	m_WinPlayerLabel.Create(100);
	m_WinPlayerLabel.text = "ÉvÉåÉCÉÑÅ[" + std::to_string(player) + "ÇÃèüÇøÇ≈Ç∑";
	m_WinPlayerLabel.position.x = (float)(aqua::GetWindowSize().x - m_WinPlayerLabel.GetTextWidth()) / 2.0f;
	m_WinPlayerLabel.position.y = (float)(aqua::GetWindowSize().x - m_WinPlayerLabel.GetFontHeight()) / 2.0f;

	if (m_pCommonData->GetCommonDate().m_device_id == aqua::controller::DEVICE_ID::P1)
	{
		m_WinPlayerSprite.Create("data//player_1p.png");
		m_LosePlayerSprite.Create("data//player_2p.png");
	}
	else
	{
		m_WinPlayerSprite.Create("data//player_2p.png");
		m_LosePlayerSprite.Create("data//player_1p.png");
	}
	m_WinPlayerSprite.scale = m_WinPlayerSprite.scale * 5.0f;
	m_WinPlayerSprite.position.x = (aqua::GetWindowWidth() / 2.0f - m_WinPlayerSprite.GetTextureWidth() / 2.0f);
	m_WinPlayerSprite.position.y = (aqua::GetWindowHeight() / 2.0f - m_WinPlayerSprite.GetTextureHeight() / 2.0f);

	m_LosePlayerSprite.position = m_loser_position;

	int center = (int)(m_max_belt_sprite / 2);

	m_BackGround.Create("data\\ç˜.png");

	for (int i = 0; i < m_max_belt_sprite; i++)
	{

		bool center_line = i / center;

		m_ResultBeltSprite[i].Create("data\\scene\\result\\belt.png");

		if (i % 2)
		{
			if (center_line)
				m_ResultBeltSprite[i].position.x = (float)aqua::GetWindowWidth() * -1.0f;
			else
				m_ResultBeltSprite[i].position.x = (float)aqua::GetWindowWidth();

		}

		if (center_line)
		{
			m_ResultBeltSprite[i].position.y = (float)(aqua::GetWindowHeight() - m_ResultBeltSprite[i].GetTextureHeight());
		}
	}

	aqua::CreateGameObject<CEffectManager>(this);

	IGameObject::Initialize();
}

void CResult::Update()
{
	CEffectManager* effect = (CEffectManager*)aqua::FindGameObject("EffectManager");
	effect->Create(EFFECT_ID::SAKURA, { 0,0 });

	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
		m_ChangeSceneFlag = true;

	if (Trigger(DEVICE_ID::P1, BUTTON_ID::A) || Trigger(DEVICE_ID::P2, BUTTON_ID::A))
		m_ChangeSceneFlag = true;

	for (int i = 0; i < m_max_belt_sprite; i++)
	{
		bool over_center_line = i / (int)(m_max_belt_sprite / 2);

		if (over_center_line)
		{
			m_ResultBeltSprite[i].position.x += m_max_move_speed;

			if (m_ResultBeltSprite[i].position.x >= (float)aqua::GetWindowWidth())
				m_ResultBeltSprite[i].position.x = (float)aqua::GetWindowWidth() * -1.0f;
		}
		else
		{
			m_ResultBeltSprite[i].position.x -= m_max_move_speed;

			if (m_ResultBeltSprite[i].position.x <= (float)aqua::GetWindowWidth() * -1.0f)
				m_ResultBeltSprite[i].position.x = (float)aqua::GetWindowWidth();
		}



	}

	IGameObject::Update();
}

void CResult::Draw()
{
	m_BackGround.Draw();

	m_WinPlayerLabel.Draw();

	m_LosePlayerSprite.Draw();
	m_WinPlayerSprite.Draw();

	for (int i = 0; i < m_max_belt_sprite; i++)
	{
		m_ResultBeltSprite[i].Draw();
	}

	IGameObject::Draw();
}

void CResult::Finalize()
{
	m_BackGround.Delete();

	m_LosePlayerSprite.Delete();
	m_WinPlayerSprite.Delete();

	m_GameSoundClass->Stop(SOUND_ID::RESULT);

	for (int i = 0; i < m_max_belt_sprite; i++)
	{
		m_ResultBeltSprite[i].Delete();
	}

	IGameObject::Finalize();
}
