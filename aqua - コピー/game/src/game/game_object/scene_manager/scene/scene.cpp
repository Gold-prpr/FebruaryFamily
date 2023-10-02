#include "scene.h"

IScene::IScene(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent,name,"Scene")
{
}

void IScene::Initialize()
{
}

void IScene::Update()
{
}

void IScene::Draw()
{
}

void IScene::Finalize()
{
}
