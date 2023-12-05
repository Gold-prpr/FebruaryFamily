#include"camera_manager.h"
#include "camera/camera.h"
#include "../unit_manager/unit/player/player.h"
#include "../unit_manager/unit_manager.h"
#include "../stage/stage.h"
#include "../stage/gimmick/gimmick.h"
#include "../Item_manager/item_manager.h"

CCameraManager::CCameraManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"CameraManager")
	, m_UnitManager(nullptr)
	, m_ItemManager(nullptr)
	, m_Gimmick(nullptr)
	, m_pStage(nullptr)
{
}

void CCameraManager::Initialize(void)
{
	m_UnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	m_ItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");
	m_Gimmick = (CGimmickAct*)aqua::FindGameObject("GimmickAct");
	m_pStage = (CStage*)aqua::FindGameObject("Stage");

	//m_Surface.Create((int)m_pStage->GetMapWidth(), (int)m_pStage->GetMapHeight());
	m_Surface.Create((int)aqua::GetWindowWidth(), (int)aqua::GetWindowHeight() / 2.0f);

	for (int i = 0; i <= (int)aqua::controller::DEVICE_ID::P2; i++)
	{
		m_CameraClass.push_back(aqua::CreateGameObject<CCamera>(this));
		
		m_CameraClass[i]->Initialize(aqua::CVector2(0, aqua::GetWindowSize().y / 2 * i), (aqua::controller::DEVICE_ID)i, m_Surface);
	}
}

void CCameraManager::Update(void)
{
	m_Surface.Create((int)aqua::GetWindowWidth(), (int)aqua::GetWindowHeight() / 2.0f);
	IGameObject::Update();
	m_Surface.Delete();
}

void CCameraManager::Draw(void)
{
	m_Surface.Begin();

	aqua::Clear(0xff808080);

	m_pStage->Draw();

	m_ItemManager->Draw();
	m_Gimmick->Draw();

	m_UnitManager->Draw();

	m_Surface.End();

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
