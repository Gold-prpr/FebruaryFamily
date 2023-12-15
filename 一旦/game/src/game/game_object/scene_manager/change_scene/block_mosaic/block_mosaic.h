#pragma once
#include "../change_scene.h"

class CBloackMosaic :public IChangeScene
{
public:
	CBloackMosaic(aqua::IGameObject* parent);
	~CBloackMosaic() = default;

	/*
	 *  @brief 初期化
	 */
	void Initialize()override;

	/*
	 *  @brief 更新
	 */
	void Update()override;

	/*
	 *  @brief 描画
	 */
	void Draw()override;

	/*
	 *  @brief 解放
	 */
	void Finalize()override;

	/*
	 *  @brief 切り替えからシーン
	 */
	bool In()override;

	/*
	 *  @brief シーンから切り替え
	 */
	bool Out()override;

private:

	static const aqua::CPoint	m_max_block_mosaic;
	static const float			m_max_block_time;
	static const unsigned char  m_max_block_alpha;
	static const unsigned char  m_min_block_alpha;

	aqua::CBoxPrimitive*		m_MosaicBox;

	aqua::CVector2				m_MosaicSize;

	aqua::CTimer				m_BlockTime;

	int							m_CountMosaic;

};

