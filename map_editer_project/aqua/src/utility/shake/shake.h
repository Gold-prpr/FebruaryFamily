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
		*  @brief �X�V
		*/
		void Updata();

		/*
		*  @brief ������
		*/
		void Setup(int max_shake_count, float m_shake_interval);

		/*
		*  @brief �h��̍ő�l��ݒ�
		*/
		void SetMaxShakeCount(int max_shake_count);

		/*
		*  @brief �h��̏���
		*/
		void Shake();

		/*
		*  @brief �h��̑傫�����擾
		*/
		aqua::CVector2 GetShake();

		/*
		*  @brief �h��̏I���t���O
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