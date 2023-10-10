#include "gimmick.h"
#include "../../stage/stage.h"

CGimmick::CGimmick(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent, "StageGimmick")
{
}

void CGimmick::Initialize()
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");

	IGameObject::Initialize();
}

void CGimmick::DamageAction(void)
{

}