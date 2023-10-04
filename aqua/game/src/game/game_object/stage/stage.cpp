#include "stage.h"
#include "../camera/camera.h"

const int CStage::map_chip_size = 60;

const int CStage::num_chip_size_x = 3;
const int CStage::num_chip_size_y = 1;

const int CStage::all_num_chip = num_chip_size_x * num_chip_size_y;

const int CStage::map_x = 60;
const int CStage::map_y = 18;

const float CStage::m_gravity = 1.0f;

CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Stage")
{
}

void CStage::Initialize(void)
{
	m_pCamera = (CCamera*)aqua::FindGameObject("Camera");

	std::string file_name = "data//stage.csv";

	m_TileSprite = AQUA_NEW aqua::CSprite[all_num_chip];

	for (int i = 0; i < (int)TILE_ID::MAX; i++)
	{
		m_TileSprite[i].Create("data\\tile.png");

		int cw = i % 3 * map_chip_size;
		int ch = i / 3 * map_chip_size;

		m_TileSprite[i].rect = aqua::CRect(cw, ch, cw + map_chip_size, ch + map_chip_size);
	}

	Parse(file_name);

	IGameObject::Initialize();
}

void CStage::Update(void)
{
	IGameObject::Update();
}

void CStage::Draw(void)
{
	int i = 0;

	for (auto it = m_MapData.begin(); it != m_MapData.end(); ++it, ++i)
	{
		m_TileSprite[*it].position.x = (float)(i % map_x) * map_chip_size + m_pCamera->GetScroll().x;
		m_TileSprite[*it].position.y = (float)(i / map_x) * map_chip_size + m_pCamera->GetScroll().y;

		m_TileSprite[*it].Draw();
	}

	IGameObject::Draw();
}

void CStage::Finalize(void)
{
	for (int i = 0; i < (int)TILE_ID::MAX; i++)
		m_TileSprite[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_TileSprite);

	IGameObject::Finalize();
}

void CStage::Parse(const std::string& file_name)
{
	aqua::CCSVLoader loader;

	loader.Load(file_name);

	for (int y = 0; y < loader.GetRows(); y++)
	{
		for (int x = 0; x < loader.GetCols(); x++)
		{
			m_MapData.push_back(loader.GetInteger(y, x));
		}
	}

	loader.Unload();
}

float CStage::GetMapWidth(void)
{
	return map_chip_size * map_x;
}

float CStage::GetMapHeight(void)
{
	return map_chip_size * map_y;
}

float CStage::GetGravity(void)
{
	return m_gravity;
}

bool CStage::CheckHit(int x, int y)
{
	int ix = x / map_chip_size;
	int iy = y / map_chip_size;

	if (m_MapData[map_x * iy + ix] == (int)TILE_ID::GROUND_TILE)
		return true;

	return false;
}

int CStage::GetTileSize(void)
{
	return map_chip_size;
}
