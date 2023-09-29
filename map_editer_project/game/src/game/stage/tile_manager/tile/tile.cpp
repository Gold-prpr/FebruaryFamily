#include "tile.h"

const float CTile::m_thickness_size = 10.0f;

CTile::CTile(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Tile")
	, tile_id(TileID::AIR)
	, m_PrevTileID(TileID::AIR)
{
}

/*
*  ê∂ê¨
*/
void CTile::Create(aqua::CVector2 position, aqua::CVector2 size)
{
	m_Position = position;

	m_TileSprite.Create("data\\object.png");

	// RECT
	m_TileSprite.rect.left = 0;
	m_TileSprite.rect.right = size.x;

	m_TileSize = size;

	m_TileBox.Setup(position, m_TileSize.x, m_TileSize.y);
	m_TileBox.fill = false;

}
/*
*  çXêV
*/
void CTile::Update()
{
	if (m_PrevTileID != tile_id)
	{
		m_PrevTileID = tile_id;

		if (tile_id != TileID::AIR)
		{
			m_TileSprite.rect.left = ((int)tile_id - 1) * m_TileSize.x;
			m_TileSprite.rect.right = (int)tile_id * m_TileSize.x;
		}
	}

	m_TileSprite.position = m_Position + m_AddPosition;

	if (tile_id == TileID::AIR)
		m_TileBox.position = m_TileSprite.position;
}

/*
*  ï`âÊ
*/
void CTile::Draw()
{
	if (tile_id != TileID::AIR)
		m_TileSprite.Draw();
	else
		m_TileBox.Draw();
}

/*
*  âï˙
*/
void CTile::Finalize()
{
	m_TileSprite.Delete();

	IGameObject::Finalize();
}

/*
*  ç¿ïWÇÃê›íË
*/
void CTile::SetPosition(aqua::CVector2 position)
{
	m_Position = position;
}

void CTile::SetAddPosition(aqua::CVector2 add_position)
{
	m_AddPosition = add_position;
}
