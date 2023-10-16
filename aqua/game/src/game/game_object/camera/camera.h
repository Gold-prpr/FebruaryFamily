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

	void SetPlayerPos(aqua::CVector2 player_pos);

	//OffSet�̎擾
	const aqua::CVector2& GetScroll();

private:
	aqua::CVector2 m_Scroll;
	aqua::CVector2 m_PlayerPos;
	
	CPlayer* m_pPlayer;
	CStage* m_pStage;

};