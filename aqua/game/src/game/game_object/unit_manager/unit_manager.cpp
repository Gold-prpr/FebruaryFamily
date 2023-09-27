#include "unit_manager.h"

CUnitManager::CUnitManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"UnitManager")
{
}

void CUnitManager::Initialize()
{
	IGameObject::Initialize();
}

void CUnitManager::Update()
{
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

IUnit* CUnitManager::CreateUnit(UNIT_ID unitid, aqua::CVector2 pos)
{
	return nullptr;
}
