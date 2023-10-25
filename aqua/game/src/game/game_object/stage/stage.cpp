#include "stage.h"
#include "../camera_manager/camera_manager.h"
#include "stage_object/stage_object.h"

const int CStage::map_chip_size = 60;

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
	std::string file_name = "data\\scene\\game\\map_data7.csv";

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

	m_BackGround.Create(loader.GetString(0, 0));

	map_x = loader.GetInteger(0, 1);
	map_y = loader.GetInteger(0, 2);

	m_BackGround.scale.x = (float)(map_x * map_chip_size) / (float)aqua::GetWindowSize().x;
	m_BackGround.scale.y = (float)(map_y * map_chip_size * 2) / (float)aqua::GetWindowSize().y;

	for (int y = 1; y < rows; y++)
	{
		CStageObject* stage_object = nullptr;

		stage_object = aqua::CreateGameObject<CStageObject>(this);

		stage_object->Create(aqua::CVector2(loader.GetFloat(y,1), loader.GetFloat(y,2)), aqua::CVector2::ONE * map_chip_size);

		stage_object->stage_object_id = (StageObjectID)loader.GetInteger(y,0);

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

bool CStage::CheckHit(int x, int y)
{
	for (auto& stage_it : m_StageObject)
	{
		aqua::CVector2 pos = stage_it->GetPosition();

		if (pos.x < x && pos.x + map_chip_size > x &&
			pos.y < y && pos.y + map_chip_size > y &&
			(int)stage_it->stage_object_id != (int)StageObjectID::AIR &&
			(int)stage_it->stage_object_id == (int)StageObjectID::GRASS1_TILE)
			return true;
	}

	return false;
}

int CStage::GetTileSize(void)
{
	return map_chip_size;
}

bool CStage::CheckGoal(int x, int y)
{
	for (auto& stage_it : m_StageObject)
	{
		aqua::CVector2 pos = stage_it->GetPosition();

		if (pos.x < x && pos.x + map_chip_size > x &&
			pos.y < y && pos.y + map_chip_size > y && 
			stage_it->stage_object_id == StageObjectID::GOAL_FLAG)
			return true;
	}

	return false;
}

bool CStage::CheckItem(int x, int y)
{
	for (auto& stage_it : m_StageObject)
	{
		aqua::CVector2 pos = stage_it->GetPosition();

		if (pos.x < x && pos.x + map_chip_size > x &&
			pos.y < y && pos.y + map_chip_size > y &&
			stage_it->stage_object_id == StageObjectID::BOX)
			return true;
	}

	return false;
}

bool CStage::CheckGimmick(int x, int y)
{
	for (auto& stage_it : m_StageObject)
	{
		aqua::CVector2 pos = stage_it->GetPosition();

		if (pos.x < x && pos.x + map_chip_size > x &&
			pos.y < y && pos.y + map_chip_size > y &&
			stage_it->stage_object_id == StageObjectID::SPIKE_BALL)
			return true;
	}

	return false;
}
