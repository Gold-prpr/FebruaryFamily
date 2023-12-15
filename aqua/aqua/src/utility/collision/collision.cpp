#include "collision.h"

aqua::CCollision::CCollision()
{
}

/*
 *  éläpÇ∆éläpÇÃè’ìÀ
 */
aqua::CollisionInfo aqua::CCollision::BoxAndBox(BoxInfo box_a, BoxInfo box_b)
{
	CollisionInfo info;

	info.collision = 
		box_b.position.x + box_b.size.x >= box_a.position.x &&
		box_a.position.x + box_a.size.x >= box_b.position.x &&
		box_b.position.y + box_b.size.y >= box_a.position.y &&
		box_a.position.y + box_a.size.y >= box_b.position.y;

	return info;
}

/*
 *  â~Ç∆â~ÇÃè’ìÀ
 */
aqua::CollisionInfo aqua::CCollision::CircleAndCircle(CircleInfo circle_a, CircleInfo circle_b)
{
	CollisionInfo info;

	aqua::CVector2 c = circle_a.center_position - circle_b.center_position;
	float r = circle_a.r + circle_b.r;

	c = c * c;
	r = r * r;

	info.collision = c.x + c.y <= r;

	if (info.collision)
	{
		info.c_distance = circle_a.center_position - circle_b.center_position;
	}

	return info;
}
