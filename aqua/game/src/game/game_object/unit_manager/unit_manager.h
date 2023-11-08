#pragma once
#include "aqua.h"
#include "unit/unit.h"

class CPlayer;
class CStage;

class CUnitManager :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CUnitManager(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CUnitManager()override = default;

	//������
	virtual void Initialize()override;

	//�X�V
	virtual void Update() override;

	//�`��
	virtual void Draw()override;

	//���
	virtual void Finalize()override;

	CPlayer* GetPlayer(aqua::controller::DEVICE_ID player_device);

	//�̐����Ɛݒu
	IUnit* CreateUnit(UNIT_ID unitid, aqua::CVector2 pos,DEVICE_ID device);

private:

	CStage* m_pStage;
};