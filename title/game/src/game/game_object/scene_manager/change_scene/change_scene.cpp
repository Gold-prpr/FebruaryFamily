#include "change_scene.h"

IChangeScene::IChangeScene(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent,name,"ChangeScene")
{
}

/*
*  �X�v���C�g�̐���
*/
void IChangeScene::CreateSprite(aqua::CSurface& surface)
{
}

/*
*  ������
*/
void IChangeScene::Initialize()
{
}

/*
*  �X�V
*/
void IChangeScene::Update()
{
}

/*
*  �`��
*/
void IChangeScene::Draw()
{
}

/*
*  ���
*/
void IChangeScene::Finalize()
{
}

/*
*  �؂�ւ�����V�[��
*/
bool IChangeScene::In()
{
	return false;
}

/*
*  �V�[������؂�ւ�
*/
bool IChangeScene::Out()
{
	return false;
}
