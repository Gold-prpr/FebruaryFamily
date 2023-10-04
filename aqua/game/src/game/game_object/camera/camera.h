#pragma once
#include "aqua.h"

class CPlayer;
class CStage;
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

	void Draw()override;

	void Finalize()override;

	//OffSet�̎擾
	const aqua::CVector2& GetScroll();

private:
	aqua::CVector2 m_Scroll;
	aqua::CSurface m_DivScreen;
	aqua::CSprite m_1PStage;
	aqua::CSprite m_2PStage;
	CPlayer* m_pPlayer;
	CStage* m_pStage;

};
