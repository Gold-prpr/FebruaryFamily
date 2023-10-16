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

	void CreateChangeScene(CHANGE_SCENE_ID change_scene_id);

	/*
	*	@brief 子オブジェクトから特定のクラスすべてを解放する
	* 
	*	@param[in] bc				基底クラス
	*	@param[in] category_name	カテゴリー名
	*/
	template<class BaseClass> void DeleteChildObject(BaseClass *bc,std::string category_name)
	{
		auto child_it = m_ChildObjectList.begin();

		while (child_it != m_ChildObjectList.end())
		{

			if ((*child_it)->GetGameObjectCategory() == category_name)
			{
				(*child_it)->Finalize();

				child_it = aqua::ListErase(&m_ChildObjectList,child_it);

				break;
			}

			if (child_it == m_ChildObjectList.end())
				break;

			child_it++;
		}

		*bc = nullptr;

	};

private:

	SCENE_STATE			m_SceneState;
	SCENE_ID			m_NextSceneID;
	CHANGE_SCENE_ID		m_NextChangeSceneID;

	IChangeScene*	m_ChangeSceneClass;
	IScene*			m_SceneClass;

	aqua::CSurface  m_SceneSurface;

};