#pragma once
#include "aqua.h"
#include "scene_id.h"
#include "../change_scene/change_scene_id.h"

class IScene :public aqua::IGameObject
{
public:
	IScene(aqua::IGameObject* parent,std::string name,SCENE_ID next_scene,CHANGE_SCENE_ID next_change_scene);
	~IScene() = default;

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Finalize()override;

	SCENE_ID	 GetNextSceneID();
	CHANGE_SCENE_ID	 GetNextChangeSceneID();

private:

	SCENE_ID m_NextSceneID;
	CHANGE_SCENE_ID m_NextChangeSceneID;

};