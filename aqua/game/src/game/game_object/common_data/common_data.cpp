#include "common_data.h"

CCommonData::CCommonData(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "CommonData")
{
}

/*
*  初期化
*/
void CCommonData::Initialize(void)
{
}

/*
*  初期化
*/
void CCommonData::Finalize(void)
{
}

//設定
void CCommonData::SetDate(CommonData* date)
{
	if ((*date).stage_name != "")
		m_CommonData.stage_name = (*date).stage_name;

	m_CommonData.p_one_time = (*date).p_one_time;
	m_CommonData.p_two_time = (*date).p_two_time;
}

//生成するステージのファイル名を設定
void CCommonData::SetCreateStageName(std::string name)
{
	m_CommonData.stage_name = name;
}

//生成するステージのファイル名を取得
std::string CCommonData::GetCreateStageName()
{
	return m_CommonData.stage_name;
}

CCommonData::CommonData CCommonData::GetCommonDate()
{
	return m_CommonData;
}
