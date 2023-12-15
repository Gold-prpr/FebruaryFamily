#pragma once
#include <DxLib.h>

#define _INHERITANCE_DXVECTOR
namespace aqua
{
#ifndef _INHERITANCE_DXVECTOR
	using Vector3 = DxLib::VECTOR;

	inline const bool operator==(const Vector3& vA, const Vector3& vB) { return(vA.x == vB.x && vA.y == vB.y && vA.z == vB.z); }
	inline const bool operator!=(const Vector3& vA, const Vector3& vB) { return(vA.x != vB.x || vA.y != vB.y || vA.z != vB.z); }
	inline const Vector3 operator+(const Vector3& v) { return v; }
	inline const Vector3 operator+(const Vector3& vA, const Vector3& vB) { return VAdd(vA, vB); }
	inline const Vector3 operator-(const Vector3& v) { return VGet(-v.x, -v.y, -v.z); }
	inline const Vector3 operator-(const Vector3& vA, const Vector3& vB) { return VSub(vA, vB); }
	inline const Vector3 operator*(const Vector3& v, float scalar) { return VScale(v, scalar); }
	inline const Vector3 operator*(float scalar, const Vector3& v) { return VScale(v, scalar); }
	inline const Vector3 operator/(const Vector3& v, float scalar) { return VScale(v, 1.0f / scalar); }
	inline const Vector3 operator+=(const Vector3& vA, const Vector3& vB) { return VAdd(vA, vB); }
	inline const Vector3 operator-=(const Vector3& vA, const Vector3& vB) { return VSub(vA, vB); }
	inline const Vector3 operator*=(const Vector3& v, float scalar) { return VScale(v, scalar); }
	inline const Vector3 operator/=(const Vector3& v, float scalar) { return VScale(v, 1.0f / scalar); }

	static const Vector3 ZERO = { 0.0f, 0.0f, 0.0f };
	static const Vector3 ONE = { 1.0f, 1.0f, 1.0f };
	static const Vector3 RIGHT = { 1.0f, 0.0f, 0.0f };
	static const Vector3 UP = { 0.0f, 1.0f, 0.0f };
	static const Vector3 FRONT = { 0.0f, 0.0f, 1.0f };
#else
	class CVector3 : public DxLib::VECTOR
	{
	public:
		CVector3(void);
		CVector3(float x, float y, float z);
		CVector3(const CVector3& v);
		~CVector3() = default;

		CVector3		Normalize(void);
		static CVector3 Normalize(const CVector3& v);

		float Length(void);
		static float Length(const CVector3& v);

		static float Dot(const CVector3& vA, const CVector3& vB);

		static CVector3 Cross(const CVector3& vA, const CVector3& vB);

		inline CVector3& operator=(const CVector3& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;

			return *this;
		}

		inline CVector3& operator+=(const CVector3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;

			return *this;
		}

		inline CVector3& operator-=(const CVector3& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;

			return *this;
		}

		inline CVector3& operator*=(const float scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;

			return *this;
		}
		
		inline bool operator==(const CVector3& v){ return (x == v.x && y == v.y && z == v.z); }
		inline bool operator!=(const CVector3& v){ return (x != v.x || y != v.y || z != v.z); }

		friend CVector3 operator+(const CVector3& v) { return v; }
		friend CVector3 operator-(const CVector3& v) { return CVector3(-v.x, -v.y, -v.z); }
		friend CVector3 operator+(const CVector3& vA, const CVector3& vB) { return CVector3(vA.x + vB.x, vA.y + vB.y, vA.z + vB.z); }
		friend CVector3 operator-(const CVector3& vA, const CVector3& vB) { return CVector3(vA.x - vB.x, vA.y - vB.y, vA.z - vB.z); }
		friend CVector3 operator*(const CVector3& v, float scalar) { return CVector3(v.x * scalar, v.y * scalar, v.z * scalar); }
		friend CVector3 operator/(const CVector3& v, float scalar) { return CVector3(v.x / scalar, v.y / scalar, v.z / scalar); }

		static const CVector3 ZERO;
		static const CVector3 ONE;
	};
	using Vector3 = CVector3;
#endif
}