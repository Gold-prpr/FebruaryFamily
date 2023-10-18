#pragma once
#include "../../mathematics/vector/vector2/vector2.h"

namespace aqua
{
	/*
	*  @brief �l�p�̏Փˏ��
	* 
	*  @param[in] position�@���_
	*  @param[in] size�@�@�@�傫��
	*/
	struct BoxInfo
	{
		aqua::CVector2 position; //! ���_
		aqua::CVector2 size;     //! �傫��
	};

	/*
	*  @brief �~�̏Փˏ��
	*
	*  @param[in] center_position	���S�_
	*  @param[in] r�@�@�@�@�@�@    �@���a
	*/
	struct CircleInfo
	{
		aqua::CVector2 center_position; //! ���_
		float r;						//! ���a
	};

	/*
	*  @brief �Փˏ��
	*
	*  @param[in] collision	�@�@�Փ˔���
	*  @param[in] c_distance�@  �Փ˂�������
	*/
	struct CollisionInfo
	{
		bool collision;            //! �Փ˔���
		aqua::CVector2 c_distance; //! �Փ˂�������
	};

	class CCollision
	{
	public:
		CCollision();

		~CCollision() = default;

		/*
		*  @brief �l�p�Ǝl�p�̏Փ�
		*
		*  @param[in] box_a	��ڂ̎l�p
		*  @param[in] box_b ��ڂ̎l�p
		* 
		*  @return CollisionInfo �Փˏ��
		*/
		CollisionInfo BoxAndBox(BoxInfo box_a, BoxInfo box_b);

		/*
		*  @brief �~�Ɖ~�̏Փ�
		*
		*  @param[in] circle_a�@��ڂ̉~
		*  @param[in] circle_b�@��ڂ̉~
		*
		*  @return CollisionInfo �Փˏ��
		*/
		CollisionInfo CircleAndCircle(CircleInfo circle_a, CircleInfo circle_b);

	};
}