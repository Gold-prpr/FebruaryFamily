#pragma once
#include "aqua.h"

enum class SCENE_STATE
{
	SCENE_IN,
	UPDATE,
	SCENE_OUT,
};

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

	SCENE_STATE m_SceneState;

};