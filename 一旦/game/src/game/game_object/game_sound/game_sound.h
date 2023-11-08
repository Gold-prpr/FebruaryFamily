#pragma once
#include "aqua.h"

class CGameSound :
	public aqua::IGameObject
{
public:

	CGameSound(aqua::IGameObject* parent);
	~CGameSound() = default;

	void Initialize()override;
	void Update()override;
	void Finalize()override;

	void PlayBGM();
	void PlaySE();

	void Stop();
};