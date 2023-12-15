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
		*  @brief XV
		*/
		void Updata();

		/*
		*  @brief ‰Šú‰»
		*/
		void Setup(int max_shake_count, float m_shake_interval);

		/*
		*  @brief —h‚ê‚ÌÅ‘å’l‚ğİ’è
		*/
		void SetMaxShakeCount(int max_shake_count);

		/*
		*  @brief —h‚ê‚Ìˆ—
		*/
		void Shake();

		/*
		*  @brief —h‚ê‚Ì‘å‚«‚³‚ğæ“¾
		*/
		aqua::CVector2 GetShake();

		/*
		*  @brief —h‚ê‚ÌI—¹ƒtƒ‰ƒO
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