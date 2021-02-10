#pragma once
#include "Object.h"

class Player : public Object
{
private:
	//** 플레이어 포신 이었던것.
	Vector2 m_LinePoint;

	//** 마우스 클릭 이동
	Vector2 m_Direction;
	Vector2 m_TargetPoint;
	POINT m_ptMouse;
	bool m_bMove;

	//** 점프 
	bool m_bJump;
	float m_fOldY;
	float m_fTime;
	float m_fDTime;
	bool m_bDJump;	//더블 점프
	float m_fDOldY; //더블 점프 위치정보.

public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;

public:
	void CheckKey();
	void SetMoveFalse() { m_bMove = false; }
public:
	Player();
	virtual ~Player();
};

