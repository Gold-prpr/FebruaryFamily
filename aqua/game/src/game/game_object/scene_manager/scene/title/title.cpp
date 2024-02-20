#include "title.h"

using namespace aqua::controller;

const int CTitle::m_effect_max_count = 3;
const int CTitle::m_frame_speed = 5;

CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent, "Title", SCENE_ID::SELECT, CHANGE_SCENE_ID::BLOCK_MOSAIC)
	, m_NowFrame(-3)
	, m_EffectCount(0)
{
}

void CTitle::Initialize()
{
	IScene::Initialize();
	m_GameSoundClass->Play(SOUND_ID::TITLE);

	m_RogoSprite.Create("data\\scene\\title\\ÉçÉS.png");

	m_RogoEffectSprite.Create("data\\scene\\title\\ÉçÉS.png");

	m_SceneChangeSprite.Create("data\\scene\\title\\scene_change.png");

	m_RogoEffectSprite.blend_mode = aqua::ALPHABLEND::ADD;
	m_RogoEffectSprite.color.alpha = (unsigned char)255;

	m_RogoEffectSprite.anchor.x = m_RogoEffectSprite.GetTextureWidth() / 2;
	m_RogoEffectSprite.anchor.y = m_RogoEffectSprite.GetTextureHeight() / 2;

}

void CTitle::Update()
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
		m_ChangeSceneFlag = true;
	if (aqua::controller::Trigger(aqua::controller::DEVICE_ID::P1, aqua::controller::BUTTON_ID::A) || aqua::controller::Trigger(aqua::controller::DEVICE_ID::P2, aqua::controller::BUTTON_ID::A))
		m_ChangeSceneFlag = true;

	if (m_EffectCount < m_effect_max_count)
	{
		if (m_NowFrame < 90 && m_NowFrame >= 0)
		{
			m_RogoEffectSprite.color.alpha = (unsigned char)(std::cos((float)m_NowFrame * DX_PI_F / 180.0f) * 255);

			float size = std::abs(std::sin((float)m_NowFrame * DX_PI_F / 180.0f) * 4) + 1;

			m_RogoEffectSprite.scale = aqua::CVector2::ONE * size;
			aqua::keyboard::KEY_ID;
		}
		else
		{
			m_NowFrame = 0;

			m_EffectCount++;

			m_RogoEffectSprite.color.alpha = (unsigned char)0;
		}

		m_NowFrame += m_frame_speed;

	}
	else
	{
		if (m_NowFrame < 180 && m_NowFrame >= 0)
		{
			m_SceneChangeSprite.color.alpha = (unsigned char)std::abs(std::cos((float)m_NowFrame * DX_PI_F / 180.0f) * 255);
		}
		else
		{
			m_NowFrame = 0;
		}

		m_NowFrame += m_frame_speed / 2;
	}

}

void CTitle::Draw()
{
	m_RogoSprite.Draw();

	if (m_RogoEffectSprite.color.alpha != (unsigned char)0)
		m_RogoEffectSprite.Draw();

	m_SceneChangeSprite.Draw();
}

void CTitle::Finalize()
{
	m_RogoSprite.Delete();

	m_RogoEffectSprite.Delete();

	m_SceneChangeSprite.Delete();

	m_GameSoundClass->Stop(SOUND_ID::TITLE);
}
