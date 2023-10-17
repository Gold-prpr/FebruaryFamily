#pragma once
#include "aqua.h"
#include "../item_manager/item_manager.h"
#include "../item_manager/item/speedup_item/speedup_item.h"
#include "../item_manager/item/item.h"

class CItemManager;

class IItem;

class CUi
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CUi(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CUi(void) = default;

	//������
	void Initialize(void) override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void) override;

	//���
	void Finalize(void) override;

private:
	//�����ɏ��ʃX�v���C�g�A�A�C�e���g�X�v���C�g�A�����̃|�W�V�����X�v���C�g�A�A�C�e�����ʃX�v���C�g������

	//1P
	aqua::CSprite		m_1PRankSprite;			//���ʃX�v���C�g
	aqua::CSprite		m_1PItemFrameSprite;	//�A�C�e���g
	aqua::CSprite		m_1PItemSprite;			//�A�C�e��
	aqua::CSprite		m_1PDistanceBar;		//�����鋗��
	aqua::CSprite		m_1PItemEffect;			//�A�C�e������

	//2P
	aqua::CSprite		m_2PRankSprite;			//���ʃX�v���C�g
	aqua::CSprite		m_2PItemFrameSprite;	//�A�C�e���g
	aqua::CSprite		m_2PItemSprite;			//�A�C�e��
	aqua::CSprite		m_2PDistanceBar;		//�����鋗��
	aqua::CSprite		m_2PItemEffect;			//�A�C�e������

	static const aqua::CVector2		m_1p_item_frame_position;		//1P�̃A�C�e���t���[���ʒu
	static const aqua::CVector2		m_2p_item_frame_position;		//2P�̃A�C�e���t���[���ʒu
	CItemManager* m_pItemManager;
	IItem* m_pItem;
};