#pragma once
#include "../scene.h"

class CResult :
	public IScene
{
public:

	CResult(aqua::IGameObject* parent);
	~CResult() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:



};
