#include "stage.h"
#include "stage_object/stage_object.h"
#include "../unit_manager/unit/unit.h"

const int CStage::map_chip_size = CStageObject::GetObjectSize();

const int CStage::num_chip_size_x = 5;
const int CStage::num_chip_size_y = 1;

const int CStage::all_num_chip = num_chip_size_x * num_chip_size_y;

const float CStage::m_gravity = 0.98f;

CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Stage")
{
}

void CStage::Initialize(void)
{
	//std::string file_name = "data\\scene\\game\\map_data7.csv";
	std::string file_name = "data\\scene\\game\\map_data11.csv";

	Parse(file_name);

	IGameObject::Initialize();
}

void CStage::Update(void)
{
	IGameObject::Update();
}

void CStage::Draw(void)
{
	m_BackGround.Draw();

	IGameObject::Draw();
}

void CStage::Finalize(void)
{
	m_BackGround.Delete();

	IGameObject::Finalize();
}

void CStage::SetScroll(aqua::CVector2 scroll)
{
	for (auto& stage_id : m_StageObject)
	{
		stage_id->SetAddPosition(scroll);
	}
}

void CStage::Parse(const std::string& file_name)
{
	aqua::CCSVLoader loader;

	loader.Load(file_name);

	int rows = loader.GetRows();

	if (loader.GetString(0, 0) != "")
		m_BackGround.Create(loader.GetString(0, 0));

	map_x = loader.GetInteger(0, 1);
	map_y = loader.GetInteger(0, 2);

	m_BackGround.scale.x = (float)(map_x * map_chip_size) / (float)aqua::GetWindowSize().x;
	m_BackGround.scale.y = (float)(map_y * map_chip_size * 2) / (float)aqua::GetWindowSize().y;

	for (int y = 1; y < rows; y++)
	{
		CStageObject* stage_object = nullptr;

		stage_object = aqua::CreateGameObject<CStageObject>(this);

		StageObjectID id = (StageObjectID)loader.GetInteger(y, 0);
		aqua::CVector2 pos = aqua::CVector2(loader.GetFloat(y, 1), loader.GetFloat(y, 2));

		stage_object->Create(id, pos);

		m_StageObject.push_back(stage_object);

	}

	loader.Unload();
}

float CStage::GetMapWidth(void)
{
	return (float)(map_chip_size * map_x);
}

float CStage::GetMapHeight(void)
{
	return (float)(map_chip_size * map_y);
}

float CStage::GetGravity(void)
{
	return m_gravity;
}

bool CStage::CheckHitObject(IUnit* unit)
{
#if 0
	for (auto& stage_it : m_StageObject)
	{
		aqua::CVector2 pos = stage_it->GetPosition();

		if (pos.x <= x && pos.x + map_chip_size > x &&
			pos.y <= y && pos.y + map_chip_size > y &&
			(int)stage_it->stage_object_id != (int)StageObjectID::AIR &&
			(int)stage_it->stage_object_id == (int)StageObjectID::GRASS1_TILE)
			return true;
	}

	return false;
#endif

	if (CheckObject(unit, StageObjectID::GRASS1_TILE) ||
		CheckObject(unit, StageObjectID::BRICK))
		return true;
}

bool CStage::CheckHitFloor(IUnit* unit)
{
	if (CheckFloor(unit, StageObjectID::GRASS1_TILE) ||
		CheckFloor(unit, StageObjectID::BRICK))
		return true;
}

int CStage::GetTileSize(void)
{
	return map_chip_size;
}

bool CStage::CheckGoal(IUnit* unit)
{
	return CheckObject(unit, StageObjectID::GOAL_FLAG);
}

bool CStage::CheckWire(IUnit* unit)
{
	return CheckObject(unit, StageObjectID::BARBED_WIRE);
}

bool CStage::CheckItem(IUnit* unit)
{
	return CheckObject(unit, StageObjectID::BOX);
}

bool CStage::CheckSpike(IUnit* unit)
{
	return CheckObject(unit, StageObjectID::SPIKE_BALL);
}

/*bool CStage::CheckObject_kari(int x, int y, StageObjectID id)
{
	if (m_pStage->CheckHit(nx, y)
		|| m_pStage->CheckHit(nx + w - 1, y)
		|| m_pStage->CheckHit(nx, y + h / 2)

		|| m_pStage->CheckHit(nx + w - 1, y + h / 2)
		|| m_pStage->CheckHit(nx, y + h - 1)
		|| m_pStage->CheckHit(nx + w - 1, y + h - 1))

	for (auto& stage_it : m_StageObject)
	{
		if (stage_it->CheckObject(x, y, id))
			return true;
	}
	return false;
}*/

bool CStage::CheckObject(IUnit* unit, StageObjectID id)
{
	for (auto& stage_it : m_StageObject)
	{
		if (stage_it->CheckObject(unit->nx, unit->y, id) ||
			stage_it->CheckObject(unit->nx + unit->w - 1, unit->y, id) ||
			stage_it->CheckObject(unit->nx, unit->y + unit->h / 2, id) ||
			stage_it->CheckObject(unit->nx + unit->w - 1, unit->y + unit->h / 2, id) ||
			stage_it->CheckObject(unit->nx, unit->y + unit->h - 1, id) ||
			stage_it->CheckObject(unit->nx + unit->w - 1, unit->y + unit->h - 1, id))
			return true;
	}
	return false;
}

bool CStage::CheckFloor(IUnit* unit, StageObjectID id)
{
	for (auto& stage_it : m_StageObject)
	{
		if (stage_it->CheckObject(unit->x, unit->ny, id) ||
			stage_it->CheckObject(unit->x + unit->w - 1, unit->ny, id) ||
			stage_it->CheckObject(unit->x, unit->ny + unit->h - 1, id) ||
			stage_it->CheckObject(unit->x + unit->w - 1, unit->ny + unit->h - 1, id))
			return true;
	}
	return false;
}
