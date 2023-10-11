#pragma once
#include "aqua.h"

using namespace aqua::controller;

enum class UNIT_ID
{
	PLAYER,
	MAX
};

class IUnit :public aqua::IGameObject
{
public:
	IUnit(IGameObject* parent, const std::string& object_name);

	virtual ~IUnit(void) = default;

	virtual void Initialize(const aqua::CVector2& position,DEVICE_ID device ) = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Finalize() = 0;

	const aqua::CVector2& GetPosition() { return m_Position; }

	const aqua::CVector2& GetVelocity() { return m_Velocity; }

	float GetWidth() { return m_Width; }

	float GetHeight() { return m_Height; }

	UNIT_ID GetUnitID() { return m_UnitID; }

	virtual void Damage(void) = 0;

protected:
	aqua::CVector2 m_Position;
	aqua::CVector2 m_Velocity;
	float m_Width;
	float m_Height;
	UNIT_ID m_UnitID;
};