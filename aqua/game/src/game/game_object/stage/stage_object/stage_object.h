#pragma once
#include "aqua.h"
#include "stage_object_id.h"

class CStageObject :
	public aqua::IGameObject
{
public:
	CStageObject(aqua::IGameObject* parent);
	~CStageObject() = default;

	void Create(StageObjectID id, aqua::CVector2 position);
	void Update() override;
	void Draw()override;
	void Finalize()override;

	/*
	*	ç¿ïWéÊìæ
	*/
	aqua::CVector2	GetPosition() { return m_StageObjectSprite.position; };

	/*
	*
	*	â¡éZï™ÇÃç¿ïWéÊìæ
	*/
	aqua::CVector2	GetAddPosition() { return m_AddPosition; };

	void			SetPosition(aqua::CVector2 position);
	void			SetAddPosition(aqua::CVector2 add_position);

	static int GetObjectSize(void) { return m_object_size; }

	bool CheckObject(int x, int y, StageObjectID id);

	StageObjectID	m_StageObjectID;

	bool			not_elase_flag;

private:

	static const int				m_object_size;
	static const float				m_thickness_size;

	aqua::CSprite					m_StageObjectSprite;

	StageObjectID	m_PrevStageObjectID;

	aqua::CVector2  m_Position;
	aqua::CVector2  m_AddPosition;
};

