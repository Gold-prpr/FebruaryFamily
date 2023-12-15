#pragma once
#include "aqua.h"
#include "item/item_id.h"

class CUnitManager;
class CPlayer;
class CItemIcon;

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

<<<<<<< HEAD
	//�A�C�e��ID
	void Create(ITEM_ID id);
=======
	//����
	void Create(ITEM_ID id, aqua::CVector2* position);
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b

	void RandPick(CPlayer* player);

	int m_1p_item_rand;				//1P�̃A�C�e���������_���ɏo��
	int m_2p_item_rand;				//2P�̃A�C�e���������_���ɏo��
private:
	static const int m_item;		//�A�C�e����
<<<<<<< HEAD
=======

	aqua::CVector2 pos;

	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CItemIcon* m_pIcon;
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
};