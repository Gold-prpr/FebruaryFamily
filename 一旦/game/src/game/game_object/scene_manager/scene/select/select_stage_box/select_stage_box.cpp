#include "select_stage_box.h"
const int CSelectStageBox::m_max_font_size = 50;

CSelectStageBox::CSelectStageBox(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SelectStageBox")
{
}

void CSelectStageBox::Initialize(void)
{
	m_SelectBox.Create("data\\scene\\select\\box.png");

	m_StageNameLabel.Create(m_max_font_size);

	m_SelectBox.anchor.x = m_SelectBox.GetTextureWidth() / 2.0f;
	m_SelectBox.anchor.y = m_SelectBox.GetTextureHeight() / 2.0f;
}

void CSelectStageBox::Update(void)
{

}

void CSelectStageBox::Draw(void)
{
	m_SelectBox.Draw();

	m_StageNameLabel.Draw();
}

void CSelectStageBox::Finalize(void)
{
	m_SelectBox.Delete();

	m_StageNameLabel.Delete();
}

void CSelectStageBox::SetUp(aqua::CVector2 position, std::string box_name, std::string stage_name)
{
	m_SelectBox.position = position;

	m_StageNameLabel.position = m_SelectBox.position;
	m_StageNameLabel.text = box_name;
	m_StageNameLabel.position.x += (m_SelectBox.GetTextureWidth() - m_StageNameLabel.GetTextWidth()) / 2.0f;
	m_StageNameLabel.position.y += (m_SelectBox.GetTextureHeight() - m_StageNameLabel.GetFontHeight()) / 2.0f;
	m_LabelText = m_StageNameLabel.text;

	m_StageName = stage_name;

	aqua::CCSVLoader cl;

	cl.Load(stage_name);

	m_StageBackGroundName = cl.GetString(0, 0);

	cl.Unload();

}

void CSelectStageBox::SetPosition(aqua::CVector2 set)
{
	m_SelectBox.position = set;
	m_StageNameLabel.position = m_SelectBox.position;
	m_StageNameLabel.position.x += (m_SelectBox.GetTextureWidth() - m_StageNameLabel.GetTextWidth()) / 2.0f;
	m_StageNameLabel.position.y += (m_SelectBox.GetTextureHeight() - m_StageNameLabel.GetFontHeight()) / 2.0f;

}

void CSelectStageBox::SetSize(aqua::CVector2 scale)
{
	m_SelectBox.scale = scale;

	m_StageNameLabel.Delete();

	m_StageNameLabel.Create((int)(m_max_font_size * scale.x));
	m_StageNameLabel.text = m_LabelText;
	m_StageNameLabel.position = m_SelectBox.position;
	m_StageNameLabel.position.x += (m_SelectBox.GetTextureWidth() - m_StageNameLabel.GetTextWidth() ) / 2.0f ;
	m_StageNameLabel.position.y += (m_SelectBox.GetTextureHeight()- m_StageNameLabel.GetFontHeight()) / 2.0f ;

}

std::string CSelectStageBox::GetStageBackGrond()
{
	return m_StageBackGroundName;
}

std::string CSelectStageBox::GetStageName()
{
	return m_StageName;
}

aqua::CVector2 CSelectStageBox::GetObjectSize()
{
	aqua::CVector2 s;

	s.x = (float)m_SelectBox.GetTextureWidth() * m_SelectBox.scale.x;
	s.y = (float)m_SelectBox.GetTextureHeight() * m_SelectBox.scale.y;

	return s;
}
