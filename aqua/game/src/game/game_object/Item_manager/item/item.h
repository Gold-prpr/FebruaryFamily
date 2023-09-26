#pragma once
#include "aqua.h"

class IItem
	:public aqua::IGameObject
{
public:

	//コンストラクタ
	IItem(aqua::IGameObject* parent, const std::string& name);

	//デストラクタ
	
};