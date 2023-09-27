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

	/*
	*	座標取得
	*/
	aqua::CVector2	GetPosition(){ return m_Position + m_AddPosition; };

	/*
	*	加算分の座標取得
	*/
	aqua::CVector2	GetAddPosition(){ return m_AddPosition; };

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

