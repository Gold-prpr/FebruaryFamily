#include "speedup_item.h"

//�R���X�g���N�^
CSpeedUpItem::CSpeedUpItem(aqua::IGameObject* parent)
	:IItem(parent,"SpeedUpItem")
{
}

//������
void CSpeedUpItem::Initialize(aqua::CVector2 position)
{
	IItem::Initialize(position, "data\\speedup.png");

}

//�X�V
void CSpeedUpItem::Update()
{
	IItem::Update();
}

//�`��
void CSpeedUpItem::Draw()
{
	IItem::Draw();
}

//���
void CSpeedUpItem::Finalize()
{
	IItem::Finalize();
}
