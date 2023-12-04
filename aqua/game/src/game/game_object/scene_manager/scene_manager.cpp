#include "scene_manager.h"
#include "scene/scene_channel.h"
#include "change_scene/change_scecne_channel.h"
#include "../common_data/common_data.h"

CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SceneManager")
	, m_SceneState(SCENE_STATE::UPDATE)
	, m_NextSceneID(SCENE_ID::TITLE)
	, m_NextChangeSceneID(CHANGE_SCENE_ID::SLIDE_CLOSE)
	, m_SceneClass(nullptr)
	, m_ChangeSceneClass(nullptr)
{
}

/*
*	������
*/
void CSceneManager::Initialize()
{
	aqua::CreateGameObject<CCommonData>(this);

	// �V�[���̐���
	CreateScene(m_NextSceneID);

	aqua::IGameObject::Initialize();
}

/*
*	�X�V
*/
void CSceneManager::Update()
{
	switch (m_SceneState)
	{
		// �V�[���ֈړ����
	case SCENE_STATE::SCENE_IN:

		// �V�[���̐���
		CreateScene(m_NextSceneID);

		if (m_ChangeSceneClass->In())
		{
			DeleteChildObject(&m_ChangeSceneClass,"ChangeScene");

			// ���̏�Ԃɐݒ�
			m_SceneState = SCENE_STATE::UPDATE;

		}

		break;

		// �X�V���
	case SCENE_STATE::UPDATE:

		if (m_SceneClass->GetChangeSceneFlag())
		{
			// ���̏�Ԃɐݒ�
			m_SceneState = SCENE_STATE::SCENE_OUT;

			// �V�[���J�ڂ̉��oID���擾
			m_NextChangeSceneID = m_SceneClass->GetNextChangeSceneID();
		}

		m_SceneClass->Update();

		break;

		// �V�[���J�ډ��o�ֈړ����
	case SCENE_STATE::SCENE_OUT:

		// ���̃V�[��ID���擾
		if (m_SceneClass)
			m_NextSceneID = m_SceneClass->GetNextSceneID();

		// �V�[���J�ڂ̉��o�𐶐�
		CreateChangeScene(m_NextChangeSceneID);

		if (m_ChangeSceneClass->Out())
		{
			m_SceneState = SCENE_STATE::SCENE_IN;

			DeleteChildObject(&m_SceneClass,"Scene");
		}

		break;
	}

	// �V�[���J�ډ��o�̍X�V
	if (m_ChangeSceneClass)
		m_ChangeSceneClass->Update();
}

/*
*	�`��
*/
void CSceneManager::Draw()
{
	if (m_SceneClass)
		m_SceneClass->Draw();

	if (m_ChangeSceneClass)
		m_ChangeSceneClass->Draw();
}

/*
*	���
*/
void CSceneManager::Finalize()
{
	DeleteChildObject(&m_SceneClass,"Scene");

	DeleteChildObject(&m_ChangeSceneClass,"ChangeScene");

	aqua::IGameObject::Finalize();
}

/*
*	�V�[���N���X�̐���
*/
void CSceneManager::CreateScene(SCENE_ID scene_id)
{
	if (m_SceneClass)return;

	switch (scene_id)
	{
	case SCENE_ID::TITLE:

		m_SceneClass = aqua::CreateGameObject<CTitle>(this);

		break;

	case SCENE_ID::SELECT:

		m_SceneClass = aqua::CreateGameObject<CSelect>(this);

		break;

	case SCENE_ID::GAME:

		m_SceneClass = aqua::CreateGameObject<CGameMain>(this);

		break;

	case SCENE_ID::RESULT:

		m_SceneClass = aqua::CreateGameObject<CResult>(this);

		break;
	}

	m_SceneClass->Initialize();
}

/*
*	�V�[���؂�ւ��N���X�̐���
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

	m_ChangeSceneClass->Initialize();
}