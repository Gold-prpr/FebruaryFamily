#include "select.h"

CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, "Select", SCENE_ID::SELECT, CHANGE_SCENE_ID::SLIDE_CLOSE)
{
}

void CSelect::Initialize()
{
}

void CSelect::Update()
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
		m_ChangeSceneFlag = true;
}

void CSelect::Draw()
{
}

void CSelect::Finalize()
{
}
