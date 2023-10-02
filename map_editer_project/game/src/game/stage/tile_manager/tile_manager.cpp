#include "tile_manager.h"
#include "tile/tile.h"
#include "../back_ground_manager/back_ground_manager.h"
#include <filesystem>

namespace mouse = aqua::mouse;
namespace keyboard = aqua::keyboard;
namespace files = std::filesystem;

const int CTileManager::m_object_max_size = 60;

CTileManager::CTileManager(aqua::IGameObject* parent)
	:IGameObject(parent, "TileManager")
	, m_NowSelectTile(TileID::AIR)
	, m_ReSetSizeFlag(false)
	, m_SelectTile(nullptr)
{
}

void CTileManager::Initialize(aqua::CVector2 stage_size)
{
	m_StageSize = stage_size;
	m_TileSize = aqua::CVector2::ONE * m_object_max_size;

	m_TileCount.x = (int)(m_StageSize.x / m_TileSize.x);
	m_TileCount.y = (int)(m_StageSize.y / m_TileSize.y);

	for (int i = 0; i < m_TileCount.y; i++)
	{
		for (int j = 0; j < m_TileCount.x; j++)
		{
			CTile* tile = nullptr;

			tile = aqua::CreateGameObject<CTile>(this);

			tile->Create(aqua::CVector2(j, i) * m_object_max_size, aqua::CVector2::ONE * m_object_max_size);

			m_TileList.push_back(tile);
		}
	}

	m_SelectTile = aqua::CreateGameObject<CTile>(this);
	m_SelectTile->Create(mouse::GetCursorPos(), aqua::CVector2::ONE * m_object_max_size);
	m_SelectTile->not_elase_flag = true;

	m_SizeLabel.Create(80);
	m_SizeLabel.text =
		"-↑キー　縦：" + std::to_string(m_TileCount.y) + "　↓キー+" +
		"\n-←キー　横：" + std::to_string(m_TileCount.x) + "　→キー+　";
}

void CTileManager::Update()
{
	aqua::CVector2 pos = mouse::GetCursorPos();

	for (auto& it : m_TileList)
	{
		aqua::CVector2 tile_pos = it->GetPosition();

		if (tile_pos.x <= pos.x && tile_pos.x + m_object_max_size > pos.x &&
			tile_pos.y <= pos.y && tile_pos.y + m_object_max_size > pos.y)
		{
			if (mouse::Button(mouse::BUTTON_ID::LEFT))
			{
				//　色塗り
				if (!keyboard::Button(keyboard::KEY_ID::LCONTROL))
					it->tile_id = m_NowSelectTile;
			}

			m_SelectTile->SetPosition(tile_pos);
		}
	}

	// Ctel＋Shift で大きさを再定義
	if (keyboard::Button(keyboard::KEY_ID::LCONTROL) || keyboard::Button(keyboard::KEY_ID::RCONTROL))
	{
		if (keyboard::Button(keyboard::KEY_ID::LSHIFT))
		{
			m_ReSetSizeFlag = true;
		}
	}

	if (m_ReSetSizeFlag)
	{
		ReSize();
	}

	// Ctel＋マウス左を押しながら
	if (keyboard::Button(keyboard::KEY_ID::LCONTROL))
	{
		if (mouse::Trigger(mouse::BUTTON_ID::LEFT))
		{
			m_MoveStartPoint = mouse::GetCursorPos();
		}

		if (mouse::Button(mouse::BUTTON_ID::LEFT))
		{
			aqua::CPoint move_point;
			move_point.x = (int)(mouse::GetCursorPos().x - m_MoveStartPoint.x);
			move_point.y = (int)(mouse::GetCursorPos().y - m_MoveStartPoint.y);

			float large = (float)std::sqrt(((move_point.x * move_point.x) + (move_point.y * move_point.y)));
			float angle = atan2f((float)move_point.x, (float)move_point.y);

			move_point.x = (int)(sin(angle) * large / 10.0f);
			move_point.y = (int)(cos(angle) * large / 10.0f);

			m_MoveStage.x = aqua::Limit(m_MoveStage.x - move_point.x, -(m_TileCount.x - 1) * m_object_max_size, 0);
			m_MoveStage.y = aqua::Limit(m_MoveStage.y - move_point.y, -(m_TileCount.y - 1) * m_object_max_size, 0);

			for (auto& tile_it : m_TileList)
			{
				tile_it->SetAddPosition(m_MoveStage);
			}

		}
	}

	// マウスの右を押しながらホイール
	if (mouse::Button(mouse::BUTTON_ID::RIGHT))
	{
		m_NowSelectTile = aqua::Mod<TileID, int>((int)m_NowSelectTile + (int)(mouse::GetWheel()), (int)TileID::AIR, (int)TileID::MAX);
	}

	if (keyboard::Button(keyboard::KEY_ID::LSHIFT))
	{
		if (mouse::Button(mouse::BUTTON_ID::RIGHT))
		{
			for (auto& it : m_TileList)
			{
				aqua::CVector2 tile_pos = it->GetPosition();

				if (tile_pos.x <= pos.x && tile_pos.x + m_object_max_size > pos.x &&
					tile_pos.y <= pos.y && tile_pos.y + m_object_max_size > pos.y)
				{
					m_NowSelectTile = it->tile_id;
				}
			}
		}
	}

	m_SelectTile->tile_id = m_NowSelectTile;

	IGameObject::Update();
}

