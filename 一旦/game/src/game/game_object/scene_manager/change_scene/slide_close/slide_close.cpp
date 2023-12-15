#include "slide_close.h"

const float				CSlideClose::m_start_position_x = (float)aqua::GetWindowWidth();
const float				CSlideClose::m_max_block_time = 1.75f;
const int				CSlideClose::m_max_block = 6;

CSlideClose::CSlideClose(aqua::IGameObject* parent)
	:IChangeScene(parent, "SlideClose")
	, m_OutFlag(false)
{
}

void CSlideClose::Initialize()
{
	m_MosaicBox = AQUA_NEW aqua::CBoxPrimitive[m_max_block];

	float space_pos_y = (float)aqua::GetWindowHeight() / m_max_block;

	for (int i = 0; i < m_max_block; i++)
	{
		float first_pos_x = m_start_position_x * (i % 2 == 0 ? -1 : 1);

		m_MosaicBox[i].Setup(aqua::CVector2(first_pos_x, space_pos_y * i),(float)aqua::GetWindowWidth(), space_pos_y);

		m_MosaicBox[i].color = aqua::CColor::BLACK;

	}

	m_SlideTime.Setup(m_max_block_time);

	m_SlideTime.SetTimer(m_SlideTime.GetLimit());

}

void CSlideClose::Update()
{

	m_SlideTime.Update();
}

void CSlideClose::Draw()
{
	for (int i = 0; i < m_max_block; i++)
	{
		m_MosaicBox[i].Draw();
	}
}

void CSlideClose::Finalize()
{
	for (int i = 0; i < m_max_block; i++)
	{
		m_MosaicBox[i] = {};
	}

	AQUA_SAFE_DELETE_ARRAY(m_MosaicBox);

}
// ‰¡‚©‚çŠJ‚­Š´‚¶
bool CSlideClose::In()
{
	if (m_SlideTime.Finished() && m_OutFlag)
	{
		m_SlideTime.Reset();
		m_OutFlag = false;
	}
	else if (m_SlideTime.Finished())
	{
		m_SlideTime.SetTimer(m_SlideTime.GetLimit());
	}

	int mosaic_num = (int)aqua::easing::InSine
	(
		m_SlideTime.GetTime(),
		m_SlideTime.GetLimit(),
		0.0f,
		m_start_position_x
	);

	for (int i = 0; i < m_max_block; i++)
	{
		int add = (i % 2 == 0 ? -1 : 1);

		m_MosaicBox[i].position.x = (float)(mosaic_num * add);

	}

	return m_SlideTime.Finished();
}

// ‰¡‚©‚ç•Â‚¶‚éŠ´‚¶
bool CSlideClose::Out()
{
	if (m_SlideTime.Finished() && !m_OutFlag)
	{
		m_SlideTime.Reset();
		m_OutFlag = true;
	}
	else if (m_SlideTime.Finished())
	{
		m_SlideTime.SetTimer(m_SlideTime.GetLimit());
	}

	int mosaic_num = (int)aqua::easing::InSine
	(
		m_SlideTime.GetTime(),
		m_SlideTime.GetLimit(),
		m_start_position_x,
		0.0f
	);

	for (int i = 0; i < m_max_block; i++)
	{
		int add = (i % 2 == 0 ? -1 : 1);

		m_MosaicBox[i].position.x =(float)( mosaic_num * add);

	}

	return m_SlideTime.Finished();
}