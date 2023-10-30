#pragma once
#include "aqua.h"
#include "item/item_id.h"

class CItemManager
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CItemManager(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CItemManager(void) = default;

	//������
	void Initialize(void) override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void) override;

	//���
	void Finalize(void) override;

	//����
	void Create(ITEM_ID id, aqua::CVector2* position);

	int m_item_rand;				//�����_���ɃA�C�e�����o��
private:
	static const int m_item;		//�A�C�e����

	aqua::CVector2 pos;
};