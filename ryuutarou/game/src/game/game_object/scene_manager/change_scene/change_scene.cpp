#include "change_scene.h"

IChangeScene::IChangeScene(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent,name,"ChangeScene")
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
