#include "common_data.h"

CCommonData::CCommonData(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "CommonData")
{
}

/*
*  ������
*/
void CCommonData::Initialize(void)
{
	m_CommonData.stage_name = "";

	m_CommonData.m_device_id;
}

/*
*  ������
*/
void CCommonData::Finalize(void)
{
}

//�ݒ�
void CCommonData::SetDate(CommonData* date)
{
	if ((*date).stage_name != "")
		m_CommonData.stage_name = (*date).stage_name;

	m_CommonData.m_device_id = (*date).m_device_id;
}

//��������X�e�[�W�̃t�@�C������ݒ�
void CCommonData::SetCreateStageName(std::string name)
{
	m_CommonData.stage_name = name;
}

//��������X�e�[�W�̃t�@�C�������擾
std::string CCommonData::GetCreateStageName()
{
	return m_CommonData.stage_name;
}

CCommonData::CommonData CCommonData::GetCommonDate()
{
	return m_CommonData;
}
