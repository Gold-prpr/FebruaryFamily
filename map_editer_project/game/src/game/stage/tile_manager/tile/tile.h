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
	*	ç¿ïWéÊìæ
	*/
	aqua::CVector2	GetPosition(){ return m_Position + m_AddPosition; };

	/*
	*	â¡éZï™ÇÃç¿ïWéÊìæ
	*/
	aqua::CVector2	GetAddPosition(){ return m_AddPosition; };

	void			SetPosition(aqua::CVector2 position);
	void			SetAddPosition(aqua::CVector2 add_position);

	TileID			tile_id;

	bool			not_elase_flag;

private:

	static const float				m_thickness_size;

	aqua::CSprite					m_TileSprite;
	aqua::CBoxPrimitive				m_TileBox;
	aqua::CVector2					m_TileSize;

	TileID			m_PrevTileID;

	aqua::CVector2  m_Position;
	aqua::CVector2  m_AddPosition;
};

