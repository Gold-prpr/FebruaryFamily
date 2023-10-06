#pragma once
#include "aqua.h"
#include "scene/scene_id.h"
#include "change_scene/change_scene_id.h"

enum class SCENE_STATE
{
	SCENE_IN,
	UPDATE,
	SCENE_OUT,
};

class IChangeScene;
class IScene;

class CSceneManager :public aqua::IGameObject
{
public:
	CSceneManager(aqua::IGameObject* parent);
	~CSceneManager() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:

	void CreateScene(SCENE_ID scene_id);

	void DeleteScene();

	void CreateChangeScene(CHANGE_SCENE_ID change_scene_id);

	void DeleteChangeScene();

private:

	SCENE_STATE m_SceneState;
	SCENE_ID    m_NextSceneID;

	IChangeScene*	m_ChangeSceneClass;
	IScene*			m_SceneClass;

	aqua::CSurface  m_SceneSurface;

};