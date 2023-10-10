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
	IGameObject::Update();
}

void CGimmick::Draw()
{
	IGameObject::Draw();
}

void CGimmick::Finalize()
{
	IGameObject::Finalize();
}