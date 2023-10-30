#include "select_stage_box.h"
const int CSelectStageBox::m_max_font_size = 50;

CSelectStageBox::CSelectStageBox(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SelectStageBox")
{
}

void CSelectStageBox::Initialize(void)
{
	m_SelectBox.Create("data\\scene\\select\\box.png");

	m_StageName.Create(m_max_font_size);

	m_SelectBox.anchor.x = m_SelectBox.GetTextureWidth() / 2.0f;
	m_SelectBox.anchor.y = m_SelectBox.GetTextureHeight() / 2.0f;
}

void CSelectStageBox::Update(void) 
{

}

void CSelectStageBox::Draw(void)
{
	m_SelectBox.Draw();

	m_StageName.Draw();
}

void CSelectStageBox::Finalize(void)
{
	m_SelectBox.Delete();

	m_StageName.Delete();
}

void CSelectStageBox::SetUp(aqua::CVector2 position, std::string box_name, std::string stage_name)
{
	m_SelectBox.position = position;

	m_StageName.position = position;
	m_StageName.position.x += m_StageName.GetTextWidth() / 2.0f;
	m_StageName.position.y += m_StageName.GetFontHeight() / 2.0f;
	m_StageName.text = box_name;

	aqua::CCSVLoader cl;

	cl.Load(stage_name);

	m_StageBackGroundName = cl.GetString(0, 0);
	
	cl.Unload();

}

void CSelectStageBox::AddPosition(aqua::CVector2 add)
{
	m_SelectBox.position += add;

	m_StageName.position += add;
}

void CSelectStageBox::SetSize(aqua::CVector2 scale)
{
	m_SelectBox.scale = scale;

	m_StageName.position = m_SelectBox.position;
	m_StageName.position.x += m_StageName.GetTextWidth() / 2.0f;
	m_StageName.position.y += m_StageName.GetFontHeight() / 2.0f;
}

std::string CSelectStageBox::GetStageBackGrond()
{
	return m_StageBackGroundName;
}
