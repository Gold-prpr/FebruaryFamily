#include "title.h"

using namespace aqua::controller;
using namespace aqua::keyboard;

CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent,"Title", SCENE_ID::GAME,CHANGE_SCENE_ID::BLOCK_MOSAIC)
{
}

void CTitle::Initialize()
{
	m_BackGround.Create("data\\scene\\title\\game_title_back(goal_flag)2.ass");
	m_BackGround.Change("wind");
	m_BackGround.Play();

	m_BackGround.scale = aqua::CVector2::ONE * 2.0f;
	m_BackGround.position.x = (aqua::GetWindowSize().x/2.0f - m_BackGround.GetFrameWidth()) / 2.0f;
}

void CTitle::Update()
{
	if(Trigger(KEY_ID::RETURN))
		m_ChangeSceneFlag = true;

	if (Trigger(DEVICE_ID::P1, BUTTON_ID::A) || Trigger(DEVICE_ID::P2, BUTTON_ID::A))
		m_ChangeSceneFlag = true;

	m_BackGround.Update();
	aqua::IGameObject::Update();
}

void CTitle::Draw()
{
	m_BackGround.Draw();
}

void CTitle::Finalize()
{
	m_BackGround.Delete();
}
