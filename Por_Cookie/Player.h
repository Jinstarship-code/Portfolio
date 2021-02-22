#pragma once
#include "Object.h"

class Player : public Object
{
private:
	//** �÷��̾� ���� �̾�����.
	Vector2 m_LinePoint;
	RECT RecPlayer;

	//** ���콺 Ŭ�� �̵�
	Vector2 m_Direction;
	Vector2 m_TargetPoint;
	POINT m_ptMouse;
	bool m_bMove;

	//�����̵�
	bool m_bSlide;

	//** ���� 
	bool m_bJump;
	float m_fOldY;
	float m_fTime;
	float m_fDTime;
	bool m_bDJump;	//���� ����
	float m_fDOldY; //���� ���� ��ġ����.


public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;

public:
	void CheckKey();
	void SetMoveFalse() { m_bMove = false; }
	//int RecPlayerColl() { return RecPlayer.right; }
	

public:
	Player();
	virtual ~Player();
};

