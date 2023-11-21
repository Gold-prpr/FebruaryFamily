#include "stage.h"
#include "stage_object/stage_object.h"
#include "../unit_manager/unit/unit.h"

const int CStage::map_chip_size = CStageObject::GetObjectSize();

const int CStage::num_chip_size_x = 5;
const int CStage::num_chip_size_y = 1;

const int CStage::all_num_chip = num_chip_size_x * num_chip_size_y;

const float CStage::m_gravity = 1.0f;

CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Stage")
{
}

void CStage::Initialize(void)
{
	std::string file_name = "data\\scene\\game\\map_data8.csv";

	m_GoalPos = aqua::CVector2::ZERO;

	Parse(file_name);

	IGameObject::Initialize();
}

void CStage::Update(void)
{
	CStageObject* stage_object = nullptr;
	stage_object = (CStageObject*)aqua::FindGameObject("StageObject");

	m_GoalPos = stage_object->GoalPos();

	if (m_GoalPos.x != 0.0f)
		int a = 1;

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

bool CStage::CheckObject(int x, int y, StageObjectID id)
{
	for (auto& stage_it : m_StageObject)
	{
		if (stage_it->CheckObject(x, y, id))
			return true;
	}
	return false;
}

bool CStage::CheckObject_Jamp(int x, int y, StageObjectID id)
{
	for (auto& stage_it : m_StageObject)
	{
		if (stage_it->CheckObject(x, y, id))
			return true;
	}
	return false;
}

bool CStage::CheckObject(int x, int y)
{
	if (CheckObject(x, y, StageObjectID::GRASS1_TILE) ||
		CheckObject(x, y, StageObjectID::BRICK))
		return true;
	else
		return false;
}

bool CStage::CheckObject_Jamp(int x, int y)
{
	if (CheckObject_Jamp(x, y, StageObjectID::JAMP_RAMP))
		return true;
	else
		return false;
}

bool CStage::CheckGoal(int x, int y)
{
	return CheckObject(x, y, StageObjectID::GOAL_FLAG);
}

bool CStage::CheckItem(int x, int y)
{
	return CheckObject(x, y, StageObjectID::BOX);
}

bool CStage::CheckSpike(int x, int y)
{
	return CheckObject(x, y, StageObjectID::SPIKE_BALL);
}

bool CStage::CheckJampRamp(int x, int y)
{
	return CheckObject(x, y, StageObjectID::JAMP_RAMP);
}

bool CStage::CheckDushBrock(int x, int y)
{
	return CheckObject(x, y, StageObjectID::DUSH_BROCK);
}

bool CStage::CheckKey(int x, int y)
{
	return CheckObject(x, y, StageObjectID::KEY);
}

bool CStage::CheckWire(int x, int y)
{
	return CheckObject(x, y, StageObjectID::BARBED_WIRE);
}

aqua::CVector2 CStage::GetGoalPos(void)
{
	return m_GoalPos;
}

bool CStage::CheckFloor2(IUnit* unit, StageObjectID id)
{
	for (auto& stage_it : m_StageObject)
	{
		if (!stage_it->CheckObject(unit->x, unit->ny + unit->h - 1, id) )
			return true;
	}
	return false;
}

// �������ɏ���
//&& !stage_it->CheckObject(unit->x + unit->w - 1, unit->ny + unit->h - 1, id

/*
* 
*/