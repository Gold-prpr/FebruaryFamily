#pragma once

enum class TileID
{
#if TRUE
	AIR,
	GRASS1_TILE,
	GRASS2_TILE,
	SAND1_TILE,
	SAND2_TILE,
	WHITE_TILE,
	ICE1_TILE,
	ICE2_TILE,
	IRON_TILE,
	GOLD_TILE,
	BRICK,
	WHITE_BRICK,
	ICE1_BRICK,
	ICE2_BRICK,
	IRON_BRICK,
	RED_BRICK,
	GOLD_BRICK,
	BOX,
	GOAL_FLAG,
	START_FLAG,
	SPIKE_BALL,
	BARBED_WIRE,
	JAMP_RAMP,
	DUSH_BROCK,
	KEY,

	MAX

#else
	AIR,
	GRASS1_TILE,
	SAND1_TILE,
	SAND2_TILE,
	BRICK,
	BOX,
	GOAL_FLAG,
	START_FLAG,
	SPIKE_BALL,
	BARBED_WIRE,
	JAMP_RAMP,
	DUSH_BROCK,
	KEY,

	MAX
#endif
};