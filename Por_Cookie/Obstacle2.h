#pragma once
#include "Object.h"

class Obstacle2 :
    public Object
{
public:
    Obstacle2();
    virtual ~Obstacle2();

private:
    RECT rc;

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};


