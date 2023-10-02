#include "stage.h"

const int CStage::map_chip_size = 60;

const int CStage::num_chip_size_x = 3;
const int CStage::num_chip_size_y = 1;

const int CStage::all_num_chip = num_chip_size_x * num_chip_size_y;

const int CStage::map_x = 33;
const int CStage::map_y = 18;

const float CStage::m_gravity = 1.0f;

CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Stage")
{
}

void CStage::Initialize(const aqua::CVector2& map_pos)
{
	m_Scroll = aqua::CVector2::ZERO;

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
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::LEFT))
	{
		m_Scroll.x -= 1.0f;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::RIGHT))
	{
		m_Scroll.x += 1.0f;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::DOWN))
	{
		m_Scroll.y += 1.0f;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::UP))
	{
		m_Scroll.y -= 1.0f;
	}

	IGameObject::Update();
}

void CStage::Draw(void)
{
	int i = 0;

	for (auto it = m_MapData.begin(); it != m_MapData.end(); ++it, ++i)
	{
		//1次元配列だからｙ使わない
		m_TileSprite[*it].position.x = (float)(i % map_x) * 60 - m_Scroll.x;
		m_TileSprite[*it].position.y = (float)(i / map_x) * 60 + m_Scroll.y;

		m_TileSprite[*it].Draw();
	}

	DrawFormatString(10, 10, GetColor(255, 0, 0), "スクロール値：%f,%f", m_Scroll.x, m_Scroll.y);

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
