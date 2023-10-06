#pragma once
#include "../change_scene.h"

class CSlideClose :public IChangeScene
{
public:
	CSlideClose(aqua::IGameObject* parent);
	~CSlideClose() = default;

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

	static const float			m_start_position_x;
	static const float			m_max_block_time;
	static const int			m_max_block;

	aqua::CBoxPrimitive*		m_MosaicBox;

	aqua::CVector2				m_MosaicSize;

	aqua::CTimer				m_BlockTime;
};

