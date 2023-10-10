#pragma once
#include "../stage_object/gimmick_id.h"

class CStage;

class CGimmick :
	public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CGimmick(aqua::IGameObject* parent, const std::string& object_name);

	//�f�X�g���N�^
	~CGimmick()override = default;

	//������
	void Initialize()override;

	void DamageAction(void);

	CStage* m_pStage;
private:
};