#pragma once
#include "aqua.h"
#include "tile/tile_id.h"
#include <fstream>

class CBackGroundManager;
class CTile;

class CTileManager : public aqua::IGameObject
{
public:
	CTileManager(aqua::IGameObject* parent);
	~CTileManager() = default;

	void Initialize(aqua::CVector2 stage_size);
	void Initialize(std::string file_name);
	void Update()override;
	void Draw()override;
	void Finalize()override;

	void SaveTile();

private:

	// ステージの大きさを再設定
	void ReSize();

private:
	static const int m_object_max_size;

	aqua::CPoint m_TileCount;
	std::list<CTile*> m_TileList;
	CTile*			m_SelectTile;
	TileID        m_NowSelectTile;

	aqua::CPoint	m_MoveStage;
	aqua::CVector2  m_MoveStartPoint;

	aqua::CVector2 m_StageSize;
	aqua::CVector2 m_TileSize;
	bool           m_ReSetSizeFlag;
	aqua::CLabel   m_SizeLabel;

	std::ofstream			m_TileDataText;            //!
	CBackGroundManager*		m_BackGroundManager;
};

