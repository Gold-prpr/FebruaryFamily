#include "scene.h"

IScene::IScene(aqua::IGameObject* parent, std::string name,SCENE_ID next_scene,CHANGE_SCENE_ID next_change_scene)
	:aqua::IGameObject(parent,name,"Scene")
	, m_NextSceneID(next_scene)
	, m_NextChangeSceneID(next_change_scene)
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

CHANGE_SCENE_ID IScene::GetNextChangeSceneID()
{
	return m_NextChangeSceneID;
}
