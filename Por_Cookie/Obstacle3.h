#pragma once
#include "Object.h"

class Obstacle3 :
    public Object
{
public:
    Obstacle3();
    virtual ~Obstacle3();

private:
    RECT rc;

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};