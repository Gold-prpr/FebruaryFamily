#include "speedup_item.h"

//コンストラクタ
CSpeedUpItem::CSpeedUpItem(aqua::IGameObject* parent)
	:IItem(parent,"SpeedUpItem")
{
}

//初期化
void CSpeedUpItem::Initialize(aqua::CVector2 position)
{
	IItem::Initialize(position, "data\\speedup.png");

}

//更新
void CSpeedUpItem::Update()
{
	IItem::Update();
}

//描画
void CSpeedUpItem::Draw()
{
	IItem::Draw();
}

//解放
void CSpeedUpItem::Finalize()
{
	IItem::Finalize();
}
