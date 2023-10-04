#include "gimmick.h"

CGimmick::CGimmick(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "StageGimmick")
{
}

void CGimmick::Initialize()
{
	IGameObject::Initialize();
}

void CGimmick::Update()
{
	IGameObject::Initialize();
}

void CGimmick::Draw()
{
	IGameObject::Initialize();
}

void CGimmick::Finalize()
{
	IGameObject::Initialize();
}

void CGimmick::Create(STAGE_GIMMICK id)
{
	/*IGameObject* gimmick = nullptr;

	switch (id)
	{
	case STAGE_GIMMICK::NEEDLE: gimmick = aqua::CreateGameObject<CNeedle>(this); break;
	}

	gimmick->Initialize();*/
}
