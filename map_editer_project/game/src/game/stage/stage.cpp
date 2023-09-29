#include "stage.h"
#include "tile_manager/tile_manager.h"
#include "back_ground_manager/back_ground_manager.h"
#include "save_manager/save_manager.h"

const float CStage::m_mouse_size = 0.25;

CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Stage")
{
}

void CStage::Initialize()
{
	aqua::CreateGameObject<CBackGroundManager>(this);

	aqua::CreateGameObject<CTileManager>(this)->Initialize(aqua::GetWindowSize());

	aqua::CreateGameObject<CSaveManager>(this);

	m_ForeGroudoSprite.Create("data\\ëÄçÏê‡ñæ.png");
	m_MouseCorsorSprite.Create("data\\mouse_corsor.png");
	m_MouseCorsorSprite.scale = aqua::CVector2(m_mouse_size, m_mouse_size);

	IGameObject::Initialize();
}

void CStage::Update()
{
	m_MouseCorsorSprite.position = aqua::mouse::GetCursorPos();
	IGameObject::Update();
}

void CStage::Draw()
{
	IGameObject::Draw();
	m_ForeGroudoSprite.Draw();
	m_MouseCorsorSprite.Draw();
}

void CStage::Finalize()
{
	IGameObject::Finalize();
	m_ForeGroudoSprite.Delete();
	m_MouseCorsorSprite.Delete();
}
