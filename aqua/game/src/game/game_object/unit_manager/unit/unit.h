#pragma once
#include "aqua.h"

using namespace aqua::controller;

enum class UNIT_ID
{
	PLAYER,
	SLIME,
	MAX
};

class IUnit :public aqua::IGameObject
{
public:
	IUnit(IGameObject* parent, const std::string& object_name);

	~IUnit(void) = default;

	virtual void Initialize(const aqua::CVector2& position) = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Finalize() = 0;

	const aqua::CVector2& GetPosition() { return m_Position; }

	const aqua::CVector2& GetVelocity() { return m_Velocity; }

	float GetWidth() { return m_Width; }

	float GetHeight() { return m_Height; }

	UNIT_ID GetUnitID() { return m_UnitID; }

	virtual void SetDeviceID(DEVICE_ID device_id) = 0 { }

	aqua::CVector2 m_Position;

	int x;
	int y;
	int nx;
	int ny;
	int w;
	int h;
	int size;

protected:
	aqua::CVector2 m_Velocity;
	float m_Width;
	float m_Height;
	UNIT_ID m_UnitID;

};