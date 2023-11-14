#include "slime.h"
#include "../../../../stage/stage.h"
#include "../../player/player.h"

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
	m_Position = position;

	w = (int)m_Width;
	h = (int)m_Height;
	size = 60;
}

void CSlime::Update()
{
	x = (int)(m_Position.x);
	y = (int)(m_Position.y);
	nx = (int)(m_Position.x + m_Velocity.x);
	ny = (int)(m_Position.y + m_Velocity.y);

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
	if (m_pStage->CheckHitObject(this))
	{
		// ���Ɉړ����Ă���
		if (m_Velocity.x < 0)
			nx = (nx / size + 1) * size;

		// �E�Ɉړ����Ă���
		if (m_Velocity.x > 0)
			nx = ((nx + w) / size) * size - w;

		// �u���b�N�ɂ������Ă���̂ő��x������
		m_Velocity.x = 0;

		if (m_ReflectionFlag && m_Velocity.x < 0.0f && m_pStage->CheckHitObject(this))
		{
			m_ReflectionFlag = false;
		}

		if (!m_ReflectionFlag && m_Velocity.x > 0.0f && m_pStage->CheckHitObject(this))
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
		if (!m_pStage->CheckHitObject(this))
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
		if (m_pStage->CheckHitFloor(this))
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

void CSlime::Damage()
{
		DeleteObject();
}
