#include"camera_manager.h"
#include "camera/camera.h"

CCameraManager::CCameraManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"CameraManager")
{
}

void CCameraManager::Initialize(void)
{
	for (int i = 0; i <= (int)aqua::controller::DEVICE_ID::P2; i++)
	{
		m_CameraClass.push_back(aqua::CreateGameObject<CCamera>(this));
		
		m_CameraClass[i]->Initialize(aqua::CVector2(0, aqua::GetWindowSize().y / 2 * i), (aqua::controller::DEVICE_ID)i);
	}
}

void CCameraManager::Update(void)
{
	IGameObject::Update();
}

void CCameraManager::Draw(void)
{
	IGameObject::Draw();
}

void CCameraManager::Finalize(void)
{
	IGameObject::Finalize();
}

aqua::CVector2 CCameraManager::GetScroll(aqua::controller::DEVICE_ID id)
{
	return m_CameraClass[(int)id]->GetScroll();
}
