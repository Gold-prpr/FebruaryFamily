#pragma once
#include "aqua.h"

class CCommonData : 
	public aqua::IGameObject
{
public:

	struct CommonData
	{
		std::string stage_name; // ��������X�e�[�W��

		std::string object_file; // �g�p����f�މ摜

		aqua::controller::DEVICE_ID m_device_id;
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