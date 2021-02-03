#pragma once
#include "Object.h"
class Player :
    public Object
{
public:
    Player();
    virtual ~Player();
private:
    Vector2 m_LinePoint;

    Vector2 m_Direction;
    Vector2 m_TargetPoint;
    POINT m_ptMouse;
    bool m_bMove;
   

    //มกวม
    bool m_bJump;
    float m_fOldY;
    float m_fTime;

public:
    virtual void Initialize(void)override;
    virtual void Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;


public:
    void CheckKey();
    void SetMoveFalse() { m_bMove = false; }
};

