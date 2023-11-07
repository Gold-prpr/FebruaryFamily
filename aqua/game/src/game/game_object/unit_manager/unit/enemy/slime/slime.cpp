#include "slime.h"
#include "../../../../stage/stage.h"

const float CSlime::m_width = 60.0f;
const float CSlime::m_height = 60.0f;

CSlime::CSlime(aqua::IGameObject* parent)
	:IUnit(parent, "Slime")
	, m_ReflectionFlag(true)
{
}

void CSlime::Initialize(const aqua::CVector2& position)
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_SlimeAnimaSprite.Create("data/slime.ass", "left");
	m_UnitID = UNIT_ID::SLIME;
	m_Width = m_width;
	m_Height = m_height;
}

void CSlime::Update()
{
	CheckHitBlok();
}

void CSlime::Draw()
{
	m_SlimeAnimaSprite.Draw();
}

void CSlime::Finalize()
{
	m_SlimeAnimaSprite.Delete();
}

void CSlime::CheckHitBlok(void)
{
	int x = (int)(m_Position.x);
	int y = (int)(m_Position.y);
	int nx = (int)(m_Position.x + m_Velocity.x);
	int ny = (int)(m_Position.y + m_Velocity.y);
	int w = (int)m_Width;
	int h = (int)m_Height;
	int size = 60;

	if (m_pStage->CheckHit(nx, y)
		|| m_pStage->CheckHit(nx + w - 1, y)
		|| m_pStage->CheckHit(nx, y + h / 2)
		|| m_pStage->CheckHit(nx + w - 1, y + h / 2)
		|| m_pStage->CheckHit(nx, y + h - 1)
		|| m_pStage->CheckHit(nx + w - 1, y + h - 1))
	{
		// ���Ɉړ����Ă���
		if (m_Velocity.x < 0)
			nx = (nx / size + 1) * size;

		// �E�Ɉړ����Ă���
		if (m_Velocity.x > 0)
			nx = ((nx + w) / size) * size - w;

		// �u���b�N�ɂ������Ă���̂ő��x������
		m_Velocity.x = 0;

		if (m_ReflectionFlag && m_Velocity.x < 0.0f && m_pStage->CheckHit(nx, y + h / 2))
		{
			m_ReflectionFlag = false;
		}

		if (!m_ReflectionFlag && m_Velocity.x > 0.0f && m_pStage->CheckHit(nx + w - 1, y + h / 2))
		{
			m_ReflectionFlag = true;
		}

		if (m_ReflectionFlag)
		{
			m_SlimeAnimaSprite.Change("left");
		}
		if (m_ReflectionFlag)
		{
			m_SlimeAnimaSprite.Change("right");
		}
	}


	if (m_LandingFlag == true)
	{
		// �����𒲂ׂău���b�N���Ȃ���Η���
		if (!m_pStage->CheckHit(x, y + h) && !m_pStage->CheckHit(x + w, y + h))
		{
			// �����Ƀu���b�N���Ȃ��̂Œ��n���Ă��Ȃ�
			m_LandingFlag = false;

			// �������n�܂�̂ŃX�s�[�h�������Ă���
			m_Velocity.y = 0;
		}
	}
	// �󒆂ɂ���
	else if (m_LandingFlag == false)
	{
		// �d�͂ŗ���������
		m_Velocity.y += m_pStage->GetGravity();

		// �㉺�̃`�F�b�N
		if (m_pStage->CheckHit(x, ny)
			|| m_pStage->CheckHit(x + w - 1, ny)
			|| m_pStage->CheckHit(x, ny + h - 1)
			|| m_pStage->CheckHit(x + w - 1, ny + h - 1))
		{
			// ��ɓ����Ă���
			if (m_Velocity.y < 0)
				ny = (ny / size + 1) * size;

			// ���ɓ����Ă���
			if (m_Velocity.y > 0)
			{
				ny = ((ny + h) / size) * size - h;

				// ���n����
				m_LandingFlag = true;
			}

			// �u���b�N�ɂ������Ă���̂ő��x������
			m_Velocity.y = 0;
		}
	}

	// �ʒu�̌���
	m_Position.x = (float)nx;
	m_Position.y = (float)ny;
}
