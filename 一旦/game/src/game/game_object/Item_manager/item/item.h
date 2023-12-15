#pragma once
#include "aqua.h"

class IItem
	:public aqua::IGameObject
{
public:
	////�R���X�g���N�^
	IItem(aqua::IGameObject* parent, const std::string& name);

	//�f�X�g���N�^
	virtual ~IItem(void) = default;

	//������
	void Initialize(aqua::CVector2* position, std::string item_file);
	
	virtual void Initialize(aqua::CVector2* position) = 0;

	//�X�V
	virtual void Update()override;

	//�`��
	virtual void Draw()override;

	//���
	virtual void Finalize()override;

	//�A�C�e���̈ʒu
	const aqua::CVector2& GetPosition();


	aqua::CSprite				m_ItemSprite;	//�A�C�e���`��
private:
};