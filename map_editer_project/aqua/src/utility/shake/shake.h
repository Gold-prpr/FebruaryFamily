#pragma once
#include "../../mathematics/vector/vector2/vector2.h"
#include "../timer/timer.h"

namespace aqua
{
	class CShake
	{
	public:

		CShake();

		~CShake() = default;

		/*
		*  @brief 更新
		*/
		void Updata();

		/*
		*  @brief 初期化
		*/
		void Setup(int max_shake_count, float m_shake_interval);

		/*
		*  @brief 揺れの最大値を設定
		*/
		void SetMaxShakeCount(int max_shake_count);

		/*
		*  @brief 揺れの処理
		*/
		void Shake();

		/*
		*  @brief 揺れの大きさを取得
		*/
		aqua::CVector2 GetShake();

		/*
		*  @brief 揺れの終了フラグ
		*/
		bool GetShakeFinished();

	private:

		int m_max_angle;

		aqua::CVector2 m_ShakeMove;
		aqua::CTimer  m_ShakeTimer;
		int m_ShakeCount;
		int m_ShakeMaxCount;
		float m_Angle;

	};
}