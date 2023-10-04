#include "speeddown_item.h"

//�R���X�g���N�^
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
{
}

//������
void CSpeedDownItem::Initialize(aqua::CVector2 position)
{
	IItem::Initialize(position, "data\\speeddown.png");
}

//�X�V
void CSpeedDownItem::Update()
{
	IItem::Update();
}

//�`��
void CSpeedDownItem::Draw()
{
	IItem::Draw();
}

//���
void CSpeedDownItem::Finalize()
{
	IItem::Finalize();
}
