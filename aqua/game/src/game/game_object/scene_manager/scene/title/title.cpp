#include "title.h"

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
