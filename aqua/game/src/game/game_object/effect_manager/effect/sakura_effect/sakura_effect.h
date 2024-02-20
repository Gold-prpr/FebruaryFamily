#pragma once
#include "../effect.h"

class CSakuraEffect
	:public IEffect
{
public:
	//�R���X�g���N�^
	CSakuraEffect(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSakuraEffect() = default;

	//������
	void Initialize(const aqua::CVector2& position) override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//���
	void Finalize() override;

private:

	aqua::CSprite	m_Sakura;	//��

	int				m_angle;	//�h��
};