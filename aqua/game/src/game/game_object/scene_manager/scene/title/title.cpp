#include "title.h"

using namespace aqua::controller;

const int CTitle::m_effect_max_count = 3;
const int CTitle::m_frame_speed = 5;
const float CTitle::m_max_title_timer = 20.0f;

CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent, "Title", SCENE_ID::SELECT, CHANGE_SCENE_ID::BLOCK_MOSAIC)
	, m_NowFrame(-3)
	, m_EffectCount(0)
	, m_VideoFlag(false)
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

	m_TitleTime.Setup(m_max_title_timer);

	m_RoopExplanatoryVideo.Create("data\\scene\\title\\ëÄçÏê‡ñæ.mp4");
}

void CTitle::Update()
{
	if (m_RoopExplanatoryVideo.Finished())
	{
		if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
			m_ChangeSceneFlag = true;

		if (aqua::controller::Trigger(aqua::controller::DEVICE_ID::P1, aqua::controller::BUTTON_ID::A) || aqua::controller::Trigger(aqua::controller::DEVICE_ID::P2, aqua::controller::BUTTON_ID::A))
			m_ChangeSceneFlag = true;
	}

	if (m_EffectCount < m_effect_max_count)
	{
		if (m_NowFrame < 90 && m_NowFrame >= 0)
		{
			m_RogoEffectSprite.color.alpha = (unsigned char)(std::cos((float)m_NowFrame * DX_PI_F / 180.0f) * 255);

			float size = std::abs(std::sin((float)m_NowFrame * DX_PI_F / 180.0f) * 4) + 1;

			m_RogoEffectSprite.scale = aqua::CVector2::ONE * size;

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

	if (m_TitleTime.Finished() && !m_VideoFlag)
	{
		m_RoopExplanatoryVideo.Play();
		m_VideoFlag = true;
		m_GameSoundClass->Stop(SOUND_ID::TITLE);

	}

	if (m_RoopExplanatoryVideo.Finished() && m_VideoFlag)
	{
		m_GameSoundClass->Play(SOUND_ID::TITLE);
		m_RoopExplanatoryVideo.Stop();
		m_TitleTime.Reset();
		m_VideoFlag = false;
		m_EffectCount = 0;
	}


	m_TitleTime.Update();

}

void CTitle::Draw()
{
	m_RogoSprite.Draw();

	if (m_RogoEffectSprite.color.alpha != (unsigned char)0)
		m_RogoEffectSprite.Draw();

	m_SceneChangeSprite.Draw();

	if (m_VideoFlag)
		m_RoopExplanatoryVideo.Draw();
}

void CTitle::Finalize()
{
	m_RogoSprite.Delete();

	m_RogoEffectSprite.Delete();

	m_SceneChangeSprite.Delete();

	m_RoopExplanatoryVideo.Delete();

	m_GameSoundClass->Stop(SOUND_ID::TITLE);
}
