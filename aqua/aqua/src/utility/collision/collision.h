#pragma once
#include "../../mathematics/vector/vector2/vector2.h"

namespace aqua
{
	/*
	*  @brief lpΜΥΛξρ
	* 
	*  @param[in] position@΄_
	*  @param[in] size@@@ε«³
	*/
	struct BoxInfo
	{
		aqua::CVector2 position; //! ΄_
		aqua::CVector2 size;     //! ε«³
	};

	/*
	*  @brief ~ΜΥΛξρ
	*
	*  @param[in] center_position	S_
	*  @param[in] r@@@@@@    @Όa
	*/
	struct CircleInfo
	{
		aqua::CVector2 center_position; //! ΄_
		float r;						//! Όa
	};

	/*
	*  @brief ΥΛξρ
	*
	*  @param[in] collision	@@ΥΛ»θ
	*  @param[in] c_distance@  ΥΛ΅½£
	*/
	struct CollisionInfo
	{
		bool collision;            //! ΥΛ»θ
		aqua::CVector2 c_distance; //! ΥΛ΅½£
	};

	class CCollision
	{
	public:
		CCollision();

		~CCollision() = default;

		/*
		*  @brief lpΖlpΜΥΛ
		*
		*  @param[in] box_a	κΒΪΜlp
		*  @param[in] box_b ρΒΪΜlp
		* 
		*  @return CollisionInfo ΥΛξρ
		*/
		CollisionInfo BoxAndBox(BoxInfo box_a, BoxInfo box_b);
		
		/*
		*  @brief ~Ζ~ΜΥΛ
		*
		*  @param[in] circle_a@κΒΪΜ~
		*  @param[in] circle_b@ρΒΪΜ~
		*
		*  @return CollisionInfo ΥΛξρ
		*/
		CollisionInfo CircleAndCircle(CircleInfo circle_a, CircleInfo circle_b);

	};
}