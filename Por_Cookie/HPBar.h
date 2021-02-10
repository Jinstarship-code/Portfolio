#pragma once
#include "Object.h"
class HPBar :
    public Object
{
public:
    HPBar();
    virtual ~HPBar();

private:
    float m_fMaxHP;
    float m_fCurHP;
    


public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};
