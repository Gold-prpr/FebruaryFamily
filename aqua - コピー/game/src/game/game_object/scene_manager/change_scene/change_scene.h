#pragma once
#include "aqua.h"

class IChangeScene :public aqua::IGameObject
{
public:
	IChangeScene(aqua::IGameObject* parent, std::string name);
	~IChangeScene() = default;

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Finalize()override;

private:



};
