#include "aqua.h"
#include "../ui_component.h"

class CStage;
class CPlayer;

class CStagePosBar
	: public IUiComponent
{
public:
	//�R���X�g���N�^
	CStagePosBar(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CStagePosBar(void) = default;

	//������
	void Initialize(const aqua::CVector2& position)override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	void Move(CPlayer* player);

private:
	aqua::CSprite		m_StageBar;
	aqua::CSprite		m_Pos1p;
	aqua::CSprite		m_Pos2p;

	float m_PlayerRatio;

	CStage* m_pStage;
	CPlayer* m_pPlayer;
};