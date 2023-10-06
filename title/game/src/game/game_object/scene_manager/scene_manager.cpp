#include "scene_manager.h"
#include "scene/scene_channel.h"
#include "change_scene/change_scecne_channel.h"

CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SceneManager")
	, m_SceneState(SCENE_STATE::UPDATE)
	, m_NextSceneID(SCENE_ID::TITLE)
	, m_SceneClass(nullptr)
	, m_ChangeSceneClass(nullptr)
{
}

void CSceneManager::Initialize()
{
	m_SceneSurface.Create(aqua::GetWindowWidth(), aqua::GetWindowHeight());

	CreateScene(m_NextSceneID);
}

void CSceneManager::Update()
{
	switch (m_SceneState)
	{
		// シーンへ移動状態
	case SCENE_STATE::SCENE_IN:

		// シーンの生成
		CreateScene(m_NextSceneID);

		if (m_ChangeSceneClass->In())
		{
			DeleteChangeScene();

			// 次の状態に設定
			m_SceneState = SCENE_STATE::UPDATE;
		}

		break;

		// 更新状態
	case SCENE_STATE::UPDATE:


		if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
		{
			// 次の状態に設定
			m_SceneState = SCENE_STATE::SCENE_OUT;

			// シーン遷移の演出IDを取得
			m_NextChangeSceneID = m_SceneClass->GetNextChangeSceneID();
		}
		m_SceneClass->Update();

		break;
		// シーン遷移演出へ移動状態
	case SCENE_STATE::SCENE_OUT:

		// 次のシーンIDを取得
		if (m_SceneClass)
			m_NextSceneID = m_SceneClass->GetNextSceneID();

		// シーン遷移の演出を生成
		CreateChangeScene(m_NextChangeSceneID);

		if (m_ChangeSceneClass->Out())
		{
			m_SceneState = SCENE_STATE::SCENE_IN;
			DeleteScene();

		}

		break;
	}

	// シーン遷移演出の更新
	if (m_ChangeSceneClass)
		m_ChangeSceneClass->Update();


	aqua::IGameObject::Update();
}

void CSceneManager::Draw()
{
	m_SceneSurface.Begin();

	if (m_SceneClass)
		m_SceneClass->Draw();

	m_SceneSurface.End();

	if (m_SceneClass)
		m_SceneClass->Draw();

	if (m_ChangeSceneClass)
		m_ChangeSceneClass->Draw();
}

void CSceneManager::Finalize()
{
	DeleteScene();

	DeleteChangeScene();

	aqua::IGameObject::Finalize();
}

/*
*
*/
void CSceneManager::CreateScene(SCENE_ID scene_id)
{
	if (m_SceneClass)return;

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

/*
*
*/
void CSceneManager::DeleteScene()
{
	if (!m_SceneClass)return;

	auto child_it = m_ChildObjectList.begin();

	while (child_it != m_ChildObjectList.end())
	{

		if ((*child_it)->GetGameObjectCategory() == "Scene")
		{
			((IScene*)(*child_it))->Finalize();

			child_it = aqua::ListErase(&m_ChildObjectList, child_it);
		}

		if (child_it == m_ChildObjectList.end())
			break;

		child_it++;
	}

	m_SceneClass = nullptr;
}

/*
*
*/
void CSceneManager::CreateChangeScene(CHANGE_SCENE_ID change_scene_id)
{
	if (m_ChangeSceneClass)return;

	switch (change_scene_id)
	{
	case CHANGE_SCENE_ID::FADE:

		m_ChangeSceneClass = (IChangeScene*)aqua::CreateGameObject<CFade>(this);

		break;

	case CHANGE_SCENE_ID::BLOCK_MOSAIC:

		m_ChangeSceneClass = (IChangeScene*)aqua::CreateGameObject<CBloackMosaic>(this);


		break;

	case CHANGE_SCENE_ID::SLIDE_CLOSE:

		m_ChangeSceneClass = (IChangeScene*)aqua::CreateGameObject<CSlideClose>(this);


		break;
	}

	m_ChangeSceneClass->CreateSprite(m_SceneSurface);

	m_ChangeSceneClass->Initialize();
}


/*
*
*/
void CSceneManager::DeleteChangeScene()
{
	if (!m_ChangeSceneClass)return;

	auto child_it = m_ChildObjectList.begin();

	while (child_it != m_ChildObjectList.end())
	{

		if ((*child_it)->GetGameObjectCategory() == "ChangeScene")
		{
			((IChangeScene*)(*child_it))->Finalize();

			child_it = aqua::ListErase(&m_ChildObjectList, child_it);

		}

		if (child_it == m_ChildObjectList.end())
			break;

		child_it++;
	}

	m_ChangeSceneClass = nullptr;
}
