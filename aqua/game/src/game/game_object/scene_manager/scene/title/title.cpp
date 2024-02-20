#include "title.h"

using namespace aqua::controller;

CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent,"Title", SCENE_ID::SELECT,CHANGE_SCENE_ID::BLOCK_MOSAIC)
{
}

void CTitle::Initialize()
{
	IScene::Initialize();
	m_GameSoundClass->Play(SOUND_ID::TITLE);
<<<<<<< HEAD
	m_GameSoundClass->Play(SOUND_ID::TITLE);

	m_BackGround.Create("data\\scene\\title\\game_title_back(goal_flag)2.ass");
	m_BackGround.Change("wind");
	m_BackGround.Play();
=======
>>>>>>> origin/我、新世界之王　KAWAGISIN～母親のパンツを添えて～

	m_RogoSprite.Create("data\\scene\\title\\���S.png");

}

void CTitle::Update()
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
		m_ChangeSceneFlag = true;
	if (aqua::controller::Trigger(aqua::controller::DEVICE_ID::P1, aqua::controller::BUTTON_ID::A) || aqua::controller::Trigger(aqua::controller::DEVICE_ID::P2, aqua::controller::BUTTON_ID::A))
		m_ChangeSceneFlag = true;


<<<<<<< HEAD
	m_BackGround.Update();
=======
>>>>>>> origin/我、新世界之王　KAWAGISIN～母親のパンツを添えて～
}

void CTitle::Draw()
{
	m_RogoSprite.Draw();
}

void CTitle::Finalize()
{
	m_RogoSprite.Delete();

	m_GameSoundClass->Stop(SOUND_ID::TITLE);
}
