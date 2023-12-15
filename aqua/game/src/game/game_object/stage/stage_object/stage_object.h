#pragma once
#include "aqua.h"
#include "stage_object_id.h"

class CStageObject :
	public aqua::IGameObject
{
public:
	CStageObject(aqua::IGameObject* parent);
	~CStageObject() = default;

	void Create(aqua::CVector2 position, aqua::CVector2 size);
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

	StageObjectID	stage_object_id;

	bool			not_elase_flag;

private:

	static const float				m_thickness_size;

	aqua::CSprite					m_StageObjectSprite;
	aqua::CVector2					m_StageObjectSize;

	StageObjectID	m_PrevStageObjectID;

	aqua::CVector2  m_Position;
	aqua::CVector2  m_AddPosition;
};

