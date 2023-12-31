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

	bool				m_ItemFlag;		//アイテム効果中
protected:

	aqua::CTimer		m_EffectTimer;
};