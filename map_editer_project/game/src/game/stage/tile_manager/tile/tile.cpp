#include "tile.h"

const float CTile::m_thickness_size = 10.0f;

CTile::CTile(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Tile")
	, tile_id(TileID::AIR)
	, m_PrevTileID(TileID::AIR)
	, not_elase_flag(false)
{
}

/*
*  生成
*/
void CTile::Create(aqua::CVector2 position, aqua::CVector2 size)
{
	m_Position = position;

	m_TileSprite.Create("data\\tile.png");

	// RECT
	m_TileSprite.rect.left = 0;
	m_TileSprite.rect.right = (int)size.x;

	m_TileSize = size;

	m_TileBox.Setup(position, m_TileSize.x, m_TileSize.y);
	m_TileBox.fill = false;

}
/*
*  更新
*/
void CTile::Update()
{
	if (m_PrevTileID != tile_id)
	{
		m_PrevTileID = tile_id;

		if (tile_id != TileID::AIR)
		{
			m_TileSprite.rect.left = ((int)tile_id - 1) * (int)m_TileSize.x;
			m_TileSprite.rect.right = (int)tile_id * (int)m_TileSize.x;
		}
	}

	m_TileSprite.position = m_Position + m_AddPosition;

	if (tile_id == TileID::AIR)
		m_TileBox.position = m_TileSprite.position;
}

/*
*  描画
*/
void CTile::Draw()
{
	if (tile_id != TileID::AIR)
		m_TileSprite.Draw();
	else
		m_TileBox.Draw();
}

/*
*  解放
*/
void CTile::Finalize()
{
	m_TileSprite.Delete();

	IGameObject::Finalize();
}

/*
*  座標の設定
*/
void CTile::SetPosition(aqua::CVector2 position)
{
	m_Position = position;
}

void CTile::SetAddPosition(aqua::CVector2 add_position)
{
	m_AddPosition = add_position;
}
