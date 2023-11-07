#pragma once
#include "aqua.h"

class CCommonData : 
	public aqua::IGameObject
{
public:

	struct CommonData
	{
		std::string stage_name; // ��������X�e�[�W��

		float p_one_time;		// �v���C���[1�̃N���A����
		float p_two_time;		// �v���C���[2�̃N���A����
	};

public:

	//�R���X�g���N�^
	CCommonData(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CCommonData(void) = default;

	//������
	void Initialize(void) override;

	//���
	void Finalize(void) override;

	//�ݒ�
	void SetDate(CommonData* date );

	//��������X�e�[�W�̃t�@�C������ݒ�
	void SetCreateStageName(std::string name);

	//��������X�e�[�W�̃t�@�C�������擾
	std::string GetCreateStageName();

	// ���L�f�[�^�̎擾
	CommonData GetCommonDate();

private:

	CommonData m_CommonData;

};