#include "block_mosaic.h"

const aqua::CPoint		CBloackMosaic::m_max_block_mosaic(16, 9);
const float				CBloackMosaic::m_max_block_time = 1.75f;
const unsigned char		CBloackMosaic::m_max_block_alpha = 0xff;
const unsigned char		CBloackMosaic::m_min_block_alpha = 0x00;

CBloackMosaic::CBloackMosaic(aqua::IGameObject* parent)
	:IChangeScene(parent, "BloackMosaic")
	, m_MosaicBox(nullptr)
{
}

/*
*  初期化
*/
void CBloackMosaic::Initialize()
{
	m_CountMosaic = (int)(m_max_block_mosaic.x * m_max_block_mosaic.y);

	m_MosaicBox = AQUA_NEW aqua::CBoxPrimitive[m_CountMosaic];

	m_BlockTime.Setup(m_max_block_time);

	m_MosaicSize.x = (float)aqua::GetWindowWidth() / (float)m_max_block_mosaic.x;
	m_MosaicSize.y = (float)aqua::GetWindowHeight() / (float)m_max_block_mosaic.y;
	
	for (int i = 0; i < m_max_block_mosaic.y; i++)
	{
		for (int j = 0; j < m_max_block_mosaic.x; j++)
		{
			int a = i * m_max_block_mosaic.x + j;

			m_MosaicBox[a].Setup(aqua::CVector2(j, i) * m_MosaicSize, m_MosaicSize.x, m_MosaicSize.y, aqua::CColor::BLACK);

			m_MosaicBox[a].visible = false;

		}
	}
}

/*
*  更新
*/
void CBloackMosaic::Update()
{
	if (m_BlockTime.Finished())
	{
		m_BlockTime.Reset();
	}

	m_BlockTime.Update();
}

/*
*  描画
*/
void CBloackMosaic::Draw()
{

	for (int i = 0; i < m_CountMosaic; i++)
	{
		m_MosaicBox[i].Draw();
	}
}

/*
*  解放
*/
void CBloackMosaic::Finalize()
{
	for (int i = 0; i < m_CountMosaic; i++)
	{
		m_MosaicBox[i] = {};
	}

	AQUA_SAFE_DELETE_ARRAY(m_MosaicBox);

	aqua::IGameObject::Finalize();
}

/*
*  切り替えからシーン
*/
bool CBloackMosaic::In()
{
	int mosaic_num = (int)aqua::easing::InCirc
	(
		m_BlockTime.GetTime(),
		m_BlockTime.GetLimit(),
		0.0f,
		(float)m_CountMosaic
	);

	int i = 0, j = 0;

	int count = 0;

	while (i < m_CountMosaic)
	{
		if (mosaic_num == j || mosaic_num == m_CountMosaic)
			break;

		int probability = aqua::Rand(1000, 1);

		if (probability % 2 == 0 && m_MosaicBox[i].visible)
		{
			j++;

			m_MosaicBox[i].visible = false;
		}

		if (i == m_CountMosaic - 1 && mosaic_num > j)
		{
			i = 0;

			count++;
		}

		if (count > 10)
		{

			for (int k = 0; k < m_CountMosaic; k++)
			{
				if (m_MosaicBox[k].visible)
					m_MosaicBox[i].visible = false;
			}

			break;
		}

		i++;
	}

	return m_BlockTime.Finished();
}

/*
*  シーンから切り替え
*/
bool CBloackMosaic::Out()
{
	int mosaic_num = (int)aqua::easing::InCirc
	(
		m_BlockTime.GetTime(),
		m_BlockTime.GetLimit(),
		0.0f,
		(float)m_CountMosaic
	);

	int i = 0, j = 0;

	int count = 0;

	while (i < m_CountMosaic)
	{
		if (mosaic_num == j || mosaic_num == m_CountMosaic)
			break;

		int probability = aqua::Rand(1000, 1);

		if (probability % 2 == 0 && !m_MosaicBox[i].visible)
		{
			j++;

			m_MosaicBox[i].visible = true;
		}

		if (i == m_CountMosaic -1 && mosaic_num > j)
		{
			i = 0;
			count++;
		}

		if (count > 10)
		{

			for (int k = 0; k < m_CountMosaic; k++)
			{
				if(!m_MosaicBox[k].visible)
					m_MosaicBox[i].visible = true;
			}

			break;
		}

		i++;
	}

	return m_BlockTime.Finished();
}
