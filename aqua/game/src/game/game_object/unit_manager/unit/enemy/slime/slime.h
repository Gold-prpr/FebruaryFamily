#pragma once
#include "../../unit.h"

class CStage;
class CSlime :public IUnit
{
public:
	CSlime(aqua::IGameObject* parent);
	~CSlime() = default;

	void Initialize(const aqua::CVector2& position)override;

	void Update()override;

	void Draw()override;

	void Finalize()override;

	//•Ç‚Ì“–‚½‚è”»’è
	void CheckHitBlok(void);

private:
	aqua::CAnimationSprite m_SlimeAnimaSprite;
	aqua::CVector2 m_Velocty;
	CStage* m_pStage;
	static const float m_width;
	static const float m_height;
	bool			   m_ReflectionFlag;
	bool			   m_LandingFlag;

};