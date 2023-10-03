#include "change_scene.h"

IChangeScene::IChangeScene(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent,name,"ChangeScene")
{
}

/*
*  スプライトの生成
*/
void IChangeScene::CreateSprite(aqua::CSurface& surface)
{
}

/*
*  初期化
*/
void IChangeScene::Initialize()
{
}

/*
*  更新
*/
void IChangeScene::Update()
{
}

/*
*  描画
*/
void IChangeScene::Draw()
{
}

/*
*  解放
*/
void IChangeScene::Finalize()
{
}

/*
*  切り替えからシーン
*/
bool IChangeScene::In()
{
	return false;
}

/*
*  シーンから切り替え
*/
bool IChangeScene::Out()
{
	return false;
}
