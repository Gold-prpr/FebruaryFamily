#ifndef _USE_DXLIB
#include "vector3.h"
#include <cmath>

//#define _USE_DXVECTOR

const aqua::CVector3 aqua::CVector3::ZERO = aqua::CVector3(0.0f, 0.0f, 0.0f);
const aqua::CVector3 aqua::CVector3::ONE = aqua::CVector3(1.0f, 1.0f, 1.0f);

aqua::CVector3::CVector3(void)
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

aqua::CVector3::CVector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

aqua::CVector3::CVector3(const CVector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

aqua::CVector3
aqua::CVector3::Normalize(void)
{
	return Normalize(*this);
}

aqua::CVector3
aqua::CVector3::Normalize(const CVector3& v)
{
#ifdef _USE_DXVECTOR
	VECTOR dxv = VNorm(v);
	aqua::Vector3 ret(v.x, v.y, v.z);
	return ret;
#else
	aqua::CVector3 t = v;
	float inv = 1.0f / t.Length();

	t.x *= inv;
	t.y *= inv;
	t.z *= inv;

	return t;
#endif
}

float
aqua::CVector3::Length(void)
{
	return Length(*this);
}

float
aqua::CVector3::Length(const CVector3& v)
{
#ifdef _USE_DXVECTOR
	return VSize(v);
#else
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
#endif
}

float
aqua::CVector3::Dot(const CVector3& vA, const CVector3& vB)
{
	return ((vA.x * vB.x) + (vA.y * vB.y) + (vA.z * vB.z));
}

aqua::CVector3 
aqua::CVector3::Cross(const CVector3& vA, const CVector3& vB)
{
	CVector3 r;
	r.x = vA.y * vB.z - vA.z * vB.y;
	r.y = vA.z * vB.x - vA.x * vB.z;
	r.z = vA.x * vB.y - vA.y * vB.x;

	return r;
}

#endif