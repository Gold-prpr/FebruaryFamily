#include "unit_manager.h"
#include "unit/unit.h"
#include "unit/player/player.h"
#include "../stage/stage.h"

CUnitManager::CUnitManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "UnitManager")
	, m_pStage(nullptr)
{
}

void CUnitManager::Initialize()
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	IGameObject::Initialize();
}

void CUnitManager::Update()
{
	if (!m_pStage)
		m_pStage = (CStage*)aqua::FindGameObject("Stage");

	IGameObject::Update();
}

void CUnitManager::Draw()
{
	IGameObject::Draw();
}

void CUnitManager::Finalize()
{
	IGameObject::Finalize();
}

CPlayer* CUnitManager::GetPlayer(aqua::controller::DEVICE_ID player_device)
{
	CPlayer* player = nullptr;

	auto child_it = m_ChildObjectList.begin();

	while (child_it != m_ChildObjectList.end())
	{
		if ((*child_it)->GetGameObjectName() == "Player")
		{
			DEVICE_ID id = ((CPlayer*)(*child_it))->GetDeviceID();

			if (id == player_device)
			{
				player = (CPlayer*)(*child_it);
				break;
			}
		}

		child_it++;
	}

	return player;
}

IUnit* CUnitManager::CreateUnit(UNIT_ID unitid, aqua::CVector2 pos,DEVICE_ID device)
{
	IUnit* unit = nullptr;
	switch (unitid)
	{
	case UNIT_ID::PLAYER: unit = aqua::CreateGameObject<CPlayer>(this); break;
	}

	if (!unit)return nullptr;
	unit->Initialize(pos,device);
	return unit;
}
