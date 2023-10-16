#include "result.h"

CResult::CResult(aqua::IGameObject* parent)
	:IScene(parent,"Result",SCENE_ID::TITLE,CHANGE_SCENE_ID::SLIDE_CLOSE)
{
}

void CResult::Initialize()
{
	m_BackGround.Create("data\\ƒŠƒUƒ‹ƒg.png");
}

void CResult::Update()
{
}

void CResult::Draw()
{
	m_BackGround.Draw();
}

void CResult::Finalize()
{
	m_BackGround.Delete();
}
