#include "title.h"

CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent,"Title", SCENE_ID::RESULT)
{
}

void CTitle::Initialize()
{
	m_BackGround.Create("data\\—§‚¿‚Æ‚é.png");
}

void CTitle::Update()
{
}

void CTitle::Draw()
{
	m_BackGround.Draw();
}

void CTitle::Finalize()
{
	m_BackGround.Delete();
}