void CTileManager::Draw()
{
	IGameObject::Draw();

	m_SelectTile->Draw();

	if (m_ReSetSizeFlag)
		m_SizeLabel.Draw();
}

void CTileManager::Finalize()
{
	m_SizeLabel.Delete();
	IGameObject::Finalize();
}

void CTileManager::SaveTile()
{
	m_BackGroundManager = (CBackGroundManager*)aqua::FindGameObject("BackGroundManager");

	// 存在しないファイル名を検索
	std::string file;

	int j = 0;

	do {
		file = "data\\map_data\\map_data" + std::to_string(j) + ".csv";
		++j;
	} while (files::exists(file));

	// ファイルを生成
	m_TileDataText.open(file, std::ios::out);

	m_TileDataText << m_BackGroundManager->GetSpritePath() << ",DUMMY\n";

	for (auto& i : m_TileList)
	{
		if (i->tile_id != TileID::AIR)
		{
			m_TileDataText << std::to_string((int)i->tile_id) << ",";
			m_TileDataText << std::to_string(i->GetPosition().x - i->GetAddPosition().x) << ",";
			m_TileDataText << std::to_string(i->GetPosition().y - i->GetAddPosition().y) << ",DUMMY\n";
		}
	}

	m_TileDataText.close();

}

void CTileManager::ReSize()
{
	if (keyboard::Trigger(keyboard::KEY_ID::TAB))
		m_ReSetSizeFlag = false;

	if (keyboard::Trigger(keyboard::KEY_ID::RIGHT))
	{
		for (int i = 0; i < m_TileCount.y; i++)
		{
			CTile* tile = nullptr;

			tile = aqua::CreateGameObject<CTile>(this);

			tile->Create(aqua::CVector2(m_TileCount.x, i) * m_object_max_size, aqua::CVector2::ONE * m_object_max_size);

			m_TileList.push_back(tile);
		}

		m_TileCount.x += keyboard::Trigger(keyboard::KEY_ID::RIGHT);
	}
	else if (keyboard::Trigger(keyboard::KEY_ID::LEFT))
	{
		auto tile_it = m_TileList.end();
		bool flag = false;

		// タイルリストから解放
		while (tile_it != m_TileList.begin())
		{
			tile_it--;

			if ((*tile_it)->GetPosition().x >= (m_TileCount.x - 1) * m_object_max_size + (*tile_it)->GetAddPosition().x)
			{
				flag = true;
				(*tile_it)->Finalize();
				tile_it = aqua::ListErase(&m_TileList, tile_it);

			}

		}
		
		auto child_it = m_ChildObjectList.end();

		// 子オブジェクトリストから解放
		while (child_it != m_ChildObjectList.begin())
		{
			child_it--;

			if ((*child_it)->GetGameObjectName() == "Tile")
			{
				if (!((CTile*)(*child_it))->not_elase_flag)
				{
					if (((CTile*)(*child_it))->GetPosition().x >= (m_TileCount.x - 1) * m_object_max_size + ((CTile*)(*child_it))->GetAddPosition().x)
					{

						((CTile*)(*child_it))->Finalize();
						child_it = aqua::ListErase(&m_ChildObjectList, child_it);

					}
				}
			}

		}

		if (flag)
			m_TileCount.x--;

	}

	if (keyboard::Trigger(keyboard::KEY_ID::DOWN))
	{
		for (int i = 0; i < m_TileCount.x; i++)
		{
			CTile* tile = nullptr;

			tile = aqua::CreateGameObject<CTile>(this);

			tile->Create(aqua::CVector2(i, m_TileCount.y) * m_object_max_size, aqua::CVector2::ONE * m_object_max_size);

			m_TileList.push_back(tile);
		}

		m_TileCount.y += keyboard::Trigger(keyboard::KEY_ID::DOWN);
	}
	else if (keyboard::Trigger(keyboard::KEY_ID::UP))
	{
		auto tile_it = m_TileList.end();
		bool flag = false;

		// タイルリストから解放
		while (tile_it != m_TileList.begin())
		{
			tile_it--;

			if ((*tile_it)->GetPosition().y >= (m_TileCount.y - 1) * m_object_max_size + (*tile_it)->GetAddPosition().y)
			{
				flag = true;
				(*tile_it)->Finalize();
				tile_it = aqua::ListErase(&m_TileList, tile_it);
			}

		}

		auto child_it = m_ChildObjectList.end();

		// 子オブジェクトリストから解放
		while (child_it != m_ChildObjectList.begin())
		{
			child_it--;

			if ((*child_it)->GetGameObjectName() == "Tile")
			{
				if (!((CTile*)(*child_it))->not_elase_flag)
				{
					if (((CTile*)(*child_it))->GetPosition().y >= (m_TileCount.y - 1) * m_object_max_size + ((CTile*)(*child_it))->GetAddPosition().y)
					{

						((CTile*)(*child_it))->Finalize();
						child_it = aqua::ListErase(&m_ChildObjectList, child_it);

					}
				}
			}

		}

		if (flag)
			m_TileCount.y--;
	}

	m_SizeLabel.text =
		"-↑キー　縦：" + std::to_string(m_TileCount.y) + "　↓キー+" +
		"\n-←キー　横：" + std::to_string(m_TileCount.x) + "　→キー+　";
}
