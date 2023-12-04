#pragma once
#include "../scene.h"


class CSelectStageBox;
class CCommonData;

class CSelect :
	public IScene
{
public:

	CSelect(aqua::IGameObject* parent);
	~CSelect() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:
	static const float m_max_scale;
	static const float m_min_scale;
	static const float m_distance;
	static const float m_max_time;
	static const int   m_max_low_select;

	aqua::CSprite m_BackGround;
	aqua::CTimer  m_SelectSpeed;

	std::vector< CSelectStageBox*>	m_SelectStageBoxList;

	CCommonData*					m_CommonDataClass;

	int m_MaxStage;

	int m_SelectNowStageNam;
	int m_SelectPrivStageNam;

	int m_CountLowSpeed;

};
