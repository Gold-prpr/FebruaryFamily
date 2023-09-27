#include "unit_manager.h"
#include "unit/unit.h"
#include "unit/player/player.h"
#include "../stage/stage.h"

CUnitManager::CUnitManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"UnitManager")
	,m_pStage(nullptr)
{
}

void CUnitManager::Initialize()
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
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
	IUnit* unit = nullptr;
	switch (unitid)
	{
	case UNIT_ID::PLAYER: unit = aqua::CreateGameObject<CPlayer>(this);break;
	}

	if (!unit)return nullptr;
	unit->Initialize(pos);
	return unit;
}
