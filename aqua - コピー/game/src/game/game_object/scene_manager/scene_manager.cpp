#include "scene_manager.h"

CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"SceneManager")
	, m_SceneState(SCENE_STATE::SCENE_IN)
{
}

void CSceneManager::Initialize()
{

}

void CSceneManager::Update()
{

}

void CSceneManager::Draw()
{
}

void CSceneManager::Finalize()
{
}
