#include "game_main.h"
#include "../../../camera/camera.h"

CGameMain::CGameMain(aqua::IGameObject* parent)
	:IScene(parent,"GameMain",SCENE_ID::RESULT,CHANGE_SCENE_ID::FADE)
{
}

void CGameMain::Initialize()
{
	aqua::CreateGameObject<CCamera>(this);

	IScene::Initialize();

}

void CGameMain::Update()
{
	IScene::Update();
}

void CGameMain::Draw()
{
	IScene::Draw();
}

void CGameMain::Finalize()
{
	IScene::Finalize();
}
