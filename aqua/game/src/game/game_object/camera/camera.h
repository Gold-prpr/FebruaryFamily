#pragma once
#include "aqua.h"

class CPlayer;
class CStage;
class CUnitManager;
class CCamera
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CCamera(IGameObject* parent);

	//�f�X�g���N�^
	~CCamera() = default;

	//������
	void Initialize()override;

	//�X�V
	void Update()override;

	void CharaCameraPos(aqua::CSprite* cp,aqua::CVector2 pos);

	void Draw()override;

	void Finalize()override;

	//OffSet�̎擾
	const aqua::CVector2& GetScroll();

private:
	aqua::CVector2 m_Scroll;
	aqua::CSurface m_DivScreen;
	aqua::CSprite m_P1Stage;
	aqua::CSprite m_P2Stage;
	CPlayer* m_pPlayer;
	CStage* m_pStage;

	CUnitManager* m_pUnitManager;

};
