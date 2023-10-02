#pragma once
#include "aqua.h"

class IScene :public aqua::IGameObject
{
public:
	IScene(aqua::IGameObject* parent,std::string name);
	~IScene() = default;

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Finalize()override;

private:



};