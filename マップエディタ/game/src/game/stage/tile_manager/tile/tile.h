#pragma once
#include "aqua.h"
#include "tile_id.h"

class CTile :
    public aqua::IGameObject
{
public:
	CTile(aqua::IGameObject* parent);
	~CTile() = default;

	void Create(aqua::CVector2 position,aqua::CVector2 size);
	void Update() override;
	void Draw()override;
	void Finalize()override;

	aqua::CVector2	GetPosition();
	void			SetPosition(aqua::CVector2 position);
	void			SetAddPosition(aqua::CVector2 add_position);

	TileID			tile_id;

private:

	static const aqua::CColor		m_TileColor[(int)TileID::MAX];

	aqua::CBoxPrimitive				m_TileBox;

	TileID			m_PrevTileID;

	aqua::CVector2  m_Position;
	aqua::CVector2  m_AddPosition;
};

