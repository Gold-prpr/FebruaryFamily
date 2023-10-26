#include "select.h"

CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent,"Select",SCENE_ID::GAME,CHANGE_SCENE_ID::SLIDE_CLOSE)
{
}

void CSelect::Initialize()
{
	m_BackGround.Create("data\\ƒŠƒUƒ‹ƒg.png");
}

void CSelect::Update()
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
		m_ChangeSceneFlag = true;
}

void CSelect::Draw()
{
	m_BackGround.Draw();
}

void CSelect::Finalize()
{
	m_BackGround.Delete();
}
