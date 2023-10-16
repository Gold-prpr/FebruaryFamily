#include "unit.h"
IUnit::IUnit(IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent,object_name,"Unit")
	,m_Width(0)
	,m_Height(0)
	,m_UnitID(UNIT_ID::MAX)
{
}
