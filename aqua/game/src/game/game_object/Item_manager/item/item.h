#pragma once
#include "aqua.h"

class IItem
	:public aqua::IGameObject
{
public:
	////コンストラクタ
	IItem(aqua::IGameObject* parent, const std::string& name);

	//デストラクタ
	virtual ~IItem(void) = default;

	//初期化
	void Initialize(aqua::CVector2 position ,std::string item_file);

	virtual void Initialize(aqua::CVector2 position) = 0;

	//更新
	virtual void Update()override;

	//描画
	virtual void Draw()override;

	//解放
	virtual void Finalize()override;

	//アイテムの位置
	const aqua::CVector2& GetPosition();

<<<<<<< HEAD
=======

	aqua::CSprite				m_ItemSprite;	//アイテム描画
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
private:
	aqua::CSprite				m_ItemSprite;		//アイテム描画
};