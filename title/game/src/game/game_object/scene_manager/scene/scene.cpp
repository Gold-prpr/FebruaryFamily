#include "scene.h"

IScene::IScene(aqua::IGameObject* parent, std::string name,SCENE_ID next_id)
	:aqua::IGameObject(parent,name,"Scene")
	, m_NextSceneID(next_id)
{
}

void IScene::Initialize()
{
}

void IScene::Update()
{
}

void IScene::Draw()
{
}

void IScene::Finalize()
{
}

SCENE_ID IScene::GetNextSceneID()
{
	return m_NextSceneID;
}
