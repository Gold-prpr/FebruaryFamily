#include "block_mosaic.h"

const aqua::CPoint		CBloackMosaic::m_max_block_mosaic(16,9);
const float				CBloackMosaic::m_max_block_time = 0.5f;
const unsigned char		CBloackMosaic::m_max_block_alpha = 0xff;
const unsigned char		CBloackMosaic::m_min_block_alpha = 0x00;

CBloackMosaic::CBloackMosaic(aqua::IGameObject* parent)
	:IChangeScene(parent, "BloackMosaic")
	, m_BlockInFlag(false)
{
}

/*
*  初期化
*/
void CBloackMosaic::Initialize()
{
	m_BlockTime.Setup(m_max_block_time);
}

void CBloackMosaic::CreateSprite(aqua::CSurface& surface)
{
	m_MosaicSize.x = (float)aqua::GetWindowWidth()  / (float)m_max_block_mosaic.x;
	m_MosaicSize.y = (float)aqua::GetWindowHeight() / (float)m_max_block_mosaic.y;

	for (int i = 0; i < m_max_block_mosaic.y; i++)
	{
		for (int j = 0; j < m_max_block_mosaic.x; j++)
		{
			aqua::CSprite s;

			s.Create(surface);

			s.rect.top = i * m_MosaicSize.y;
			s.rect.bottom = (i + 1) * m_MosaicSize.y;

			s.rect.left  = j * m_MosaicSize.x;
			s.rect.right = (j + 1) * m_MosaicSize.x;

			s.position = aqua::CVector2(j, i) * m_MosaicSize;

			m_BlockSprite.push_back(s);

			s.Delete();
		}
	}
}

/*
*  更新
*/
void CBloackMosaic::Update()
{
	m_BlockTime.Update();
}

/*
*  描画
*/
void CBloackMosaic::Draw()
{

	for (auto sprite_it : m_BlockSprite)
	{
		sprite_it.Draw();
	}

}

/*
*  解放
*/
void CBloackMosaic::Finalize()
{
	for (auto sprite_it : m_BlockSprite)
	{
		sprite_it.Draw();
	}
}

/*
*  切り替えからシーン
*/
bool CBloackMosaic::In()
{
	if (m_BlockTime.Finished() && !m_BlockInFlag)
	{
		m_BlockTime.Reset();
		m_BlockInFlag = true;
	}

	float easing_speed = aqua::easing::InBack
	(
		m_BlockTime.GetTime(),
		m_BlockTime.GetLimit(),
		0,
		10.0f
	);

	unsigned char alpha  =
		(unsigned char)aqua::easing::InCubic
		(
			m_BlockTime.GetTime(),
			m_BlockTime.GetLimit(),
			m_max_block_alpha,
			m_min_block_alpha
		);

	for (auto sprite_it : m_BlockSprite)
	{
		sprite_it.position.x += easing_speed;

		sprite_it.color.alpha = alpha;
	}

	return m_BlockTime.Finished();
}

/*
*  シーンから切り替え
*/
bool CBloackMosaic::Out()
{
	return true;
}
