#pragma once
#include "aqua.h"

class CStageManager
	:public aqua::IGameObject
{
	//�R���X�g���N�^
	CStageManager(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CStageManager() = default;

	//������
	void Initialize(const aqua::CVector2& map_1p_pos, const aqua::CVector2& map_2p_pos);
private:

};