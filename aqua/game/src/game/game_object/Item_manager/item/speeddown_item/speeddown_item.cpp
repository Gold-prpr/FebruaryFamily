#include "speeddown_item.h"

//コンストラクタ
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
{
}

//初期化
void CSpeedDownItem::Initialize(aqua::CVector2 position)
{
	IItem::Initialize(position, "data\\speeddown.png");
}

//更新
void CSpeedDownItem::Update()
{
	IItem::Update();
}

//描画
void CSpeedDownItem::Draw()
{
	IItem::Draw();
}

//解放
void CSpeedDownItem::Finalize()
{
	IItem::Finalize();
}
