#pragma once
#include "aqua.h"
#include "unit/unit.h"


class CStage;
class CUnitManager :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CUnitManager(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CUnitManager()override = default;

	//������
	void Initialize()override;

	//�X�V
	void Update() override;

	//�`��
	void Draw()override;

	//���
	void Finalize()override;

	//Unit�̐����Ɛݒu
	IUnit* CreateUnit(UNIT_ID unitid, aqua::CVector2 pos);

private:

	CStage* m_pStage;
};