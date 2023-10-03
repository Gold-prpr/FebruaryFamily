#include "scene_manager.h"
#include "scene/scene_channel.h"

CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SceneManager")
	, m_SceneState(SCENE_STATE::SCENE_IN)
	, m_NextSceneID(SCENE_ID::TITLE)
{
}

void CSceneManager::Initialize()
{

}

void CSceneManager::Update()
{
	switch (m_SceneState)
	{
	case SCENE_STATE::SCENE_IN:
		break;
	case SCENE_STATE::UPDATE:
		break;
	case SCENE_STATE::SCENE_OUT:
		break;
	}



	aqua::IGameObject::Update();
}

void CSceneManager::Draw()
{
	aqua::IGameObject::Draw();
}

void CSceneManager::Finalize()
{
	aqua::IGameObject::Finalize();
}

void CSceneManager::CreateScene(SCENE_ID scene_id)
{
	m_SceneClass = nullptr;

	switch (scene_id)
	{
	case SCENE_ID::TITLE:
		m_SceneClass = aqua::CreateGameObject<CTitle>(this);
		break;
	case SCENE_ID::RESULT:
		m_SceneClass = aqua::CreateGameObject<CResult>(this);
		break;

	}

	m_SceneClass->Initialize();
}
