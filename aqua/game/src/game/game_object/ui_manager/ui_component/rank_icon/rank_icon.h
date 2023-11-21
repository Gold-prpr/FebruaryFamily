#include "aqua.h"
#include "../ui_component.h"

class CRankIcon
	: public IUiComponent
{
public:
	//�R���X�g���N�^
	CRankIcon(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CRankIcon(void) = default;

	//������
	void Initialize(const aqua::CVector2& position)override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	////���ʕϓ�
	//void ChangeRank(void);

private:

	aqua::CSprite		m_1PRankIconSprite;	//1P�A�C�e���A�C�R��
	aqua::CSprite		m_2PRankIconSprite;	//2P�A�C�e���A�C�R��
};