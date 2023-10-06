#pragma once
#include "aqua.h"
#include "scene_id.h"
class IScene :public aqua::IGameObject
{
public:
	IScene(aqua::IGameObject* parent,std::string name,SCENE_ID next_id);
	~IScene() = default;

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Finalize()override;

	SCENE_ID	 GetNextSceneID();

private:

	SCENE_ID m_NextSceneID;

};