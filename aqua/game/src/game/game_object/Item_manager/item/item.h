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
	void Initialize(std::string item_file);


	//更新
	virtual void Update()override;

	//描画
	virtual void Draw()override;

	//解放
	virtual void Finalize()override;


	aqua::CSprite				m_ItemSprite;	//アイテム描画

protected:

	bool				m_itemflag;			//アイテム使ったか

	aqua::CTimer		m_EffectTimer;
};