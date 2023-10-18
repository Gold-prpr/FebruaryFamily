#pragma once
#include "../../mathematics/vector/vector2/vector2.h"

namespace aqua
{
	/*
	*  @brief 四角の衝突情報
	* 
	*  @param[in] position　原点
	*  @param[in] size　　　大きさ
	*/
	struct BoxInfo
	{
		aqua::CVector2 position; //! 原点
		aqua::CVector2 size;     //! 大きさ
	};

	/*
	*  @brief 円の衝突情報
	*
	*  @param[in] center_position	中心点
	*  @param[in] r　　　　　　    　半径
	*/
	struct CircleInfo
	{
		aqua::CVector2 center_position; //! 原点
		float r;						//! 半径
	};

	/*
	*  @brief 衝突情報
	*
	*  @param[in] collision	　　衝突判定
	*  @param[in] c_distance　  衝突した距離
	*/
	struct CollisionInfo
	{
		bool collision;            //! 衝突判定
		aqua::CVector2 c_distance; //! 衝突した距離
	};

	class CCollision
	{
	public:
		CCollision();

		~CCollision() = default;

		/*
		*  @brief 四角と四角の衝突
		*
		*  @param[in] box_a	一つ目の四角
		*  @param[in] box_b 二つ目の四角
		* 
		*  @return CollisionInfo 衝突情報
		*/
		CollisionInfo BoxAndBox(BoxInfo box_a, BoxInfo box_b);

		/*
		*  @brief 円と円の衝突
		*
		*  @param[in] circle_a　一つ目の円
		*  @param[in] circle_b　二つ目の円
		*
		*  @return CollisionInfo 衝突情報
		*/
		CollisionInfo CircleAndCircle(CircleInfo circle_a, CircleInfo circle_b);

	};
}