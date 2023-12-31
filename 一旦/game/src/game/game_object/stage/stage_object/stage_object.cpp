#include "stage_object.h"

const float CStageObject::m_thickness_size = 10.0f;

CStageObject::CStageObject(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "StageObject")
	, stage_object_id(StageObjectID::AIR)
	, m_PrevStageObjectID(StageObjectID::AIR)
	, not_elase_flag(false)
{
}

/*
*  生成
*/
void CStageObject::Create(aqua::CVector2 position, aqua::CVector2 size)
{
	m_Position = position;

	m_StageObjectSprite.Create("data\\scene\\game\\tile2.png");

	// RECT
	m_StageObjectSprite.rect.left = 0;
	m_StageObjectSprite.rect.right = (int)size.x;

	m_StageObjectSize = size;
}
/*
*  更新
*/
void CStageObject::Update()
{
	if (m_PrevStageObjectID != stage_object_id)
	{
		m_PrevStageObjectID = stage_object_id;

		if (stage_object_id != StageObjectID::AIR)
		{
			m_StageObjectSprite.rect.left = ((int)stage_object_id - 1) * (int)m_StageObjectSize.x;
			m_StageObjectSprite.rect.right = (int)stage_object_id * (int)m_StageObjectSize.x;
		}
	}

	m_StageObjectSprite.position = m_Position + m_AddPosition;

}

/*
*  描画
*/
void CStageObject::Draw()
{
	if (stage_object_id != StageObjectID::AIR)
		m_StageObjectSprite.Draw();
}

/*
*  解放
*/
void CStageObject::Finalize()
{
	m_StageObjectSprite.Delete();

	IGameObject::Finalize();
}

/*
*  座標の設定
*/
void CStageObject::SetPosition(aqua::CVector2 position)
{
	m_Position = position;
}

void CStageObject::SetAddPosition(aqua::CVector2 add_position)
{
	m_AddPosition = add_position;
}
