#include "stage_object.h"

const int CStageObject::m_object_size = 60;
const float CStageObject::m_thickness_size = 10.0f;

CStageObject::CStageObject(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "StageObject")
	, m_StageObjectID(StageObjectID::AIR)
	, m_PrevStageObjectID(StageObjectID::AIR)
	, not_elase_flag(false)
{
}

/*
*  ê∂ê¨
*/
void CStageObject::Create(StageObjectID id, aqua::CVector2 position)
{
	m_Position = position;

	m_StageObjectSprite.Create("data\\scene\\game\\tile3.png");

	m_StageObjectID = id;

	// RECT
	m_StageObjectSprite.rect.left = 0;
	m_StageObjectSprite.rect.right = m_object_size;
}
/*
*  çXêV
*/
void CStageObject::Update()
{
	if (m_PrevStageObjectID != m_StageObjectID)
	{
		m_PrevStageObjectID = m_StageObjectID;

		if (m_StageObjectID != StageObjectID::AIR)
		{
			m_StageObjectSprite.rect.left = ((int)m_StageObjectID - 1) * m_object_size;
			m_StageObjectSprite.rect.right = m_StageObjectSprite.rect.left + m_object_size;
		}
	}

	m_StageObjectSprite.position = m_Position + m_AddPosition;

}

/*
*  ï`âÊ
*/
void CStageObject::Draw()
{
	if (m_StageObjectID != StageObjectID::AIR)
		m_StageObjectSprite.Draw();
}

/*
*  âï˙
*/
void CStageObject::Finalize()
{
	m_StageObjectSprite.Delete();

	IGameObject::Finalize();
}

/*
*  ç¿ïWÇÃê›íË
*/
void CStageObject::SetPosition(aqua::CVector2 position)
{
	m_Position = position;
}

void CStageObject::SetAddPosition(aqua::CVector2 add_position)
{
	m_AddPosition = add_position;
}

bool CStageObject::CheckObject(int x, int y, StageObjectID id)
{
	int obj_x = (int)m_StageObjectSprite.position.x;
	int obj_y = (int)m_StageObjectSprite.position.y;

	return ((obj_x <= x && obj_x + m_object_size > x) &&
		    (obj_y <= y && obj_y + m_object_size > y) && 
		     m_StageObjectID == id);
}

void CStageObject::ChangeAir(int x, int y, StageObjectID id)
{
	int obj_x = (int)m_StageObjectSprite.position.x;
	int obj_y = (int)m_StageObjectSprite.position.y;

	if ((obj_x <= x && obj_x + m_object_size > x) &&
		(obj_y <= y && obj_y + m_object_size > y) &&
		m_StageObjectID == id)
		m_StageObjectID = StageObjectID::AIR;
}

aqua::CVector2 CStageObject::GoalPos(void)
{
	if(m_StageObjectID == StageObjectID::GOAL_FLAG)
		return m_StageObjectSprite.position;
}
