#pragma once

#include "../change_scene.h"

class CFade :public IChangeScene
{
public:
	CFade(aqua::IGameObject* parent);
	~CFade() = default;

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

	static const float m_max_fade_time;
	static const unsigned char m_max_fade_alpha;
	static const unsigned char m_min_fade_alpha;

	aqua::CBoxPrimitive m_FadeBox;

	aqua::CTimer		m_FadeTime;

};

