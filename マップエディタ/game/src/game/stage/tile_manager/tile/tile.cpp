#include "tile.h"

const aqua::CColor CTile::m_TileColor[(int)TileID::MAX] =
{
	0x00000000,
	0xff734e30,
	0xfffd7e00
};

CTile::CTile(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Tile")
	, tile_id(TileID::AIR)
	, m_PrevTileID(TileID::AIR)
{
}

/*
*  生成
*/
void CTile::Create(aqua::CVector2 position,aqua::CVector2 size)
{
	m_Position = position;

	m_TileBox.Setup(position, size.x, size.y, m_TileColor[(int)tile_id]);
}
/*
*  更新
*/
void CTile::Update()
{
	if (m_PrevTileID != tile_id)
	{
		m_PrevTileID = tile_id;
		m_TileBox.color = m_TileColor[(int)tile_id];
	}

	m_TileBox.position = m_Position + m_AddPosition;
}

/*
*  描画
*/
void CTile::Draw()
{
	m_TileBox.Draw();
}

/*
*  解放
*/
void CTile::Finalize()
{
	m_TileBox.visible = false;

	IGameObject::Finalize();
}

/*
*	座標取得
*/
aqua::CVector2 CTile::GetPosition()
{
	return m_Position + m_AddPosition;
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
