#include "slide_close.h"

const float				CSlideClose::m_start_position_x = aqua::GetWindowWidth();
const float				CSlideClose::m_max_block_time = 1.75f;
const int				CSlideClose::m_max_block = 6;

CSlideClose::CSlideClose(aqua::IGameObject* parent)
	:IChangeScene(parent,"SlideClose")
{
}

void CSlideClose::Initialize()
{
	m_MosaicBox = AQUA_NEW aqua::CBoxPrimitive[m_max_block];

	float space_pos_y = aqua::GetWindowHeight() / m_max_block;

	
	for (int i = 0; i < m_max_block; i++)
	{
		float first_pos_x = m_start_position_x * (i % 2 == 0 ? -1 : 1);

		m_MosaicBox[i].Setup(aqua::CVector2(first_pos_x, space_pos_y * i), aqua::GetWindowWidth(), space_pos_y);

		m_MosaicBox[i].color = aqua::CColor::BLACK;
	}

}

void CSlideClose::Update()
{
}

void CSlideClose::Draw()
{
}

void CSlideClose::Finalize()
{
}
// ‰¡‚©‚çŠJ‚­Š´‚¶
bool CSlideClose::In()
{
	return false;
}

// ‰¡‚©‚ç•Â‚¶‚éŠ´‚¶
bool CSlideClose::Out()
{
	return false;
}
