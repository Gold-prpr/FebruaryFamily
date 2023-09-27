#include "stage.h"
#include "tile_manager/tile_manager.h"
#include "back_ground_manager/back_ground_manager.h"

CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Stage")
{
}

void CStage::Initialize()
{
	aqua::CreateGameObject<CBackGroundManager>(this);
	aqua::CreateGameObject<CTileManager>(this)->Initialize(aqua::GetWindowSize());

	m_ForeGroudoSprite.Create("data\\ëÄçÏê‡ñæ.png");

	IGameObject::Initialize();
}

void CStage::Update()
{
	
	IGameObject::Update();
}

void CStage::Draw()
{
	IGameObject::Draw();
	m_ForeGroudoSprite.Draw();
}

void CStage::Finalize()
{
	IGameObject::Finalize();
	m_ForeGroudoSprite.Delete();
}
