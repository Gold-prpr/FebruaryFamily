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

	m_CommonData.p_one_time = (*date).p_one_time;
	m_CommonData.p_two_time = (*date).p_two_time;
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
