#include "scene.h"

IScene::IScene(aqua::IGameObject* parent, std::string name,SCENE_ID next_scene,CHANGE_SCENE_ID next_change_scene)
	:aqua::IGameObject(parent,name,"Scene")
	, m_ChangeSceneFlag(false)
	, m_NextSceneID(next_scene)
	, m_NextChangeSceneID(next_change_scene)
	, m_GameSoundClass(nullptr)
{
}

void IScene::Initialize()
{
	m_GameSoundClass = (CGameSound*)aqua::FindGameObject("GameSound");
	aqua::IGameObject::Initialize();
}

void IScene::Update()
{
	aqua::IGameObject::Update();
}

void IScene::Draw()
{
	aqua::IGameObject::Draw();
}

void IScene::Finalize()
{
	aqua::IGameObject::Finalize();
}

SCENE_ID IScene::GetNextSceneID()
{
	return m_NextSceneID;
}

CHANGE_SCENE_ID IScene::GetNextChangeSceneID()
{
	return m_NextChangeSceneID;
}

bool IScene::GetChangeSceneFlag()
{
	return m_ChangeSceneFlag;
}
